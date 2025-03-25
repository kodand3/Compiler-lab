#define NODE_CONNECTOR 0
#define NODE_PLUS 1
#define NODE_MINUS 2
#define NODE_MUL 3
#define NODE_DIV 4
#define NODE_ASSG 5
#define NODE_READ 6
#define NODE_WRITE 7
#define NODE_NUM 8
#define NODE_VAR 9
#define NODE_IFTHEN 10
#define NODE_IFELSE 11
#define NODE_WHILEDO 12
#define NODE_L 13
#define NODE_LE 14
#define NODE_G 15
#define NODE_GE 16
#define NODE_E 17
#define NODE_NE 18
#define NODE_BREAK 19
#define NODE_CONTINUE 20
#define NODE_REPEAT 21
#define NODE_DOWHILE 22
#define NODE_ARRAY 23
#define NODE_STR 24
#define NODE_VARASSG 25
#define NODE_ADDR 26
#define NODE_DEREF 27
#define NODE_DERASSG 28
#define NODE_MOD 29

#define NO_TYPE -1
#define INT_TYPE 0
#define BOOL_TYPE 1
#define STR_TYPE 2
#define INT_PTR 3
#define STR_PTR 4

typedef struct tnode {
    int val;        // value of a number for NUM nodes.
    int type;       // type of variable
    char* varname;  // name of a variable for ID nodes also used to store the string value for NODE_STR
    int nodetype;   // information about non-leaf nodes - read/write/connector/+/* etc.
    struct Gsymbol *Gentry;     // pointer to GST entry for global variables and functions
    struct tnode *left,*right, *mid;  // left, right and middle branches
}tnode;

/*Create a node tnode*/
struct tnode* createTree(int val, int vartype, int type, char* c, struct tnode *l, struct tnode *r, struct tnode* m);
