%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int number;
typedef struct node {
    char *label;
    int addr;
    struct node* next;
} Node;

int pass = 1;
int line = 0;
FILE *fp, *yyin;
struct node *head = NULL;
struct node *tail = NULL;

int computeAddr(int line);
void process_instruction(const char *yytext, int i, int label_start_offset, FILE *fp);
void yyerror(char const *);
%}

letter  [a-zA-Z]
digit   [0-9]

%%

{letter}({letter}|{digit})+(":")([\n]) {
    if (pass == 1) {
        line++;
        struct node *t = (struct node *)malloc(sizeof(struct node));
        t->label = (char *)malloc((yyleng) * sizeof(char));
        strncpy(t->label, yytext, yyleng - 2);
        t->label[yyleng - 2] = '\0';
        t->addr = computeAddr(line-1);
        line--;
        if (!head) {
            head = t;
            tail = t;
        } else {
            tail->next = t;
            tail = t;
        }
    }
}

("CALL"|"JMP")[ ]{letter}({letter}|{digit})+\n {
    if (pass == 1) {
        line++;
    } else {
        int i = 0;
        while (yytext[i] != ' ') {
            i++;
        }
        process_instruction(yytext, i, 1, fp); // label_start_offset = 1
    }
}

("JZ"|"JNZ")[ ]("R")({digit}+)(",")[ ]{letter}({letter}|{digit})+\n {
    if (pass == 1) {
        line++;
    } else {
        int i = 0;
        while (yytext[i] != ',') {
            i++;
        }
        process_instruction(yytext, i, 2, fp); // label_start_offset = 2
    }
}


("CALL"|"JMP")([ ])({digit}+)([\n]) {
    if(pass == 1){
        line++;
    }
    else{
        fprintf(fp, "%s", yytext);
    }
}

("JZ"|"JNZ")([ ])("R")({digit}+)(",")({digit}+)([\n]) {
    if(pass == 1){
        line++;
    }
    else{
        fprintf(fp, "%s", yytext);
    }
}

(.)+(\n) {
    if(pass == 1){
        line++;
    }
    else{
        fprintf(fp, "%s", yytext);
    }
}

%%

int computeAddr(int line) {
    return 2056 + 2 * (line - 8);
}

void process_instruction(const char *yytext, int i, int label_start_offset, FILE *fp) {
    char command[100] = "";
    strncpy(command, yytext, i + 1); // Extract the command part (e.g., "CALL ")

    char temp_label[10] = "";
    int j = i + label_start_offset;
    while (yytext[j] != '\n') {
        j++;
    }
    strncpy(temp_label, yytext + i + label_start_offset, j - i - label_start_offset);
    temp_label[j - i - label_start_offset] = '\0'; // Null-terminate the label string

    printf("Instruction : %s\n", yytext);
    printf("Label : %s\n", temp_label);
    printf("Command : %s\n", command);

    struct node *t = head;
    int addr = -1;
    while (t != NULL) {
        if (strcmp(t->label, temp_label) == 0) {
            addr = t->addr; 
            break;
        }
        t = t->next;
    }

    if (addr == -1) {
        printf("Looking for label %s\n", temp_label);
        printf("STATUS: NOT FOUND\n");
        exit(1);
    }

    char address[10] = "";
    snprintf(address, sizeof(address), "%d", addr);
    strcat(command, address); 

    fprintf(fp, "%s\n", command);
}


void printLinkedList() {
    struct node *t = head;
    while(t) {
        printf("Label: %s, Addr: %d\n", t->label, t->addr);
        t = t->next;
    }
}

int yywrap() {
    if (pass == 2) {
        printf("------- Ending second pass ------\n");    
        return 1;
    }
    printLinkedList();
    printf("----- Ending first pass --------\n");
    pass = 2;
    fclose(yyin);
    yyin = fopen("target.xsm", "r");
    if (!yyin) {
        perror("Error opening target.xsm");
        exit(1);
    }
    fp = fopen("final.xsm", "w+");
    if (!fp) {
        perror("Error opening code2.xsm");
        exit(1);
    }
    printf("----- Starting second pass -----\n");
    return 0;
}

int main() {
    yyin = fopen("target.xsm", "r");
    if (!yyin) {
        perror("Error opening target.xsm");
        exit(1);
    }
    printf("----- Starting first pass ------\n");
    yylex();
    return 0;
}
