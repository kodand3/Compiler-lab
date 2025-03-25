#include <string.h>

typedef struct Gsymbol {
    char* name;       // name of the variable
    int type;         // type of the variable
    int size;         // size of the type of the variable
    int binding;      // stores the static memory address allocated to the variable
    int rowlen;
    struct Gsymbol *next;
}Gsymbol;

struct Gsymbol* head = NULL;
int data_size = 0;

struct Gsymbol *Lookup(char* name)// Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.
{ 
    if(!name){
        perror("ERROR:symbol table entry not found\n");
        exit(1);
        return NULL;
    }


    struct Gsymbol* ptr = head;
    while( ptr != NULL){
        if(strcmp(ptr->name, name) == 0)
            return ptr;
        
        ptr = ptr->next;
    }

    perror("ERROR:symbol table entry not found\n");
    exit(1);
    return NULL;

}

void Install(char* name, int type, int size, int rowlen){

    struct Gsymbol* temp = (struct Gsymbol *) malloc(sizeof(struct Gsymbol));
    temp->name = name;
    temp->type = type;
    temp->size = size;
    temp->rowlen = rowlen;
    temp->next = NULL;
    data_size = data_size + size;
    if(head == NULL){
        temp->binding = 4096;
        head = temp;
    }
    else{
        struct Gsymbol* ptr = head;

        while(ptr->next != NULL){
            if(strcmp(ptr->name, name) == 0)
                perror("ERROR: same variable name declared twice");
            ptr = ptr->next;
        }
        temp->binding = ptr->binding + ptr->size;
        ptr->next = temp;
    }

}

void PrintSymbolTable(){
    struct Gsymbol* t = head;

    printf("TYPE    |      NAME     |      SIZE     |    BINDING    |\n");
    printf("---------------------------------------------------------\n");

    while (t != NULL) {
        if (t->type == INT_TYPE) {
            printf("INT\t|\t");
        } else {
            printf("STR\t|\t");
        }
        printf("%s\t|\t", t->name);
        printf("%d\t|\t", t->size);
        printf("%d\t|", t->binding);
        printf("\n");
        t = t->next;
    }
}