#ifndef EXPTREE_H
#define EXPTREE_H

typedef struct tnode {
    int val;
    char *op;
    struct tnode *left, *right;
} tnode;

struct tnode* makeLeafNode(int n);
struct tnode* makeOperatorNode(char c, struct tnode *l, struct tnode *r);
int evaluate(struct tnode *t);

#endif // EXPTREE_H
