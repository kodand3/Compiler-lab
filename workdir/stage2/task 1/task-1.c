#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "task-1.h"

struct tnode *createTreeNode(int val, int type, char *c, int ntype, struct tnode *l, struct tnode *r)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->val = val;
    temp->type = type;
    temp->nodetype = ntype;

    if (c != NULL) {
        temp->varname = (char*)malloc(strlen(c) + 1);
        strcpy(temp->varname, c);
    } else {
        temp->varname = NULL;
    }

    temp->left = l;
    temp->right = r;

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
        }
        printPrefix(t->left);
        printPrefix(t->right);
    }
}
