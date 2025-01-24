#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum nodetype {
    NODETYPE_ID,
    NODETYPE_NUM,
    NODETYPE_ADD,
    NODETYPE_SUB,
    NODETYPE_MUL,
    NODETYPE_DIV,
    NODETYPE_READ,
    NODETYPE_WRITE,
    NODETYPE_ASSIGN,
    NODETYPE_CONNECT
};

typedef struct tnode {
    int val;        // Value of a number for NUM nodes.
    int type;       // Type of variable.
    char* varname;  // Name of a variable for ID nodes.
    int nodetype;   // Node type - read/write/connector/+/* etc.
    struct tnode *left, *right;  // Left and right branches.
} tnode;

struct tnode *createTreeNode(int val, int type, char *c, int ntype, struct tnode *l, struct tnode *r);
void printPrefix(struct tnode* t);

