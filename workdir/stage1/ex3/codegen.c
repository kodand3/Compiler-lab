#include <stdlib.h>
#include <stdio.h>
#include "codegen.h"


int regIndex = -1;

struct tnode *makeLeafNode(int n)
{
    struct tnode *temp;
    temp = (struct tnode *)malloc(sizeof(struct tnode));
    temp->op = NULL;
    temp->val = n;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode *makeOperatorNode(char c, struct tnode *l, struct tnode *r)
{
    struct tnode *temp;
    temp = (struct tnode *)malloc(sizeof(struct tnode));
    temp->op = malloc(sizeof(char));
    *(temp->op) = c;
    temp->left = l;
    temp->right = r;
    return temp;
}

int evaluate(struct tnode *t)
{
    if (t->op == NULL)
    {
        return t->val;
    }
    else
    {
        switch (*(t->op))
        {
        case '+':
            return evaluate(t->left) + evaluate(t->right);
            break;
        case '-':
            return evaluate(t->left) - evaluate(t->right);
            break;
        case '*':
            return evaluate(t->left) * evaluate(t->right);
            break;
        case '/':
            return evaluate(t->left) / evaluate(t->right);
            break;
        }
    }
}

int codegen(struct tnode *t, FILE *target)
{
    int l, r;
    if (t->left->op == NULL)
    {
        l = getreg();
        fprintf(target, "MOV R%d, %d\n", l, t->left->val);
    }
    else
    {
        l = codegen(t->left, target);
    }
    if (t->right->op == NULL)
    {
        r = getreg();
        fprintf(target, "MOV R%d, %d\n", r, t->right->val);
    }
    else
    {
        r = codegen(t->right, target);
    }
    if (*(t->op) == '+')
        fprintf(target, "ADD R%d, R%d\n", l, r);
    else if (*(t->op) == '-')
        fprintf(target, "SUB R%d, R%d\n", l, r);
    else if (*(t->op) == '*')
        fprintf(target, "MUL R%d, R%d\n", l, r);
    else if (*(t->op) == '/')
        fprintf(target, "DIV R%d, R%d\n", l, r);
    freereg();
    return l;
}

void freereg()
{
    regIndex--;
}

int getreg()
{
    regIndex++;
    return regIndex;
}

void printConsole(int i, FILE *target)
{
    int l = getreg();
    int r = getreg();
    fprintf(target, "MOV SP, %d\n", 4096);
    fprintf(target, "MOV [%d], R%d\n", 4095, i);
    fprintf(target, "MOV R%d, [%d]\n", l, 4095);
    fprintf(target, "MOV R%d, %d\n", r, 5);
    fprintf(target, "PUSH %d\n", r);
    fprintf(target, "MOV R%d, %d\n", r, -2);
    fprintf(target, "PUSH R%d\n", r);
    fprintf(target, "PUSH R%d\n", l);
    fprintf(target, "PUSH R%d\n", l);
    fprintf(target, "PUSH R%d\n", l);
    fprintf(target, "INT 7\n");
    fprintf(target, "POP R%d\n", r);
    fprintf(target, "POP R%d\n", r);
    fprintf(target, "POP R%d\n", r);
    fprintf(target, "POP R%d\n", r);
    fprintf(target, "POP R%d\n", r);
    freereg();
    freereg();
}
