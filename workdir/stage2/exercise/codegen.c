#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "codegen.h"

int regIndex = 0;
FILE *target;
int a[26];

struct tnode *createTreeNode(int val, int type, char *c, int ntype, struct tnode *l, struct tnode *r)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->val = val;
    temp->type = type;
    temp->nodetype = ntype;

    temp->varname = (char*)malloc(sizeof(char));
    *(temp->varname) = *(c);

    temp->left = l;
    temp->right = r;

    return temp;
}

int evaluate(struct tnode *t) {
    if(!t){
        return 0;
    }

    int temp;

    switch((t->nodetype)) {
        /* Arithemetic */
        case NODETYPE_ADD:
                          return evaluate(t->left) + evaluate(t->right);
        case NODETYPE_SUB:
                          return evaluate(t->left) - evaluate(t->right);
        case NODETYPE_MUL:
                          return evaluate(t->left) * evaluate(t->right);
        case NODETYPE_DIV:
                          return evaluate(t->left) / evaluate(t->right);

        
        /* Statements */
        case NODETYPE_READ:
                          printf("INPUT %c : ", *(t->left->varname));
                          scanf("%d", a + (*(t->left->varname) - 'a'));
                	      return 0;
        case NODETYPE_WRITE:
                          printf("Eval done: %d\n", evaluate(t->left));
                          return 0;
        case NODETYPE_ASSIGN:
                          a[*(t->left->varname)-'a'] = evaluate(t->right);
                          return 0;
        

        /* Connecter */
        case NODETYPE_CONNECT:
                              evaluate(t->left);
                              evaluate(t->right);
                              return 0;
        
        /* Identifiers */
        case NODETYPE_ID:
                         return a[*(t->varname)-'a'];
        case NODETYPE_NUM:
                         return t->val;
    }
}

void printPrefix(struct tnode* t)
{
    if (!t) {
        return;
    }
    if (t->nodetype == NODETYPE_ID) {
        printf("%s ", t->varname);
    } 
    else if (t->nodetype == NODETYPE_NUM) {
        printf("%d ", t->val);
    } 
    else {
        switch (t->nodetype) {
            case NODETYPE_ADD:
                printf("+ ");
                break;
            case NODETYPE_SUB:
                printf("- ");
                break;
            case NODETYPE_MUL:
                printf("* ");
                break;
            case NODETYPE_DIV:
                printf("/ ");
                break;
            case NODETYPE_READ:
                printf("read ");
                break;
            case NODETYPE_WRITE:
                printf("write ");
                break;
            case NODETYPE_ASSIGN:
                printf("= ");
                break;
            case NODETYPE_CONNECT:
                printf("Connecter ");
                break;
        }
        printPrefix(t->left);
        printPrefix(t->right);
    }
}

int getreg(){
    if(regIndex == 20){
        printf("All registers used!\n");
        exit(1);
    }
    return regIndex++;
}

int freereg(){
    if(regIndex == 0){
        printf("Invalid free\n");
        exit(1);
    }
    return regIndex--;
}





int codegen(struct tnode* t) {
    if(!t) {
        return 0;
    }

    int l, r, addr;

    switch((t->nodetype)) {
        /* Arithmetic */
        case NODETYPE_ADD:
                            l = codegen(t->left);
                            r = codegen(t->right);
                            fprintf(target, "ADD R%d, R%d\n", l, r);
                            freereg();
                            return l;
                            break;
        case NODETYPE_SUB:
                            l = codegen(t->left);
                            r = codegen(t->right);
                            fprintf(target, "SUB R%d, R%d\n", l, r);
                            freereg();
                            return l;
                            break;
        case NODETYPE_MUL:
                            l = codegen(t->left);
                            r = codegen(t->right);
                            fprintf(target, "MUL R%d, R%d\n", l, r);
                            freereg();
                            return l;
                            break;
        case NODETYPE_DIV:
                            l = codegen(t->left);
                            r = codegen(t->right);
                            fprintf(target, "DIV R%d, R%d\n", l, r);
                            freereg();
                            return l;
                            break;

        /* Statements */
        case NODETYPE_READ:
                            l = codegen(t->left);
                            addr = *(t->left->varname) - 'a' + 4096;
                            printf("During read address : %d, var ascii : %d\n", addr, (int)*(t->left->varname));
                            fprintf(target, "MOV R1, %d\n", addr);
                            fprintf(target, "CALL 2060\n");
                            freereg();
                            return EMPTY_REGISTER;
                            break;
        case NODETYPE_WRITE:
                            l = codegen(t->left);
                            printf("Write begin called\n");
                            fprintf(target, "MOV R1, R%d\n", l);
                	        fprintf(target, "CALL 2090\n");
                            freereg();
                            return EMPTY_REGISTER;
                            break;
        case NODETYPE_ASSIGN:
                            l = codegen(t->right);
                            addr = *(t->left->varname)-'a' + 4096;
                            fprintf(target, "MOV [%d],R%d\n", addr, l);
                            freereg();
                            return EMPTY_REGISTER;
                            break;


        /* Connecters */        
        case NODETYPE_CONNECT:
                            l = codegen(t->left);
                            r = codegen(t->right);
                            if(l != EMPTY_REGISTER)
                                freereg();
                            if(r != EMPTY_REGISTER)
                                freereg();
                            return EMPTY_REGISTER;
                            break;

        /* Identifiers */
        case NODETYPE_ID:
                            l = getreg();
                            printf("\nThe ID is %c\n", *(t->varname));
                            addr = *(t->varname)-'a' + 4096;
                            fprintf(target, "MOV R%d, [%d]\n", l, addr);
                            return l;
                            break;
        case NODETYPE_NUM:
                            l = getreg();
                            fprintf(target, "MOV R%d, %d\n", l, t->val);
                            return l;
                            break;
    
        default:
            fprintf(stderr, "Error: Unknown nodetype %d\n", t->nodetype);
            exit(1);
    }
}



void start() 
{
    target = fopen("target.xsm", "w");
    if (!target) {
        fprintf(stderr, "Error: Unable to open file target.xsm\n");
        exit(1);
    }

    fprintf(target, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 0, 2056, 0, 0, 0, 0, 0, 0);
    fprintf(target, "MOV SP,4121\n");
    fprintf(target, "JMP 2120\n");
    fprintf(target, "MOV R4 , \"Read\"\n");
    fprintf(target, "PUSH R4\n");
    fprintf(target, "MOV R4 ,-1\n");
    fprintf(target, "PUSH R4\n");
    fprintf(target, "MOV R4,R1\n");
    fprintf(target, "PUSH R4\n");
    fprintf(target, "PUSH R4\n");
    fprintf(target, "PUSH R4\n");
    fprintf(target, "CALL 0\n");
    fprintf(target, "POP R4\n");
    fprintf(target, "POP R4\n");
    fprintf(target, "POP R4\n");
    fprintf(target, "POP R4\n");
    fprintf(target, "POP R4\n");
    fprintf(target, "RET\n");

    fprintf(target, "MOV R4 , \"Write\"\n");
    fprintf(target, "PUSH R4\n");
    fprintf(target, "MOV R4 ,-2\n");
    fprintf(target, "PUSH R4\n");
    fprintf(target, "MOV R4,R1\n");
    fprintf(target, "PUSH R4\n");
    fprintf(target, "PUSH R4\n");
    fprintf(target, "PUSH R4\n");
    fprintf(target, "CALL 0\n");
    fprintf(target, "POP R4\n");
    fprintf(target, "POP R4\n");
    fprintf(target, "POP R4\n");
    fprintf(target, "POP R4\n");
    fprintf(target, "POP R4\n");
    fprintf(target, "RET\n");

    return;
}

void end()
{
    fprintf(target, "MOV R4 , \"Exit\"\n");
    fprintf(target, "PUSH R4\n");
    fprintf(target, "PUSH R4\n");
    fprintf(target, "PUSH R4\n");
    fprintf(target, "PUSH R4\n");
    fprintf(target, "PUSH R4\n");
    fprintf(target, "CALL 0\n");
    fprintf(target, "POP R4\n");
    fprintf(target, "POP R4\n");
    fprintf(target, "POP R4\n");
    fprintf(target, "POP R4\n");
    fprintf(target, "POP R4\n");

    return;

}