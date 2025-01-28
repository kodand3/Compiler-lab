#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "codegen.h"

int regIndex = 0;
int labelIndex = 0;
FILE *target;
int a[26];
/*  
0 - check if inside while
1 - l1
2 - l2
*/
int labels[3];

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

int getlabel() {
    return labelIndex++;
}

int codegen(struct tnode* t) {
    if (!t) {
        return 0;
    }

    int i, j, l1, l2;

    switch (t->nodetype) {
        case NODETYPE_ADD:
            i = codegen(t->left);
            j = codegen(t->right);
            fprintf(target, "ADD R%d, R%d\n", i, j);
            freereg();
            return i;

        case NODETYPE_SUB:
            i = codegen(t->left);
            j = codegen(t->right);
            fprintf(target, "SUB R%d, R%d\n", i, j);
            freereg();
            return i;

        case NODETYPE_MUL:
            i = codegen(t->left);
            j = codegen(t->right);
            fprintf(target, "MUL R%d, R%d\n", i, j);
            freereg();
            return i;

        case NODETYPE_DIV:
            i = codegen(t->left);
            j = codegen(t->right);
            fprintf(target, "DIV R%d, R%d\n", i, j);
            freereg();
            return i;

        case NODETYPE_READ:
            i = codegen(t->left);
            fprintf(target, "MOV R1, %d\n", *(t->left->varname) - 'a' + 4096);
            fprintf(target, "CALL 2060\n");
            freereg();
            return EMPTY_REGISTER;

        case NODETYPE_WRITE:
            i = codegen(t->left);
            fprintf(target, "MOV R1, R%d\n", i);
            fprintf(target, "CALL 2090\n");
            freereg();
            return EMPTY_REGISTER;

        case NODETYPE_ASSIGN:
            i = codegen(t->right);
            fprintf(target, "MOV [%d], R%d\n", *(t->left->varname) - 'a' + 4096, i);
            freereg();
            return EMPTY_REGISTER;

        case NODETYPE_CONNECT:
            i = codegen(t->left);
            j = codegen(t->right);
            if (j != EMPTY_REGISTER)
                freereg();
            if (i != EMPTY_REGISTER)
                freereg();
            return EMPTY_REGISTER;

        case NODETYPE_ID:
            i = getreg();
            fprintf(target, "MOV R%d, [%d]\n", i, 4096 + (*(t->varname) - 'a'));
            return i;

        case NODETYPE_NUM:
            i = getreg();
            fprintf(target, "MOV R%d, %d\n", i, t->val);
            return i;

        case NODETYPE_LT:
            i = codegen(t->left);
            j = codegen(t->right);
            fprintf(target, "LT R%d, R%d\n", i, j);
            freereg();
            return i;

        case NODETYPE_GT:
            i = codegen(t->left);
            j = codegen(t->right);
            fprintf(target, "GT R%d, R%d\n", i, j);
            freereg();
            return i;

        case NODETYPE_LE:
            i = codegen(t->left);
            j = codegen(t->right);
            fprintf(target, "LE R%d, R%d\n", i, j);
            freereg();
            return i;

        case NODETYPE_GE:
            i = codegen(t->left);
            j = codegen(t->right);
            fprintf(target, "GE R%d, R%d\n", i, j);
            freereg();
            return i;

        case NODETYPE_NE:
            i = codegen(t->left);
            j = codegen(t->right);
            fprintf(target, "NE R%d, R%d\n", i, j);
            freereg();
            return i;

        case NODETYPE_EQ:
            i = codegen(t->left);
            j = codegen(t->right);
            fprintf(target, "EQ R%d, R%d\n", i, j);
            freereg();
            return i;

        case NODETYPE_WHILE:
            labels[0] = 1;
            l1 = getlabel();
            l2 = getlabel();
            labels[1] = l1;
            labels[2] = l2;
            fprintf(target, "L%d:\n", l1);
            i = codegen(t->left);
            fprintf(target, "JZ R%d, L%d\n", i, l2);
            j = codegen(t->right);
            fprintf(target, "JMP L%d\n", l1);
            fprintf(target, "L%d:\n", l2);
            if (j != EMPTY_REGISTER)
                freereg();
            if (i != EMPTY_REGISTER)
                freereg();
            labels[0] = 0;
            return EMPTY_REGISTER;

        case NODETYPE_IFELSE:
            i = codegen(t->left);
            l1 = getlabel();
            fprintf(target, "JZ R%d, L%d\n", i, l1);
            j = codegen(t->right->left);

            if (t->right->right != NULL) {
                l2 = getlabel();
                fprintf(target, "JMP L%d\n", l2);
                fprintf(target, "L%d:\n", l1);
                int k = codegen(t->right->right);
                if (k != EMPTY_REGISTER) {
                    freereg();
                }
                fprintf(target, "L%d:\n", l2);
            } else {
                fprintf(target, "L%d:\n", l1);
            }

            if (j != EMPTY_REGISTER)
                freereg();
            if (i != EMPTY_REGISTER)
                freereg();
            return EMPTY_REGISTER;

        case NODETYPE_BREAK:
            if (labels[0] == 0) {
                printf("Break statement not inside loop\n");
                exit(1);
            }
            fprintf(target, "JMP L%d\n", labels[2]);
            return EMPTY_REGISTER;
        
        case NODETYPE_CONTINUE:
            if (labels[0] == 0) {
                printf("Continue statement not inside loop\n");
                exit(1);
            }
            fprintf(target, "JMP L%d\n", labels[1]);
            return EMPTY_REGISTER;
    }
}


void check(struct tnode* t, int type){
    if (t->type != type){
        printf("Type Mismatch Error: %d != %d \n", t->type, type);
        exit(1);
    }
}

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


    switch (ntype)
    {
        /* aritimetic */
        case NODETYPE_ADD:
                          check(l, TYPE_INT);
                          check(r, TYPE_INT);
                          break;
        case NODETYPE_SUB:
                          check(l, TYPE_INT);
                          check(r, TYPE_INT);
                          break;
        case NODETYPE_MUL:
                          check(l, TYPE_INT);
                          check(r, TYPE_INT);
                          break;
        case NODETYPE_DIV:
                          check(l, TYPE_INT);
                          check(r, TYPE_INT);
                          break;
        
        /* Comparators */
        case NODETYPE_EQ:
                          check(l, TYPE_INT);
                          check(r, TYPE_INT);
                          break;
        case NODETYPE_NE:
                          check(l, TYPE_INT);
                          check(r, TYPE_INT);
                          break;
        case NODETYPE_GE:
                          check(l, TYPE_INT);
                          check(r, TYPE_INT);
                          break;
        case NODETYPE_GT:
                          check(l, TYPE_INT);
                          check(r, TYPE_INT);
                          break;
        case NODETYPE_LE:
                          check(l, TYPE_INT);
                          check(r, TYPE_INT);
                          break;
        case NODETYPE_LT:
                          check(l, TYPE_INT);
                          check(r, TYPE_INT);
                          break;
        
        /* Statements */
        case NODETYPE_WHILE:
                          check(l, TYPE_BOOL);
                          check(r, TYPE_NONE);
                          break;
        case NODETYPE_IFELSE:
                          check(l, TYPE_BOOL);
                          check(r, TYPE_NONE);
                          break;
        case NODETYPE_ELSE:
                          check(l, TYPE_NONE);
                          check(r, TYPE_NONE);
                          break;
    }

    return temp;
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
            case NODETYPE_IFELSE:
                printf("If-else ");
                break;
            case NODETYPE_WHILE:
                printf("While ");
                break;
            case NODETYPE_ELSE:
                printf("Else ");
                break;
        }
        printPrefix(t->left);
        printPrefix(t->right);
    }
}

int evaluate(struct tnode* t) {
    if (t == NULL) {
        return 0;
    }
    int i, j;
    switch (t->nodetype) {
        case NODETYPE_ADD:
            return evaluate(t->left) + evaluate(t->right);
            break;
        case NODETYPE_SUB:
            return evaluate(t->left) - evaluate(t->right);
            break;
        case NODETYPE_MUL:
            return evaluate(t->left) * evaluate(t->right);
            break;
        case NODETYPE_DIV:
            return evaluate(t->left) / evaluate(t->right);
            break;
        case NODETYPE_READ:
            printf("INPUT %c: ", *(t->left->varname));
            scanf("%d", a + (*(t->left->varname) - 'a'));
            return 0;
            break;
        case NODETYPE_WRITE:
            i = evaluate(t->left);
            printf("%d\n", i);
            return 0;
            break;
        case NODETYPE_ASSIGN:
            i = evaluate(t->right);
            a[*(t->left->varname) - 'a'] = i;
            return 0;
            break;
        case NODETYPE_CONNECT:
            i = evaluate(t->left);
            j = evaluate(t->right);
            return 0;
            break;
        case NODETYPE_ID:
            return a[(*(t->varname) - 'a')];
            break;
        case NODETYPE_NUM:
            return t->val;
            break;
        case NODETYPE_LE:
            return evaluate(t->left) <= evaluate(t->right);
            break;
        case NODETYPE_LT:
            return evaluate(t->left) < evaluate(t->right);
            break;
        case NODETYPE_GE:
            return evaluate(t->left) >= evaluate(t->right);
            break;
        case NODETYPE_GT:
            return evaluate(t->left) > evaluate(t->right);
            break;
        case NODETYPE_NE:
            return evaluate(t->left) != evaluate(t->right);
            break;
        case NODETYPE_EQ:
            return evaluate(t->left) == evaluate(t->right);
            break;
        case NODETYPE_IFELSE:
            if (evaluate(t->left)) {
                i = evaluate(t->right->left);
                return 0;
            } else {
                i = evaluate(t->right->right);
                return 0;
            }
            break;
        case NODETYPE_WHILE:
            while (evaluate(t->left)) {
                i = evaluate(t->right);
            }
            return 0;
    }
    return 0;
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
    fprintf(target, "MOV R4, \"Read\"\n");
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

    fprintf(target, "MOV R4, \"Write\"\n");
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
    fprintf(target, "MOV R4, \"Exit\"\n");
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
