#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "codegen.h"

int a[26];

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
