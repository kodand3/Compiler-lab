#include <string.h>
    
struct tnode* createTree(int val, int vartype, int type, char* c, struct tnode *l, struct tnode *r, struct tnode* m){
    
    if(type == NODE_PLUS || type == NODE_MINUS || type == NODE_DIV || type == NODE_MUL){
        if(l->type != INT_TYPE || r->type != INT_TYPE){
            perror("ERROR: type mismatch in expression\n");
            exit(1);
        }
    }
    if(type == NODE_ASSG){       
        if(l->type != r->type){
            perror("ERROR: assigning value of wrong dtype to ID ");
            exit(1);
        }
    }
    if(type == NODE_WHILEDO ){
        if(l->type != BOOL_TYPE ){
            perror("ERROR : condition is not of type boolean");
            exit(1);
        }
    }
    if(type == NODE_IFTHEN || type == NODE_IFELSE){
        if( m->type != BOOL_TYPE ){
            perror("ERROR : condition is not of type boolean");
            exit(1);
        }
    }
    if(type == NODE_ARRAY){
        if(Lookup(l->varname)->size == 0 ){
            perror("ERROR: variable not of type array\n");
            exit(1);
        }
        if(r->type != INT_TYPE ){
            perror("ERROR: the index given not an integer");
            exit(1);
        }
        if(m != NULL){
            if(m->type != INT_TYPE){
                perror("ERROR: the index given is not an integer\n");
                exit(1);
            }
        }
    }
    if(type == NODE_DEREF || type == NODE_DERASSG){

        if(Lookup(l->varname)->type != STR_PTR && Lookup(l->varname)->type != INT_PTR ){
            perror("ERROR: deferencing not allowed for this varible");
            exit(1);       
        }
    }
    struct tnode* temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));

    temp->type = vartype;
    temp->val = val;
    temp->nodetype = type;
    if(c != NULL)
        temp->varname = c;
    temp->left = l;
    temp->right = r;
    temp->mid = m;
    
    return temp;
}

int typeCheck(char type, struct tnode*l, struct tnode*r, struct tnode*m){
    switch(type){
        case 'c' : if(l->type != BOOL_TYPE){
                perror("ERROR : condition is not of type boolean");
                exit(1);            
            }
            break;
        case 'a' : if(l->type != INT_TYPE || r->type != INT_TYPE){
                perror("type mismatch in arithmetic op\n");
                exit(1);
            }
            break;
        case 'b' : if(l->type != r->type){
                perror("ERROR:type mismatch in assign op");
                exit(1);
            }
            break;
    }
}

