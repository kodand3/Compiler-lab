#include <stdlib.h>
#include <stdio.h>
#include "exprtree.h"

struct tnode* makeLeafNode(int n) {
    struct tnode *temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = NULL;
    temp->val = n;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makeOperatorNode(char c, struct tnode *l, struct tnode *r) {
    struct tnode *temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = malloc(sizeof(char));
    *(temp->op) = c;
    temp->left = l;
    temp->right = r;
    return temp;
}

int evaluate(struct tnode *t) {
    if (t->op == NULL) {
        return t->val;
    } else {
        switch (*(t->op)) {
            case '+': return evaluate(t->left) + evaluate(t->right);
            case '-': return evaluate(t->left) - evaluate(t->right);
            case '*': return evaluate(t->left) * evaluate(t->right);
            case '/': return evaluate(t->left) / evaluate(t->right);
            default: return 0;
        }
    }
}

void prefix(struct tnode *t) {
    if(t->op == NULL){
        printf("%d ", t->val);
        return;
    }
    printf("%c ", *(t->op));
    prefix(t->left);
    prefix(t->right);
}

void postfix(struct tnode *t) {
    if(t->op == NULL){
        printf("%d ", t->val);
        return;
    }
    prefix(t->left);
    prefix(t->right);
    printf("%c ", *(t->op));
}