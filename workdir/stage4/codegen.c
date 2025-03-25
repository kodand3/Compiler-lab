typedef int reg_index;

int regCount = 0; //the number of registers currently in use
int labelCount = 0;//the number of labels used

int beginLabel = -1;
int endLabel = -1;

reg_index getReg(){
    if(regCount < 20)
        return regCount++;
    else
        return -1;
}

int freeReg(){
    if(regCount > 0){
        regCount--;
		return 0;
	}
     else{
		return -1;
	 }
}

int getLabel(){
    return labelCount ++;
}
void exitProgram(FILE* fileptr){
	fprintf(fileptr,"MOV R1, \"Exit\"\n"
                    "PUSH R1\n"
                    "PUSH R0\n"
                    "PUSH R0\n"
                    "PUSH R0\n"
                    "PUSH R0\n"
                    "CALL 0\n");
}

void readNum(reg_index r, FILE* fileptr){
	fprintf(fileptr, "PUSH R0\n"	
					 "PUSH R1\n"
					 "PUSH R2\n"
					 "MOV R2, R%d\n"
					 "MOV R0, \"Read\"\n"
					 "MOV R1, -1\n"
					 "PUSH R0\n"
					 "PUSH R1\n"
					 "PUSH R2\n"
					 "PUSH R0\n"
					 "PUSH R0\n"
					 "CALL 0\n"
					 "POP R0\n"
					 "POP R1\n" 
					 "POP R1\n"
					 "POP R1\n"
					 "POP R1\n"
					 
					 "POP R2\n"
					 "POP R1\n"
					 "POP R0\n", r);
}
		

void writeNum(int reg, FILE* fileptr){
	fprintf(fileptr, "PUSH R0\n"	
					 "PUSH R1\n"
					 "PUSH R2\n"
					 "MOV R2, R%d\n"
					 "MOV R1, -2\n"
					 "MOV R0, \"Write\"\n"


					 "PUSH R0\n"
					 "PUSH R1\n"
					 "PUSH R2\n"
					 "PUSH R0\n"
					 "PUSH R0\n"
					 "CALL 0\n"
					 "POP R0\n"
					 "POP R1\n" 
					 "POP R1\n"
					 "POP R1\n"
					 "POP R1\n"
					 
					 "POP R2\n"
					 "POP R1\n"
					 "POP R0\n", reg);	
}

reg_index codeGen( struct tnode *t, FILE* fileptr){

		reg_index rl, rr, r, rm;
		int mem_loc, val;
		int l1, l2, l3;
		char c;
		int prev_begin, prev_end;
		struct Gsymbol* entry;
		
		switch(t->nodetype){
		
			case NODE_CONNECTOR:
				codeGen(t->left, fileptr);
				codeGen(t->right, fileptr);
				break;
			case NODE_IFTHEN:
			    l1 = getLabel();
			    
			    r = codeGen(t->mid, fileptr);
			    fprintf(fileptr, "JZ R%d, L%d\n", r, l1);
			    freeReg();
			    
			    codeGen(t->left, fileptr);
			    fprintf(fileptr, "L%d:\n", l1);
			    break;
			case NODE_IFELSE:
			    l1 = getLabel();
			    l2 = getLabel();
			    
			    r = codeGen(t->mid, fileptr);
			    			    
			    fprintf(fileptr, "JZ R%d, L%d\n", r, l1);
			    freeReg(); //free the reg as there is no use left for the bool val
			    
			    codeGen(t->left, fileptr);			    
			    fprintf(fileptr, "JMP L%d\n", l2);
			    
			    fprintf(fileptr, "L%d:\n", l1);
			    codeGen(t->right, fileptr);
			    
			    fprintf(fileptr, "L%d:\n", l2);
			    break;
			case NODE_WHILEDO:
			    l1 = getLabel();
			    l2 = getLabel();

				prev_begin = beginLabel;
				prev_end = endLabel;

				beginLabel = l1;
				endLabel = l2;

			    fprintf(fileptr, "L%d:\n", l1);
			    
			    r = codeGen(t->left, fileptr);
			    
			    fprintf(fileptr, "JZ R%d, L%d\n", r, l2);
			    freeReg(); //free the reg as there is no use left for the bool val
			    codeGen(t->right, fileptr);
			    fprintf(fileptr, "JMP L%d\n", l1);
			    
			    fprintf(fileptr, "L%d:\n", l2);

				beginLabel = prev_begin;
				endLabel = prev_end;
			    return -1;
			    break;
			case NODE_L:
				rl = codeGen(t->left, fileptr);
				rr = codeGen(t->right, fileptr);
								
				fprintf(fileptr, "LT R%d, R%d\n", rl, rr);
				freeReg();
				return rl;
				break;
			case NODE_LE:
				rl = codeGen(t->left, fileptr);
				rr = codeGen(t->right, fileptr);
								
				fprintf(fileptr, "LE R%d, R%d\n", rl, rr);
				freeReg();
				return rl;
				break;
			case NODE_G:
				rl = codeGen(t->left, fileptr);
				rr = codeGen(t->right, fileptr);
							
				fprintf(fileptr, "GT R%d, R%d\n", rl, rr);
				freeReg();
				return rl;
				break;
			case NODE_GE:
				rl = codeGen(t->left, fileptr);
				rr = codeGen(t->right, fileptr);
								
				fprintf(fileptr, "GE R%d, R%d\n", rl, rr);
				freeReg();
				return rl;
				break;	
			case NODE_E:
				rl = codeGen(t->left, fileptr);
				rr = codeGen(t->right, fileptr);
								
				fprintf(fileptr, "EQ R%d, R%d\n", rl, rr);
				freeReg();
				return rl;
				break;
			case NODE_NE:
				rl = codeGen(t->left, fileptr);
				rr = codeGen(t->right, fileptr);
							
				fprintf(fileptr, "NE R%d, R%d\n", rl, rr);
				freeReg();
				return rl;
				break;					    
			case NODE_PLUS:
				rl = codeGen(t->left, fileptr);
				rr = codeGen(t->right, fileptr);
							
				fprintf(fileptr, "ADD R%d, R%d\n", rl, rr);
				freeReg();
				return rl;
				break;
			case NODE_MINUS:
				rl = codeGen(t->left, fileptr);
				rr = codeGen(t->right, fileptr);
								
				fprintf(fileptr, "SUB R%d, R%d\n", rl, rr);
				freeReg();
				return rl;
				break;	
			case NODE_MUL:
				rl = codeGen(t->left, fileptr);
				rr = codeGen(t->right, fileptr);	
				
				fprintf(fileptr, "MUL R%d, R%d\n", rl, rr);
				freeReg();
				return rl;
				break;	
			case NODE_DIV:
				rl = codeGen(t->left, fileptr);
				rr = codeGen(t->right, fileptr);
				
				fprintf(fileptr, "DIV R%d, R%d\n", rl, rr);
				freeReg();
				return rl;
				break;	
			case NODE_MOD:
				rl = codeGen(t->left, fileptr);
				rr = codeGen(t->right, fileptr);

				fprintf(fileptr, "MOD R%d, R%d\n", rl, rr);
				freeReg();
				return rl;
				break;	
			case NODE_ASSG:
				rl = codeGen(t->left, fileptr);
				rr = codeGen(t->right, fileptr);

				fprintf(fileptr, "MOV [R%d], R%d\n",rl, rr);
				freeReg();
				freeReg();
				break;
			case NODE_READ:
				rl = codeGen(t->left, fileptr);		

				readNum(rl, fileptr);
				freeReg();
				break;
			case NODE_WRITE:
				r = codeGen(t->left, fileptr);
				writeNum(r, fileptr);
				freeReg();
				break;
			case NODE_VAR:
				entry = Lookup(t->varname);
				
				r = getReg();
				fprintf(fileptr, "MOV R%d, [%d]\n", r, entry->binding);
				return r;
				break;
			case NODE_NUM:
				r = getReg();
				fprintf(fileptr, "MOV R%d, %d\n", r, t->val);
				return r;
				break;
			case NODE_STR:
				r = getReg();
				fprintf(fileptr, "MOV R%d, %s\n",r, t->varname);
				return r;
				break;
			case NODE_ARRAY:
				
				r = getReg();			    
				entry = Lookup(t->left->varname);			
				rr = codeGen(t->right, fileptr);
				if(t->mid != NULL){
					rm = codeGen(t->mid, fileptr);
					fprintf(fileptr, "MUL R%d, %d\n", rr, entry->rowlen);
					fprintf(fileptr, "ADD R%d, R%d\n", rr, rm);
					freeReg();
				}

				fprintf(fileptr, "ADD R%d, %d\n", rr, entry->binding);

				fprintf(fileptr, "MOV R%d, [R%d]\n", r, rr);
				freeReg();
				return r;
				break;
			case NODE_BREAK:
				if(endLabel != -1)
					fprintf(fileptr, "JMP L%d\n", endLabel);
				break;
			case NODE_CONTINUE:
				if(beginLabel != -1)
					fprintf(fileptr, "JMP L%d\n", beginLabel);
				break;
			case NODE_REPEAT:
			    l1 = getLabel();
			    l2 = getLabel();

				prev_begin = beginLabel;
				prev_end = endLabel;

				beginLabel = l1;
				endLabel = l2;

			    fprintf(fileptr, "L%d:\n", l1);
			    
			    codeGen(t->left, fileptr);
			    
			    r = codeGen(t->right, fileptr);
			    fprintf(fileptr, "JNZ R%d, L%d\n", r, l2);
			    freeReg(); //free the reg as there is no use left for the bool val
			    fprintf(fileptr, "JMP L%d\n", l1);
			    
			    fprintf(fileptr, "L%d:\n", l2);

				beginLabel = prev_begin;
				endLabel = prev_end;	
				break;	
			case NODE_DOWHILE:
			    l1 = getLabel();
			    l2 = getLabel();

				prev_begin = beginLabel;
				prev_end = endLabel;

				beginLabel = l1;
				endLabel = l2;

			    fprintf(fileptr, "L%d:\n", l1);
			    
			    codeGen(t->left, fileptr);
			    
			    r = codeGen(t->right, fileptr);
			    fprintf(fileptr, "JZ R%d, L%d\n", r, l2);
			    freeReg(); //free the reg as there is no use left for the bool val
			    fprintf(fileptr, "JMP L%d\n", l1);
			    
			    fprintf(fileptr, "L%d:\n", l2);

				beginLabel = prev_begin;
				endLabel = prev_end;	
				break;	
			case NODE_VARASSG:
				entry = Lookup(t->left->varname);

				if(t->right == NULL)	{
					rr = getReg();
					fprintf(fileptr, "MOV R%d, 0\n", rr);
				}
				else{

					rr = codeGen(t->right, fileptr);
					if(t->mid != NULL){
						rm = codeGen(t->mid, fileptr);
						fprintf(fileptr, "MUL R%d, %d\n", rr, entry->rowlen);
						fprintf(fileptr, "ADD R%d, R%d\n", rr, rm);
						freeReg();
					}
				}
				fprintf(fileptr, "ADD R%d, %d\n", rr, entry->binding);
				return rr;
				break;
			case NODE_DERASSG:
				rl = codeGen(t->left, fileptr);
				return rl;
				break;
			case NODE_DEREF:
				r = getReg();
				rl = codeGen(t->left, fileptr);

				fprintf(fileptr, "MOV R%d, [R%d]\n", r, rl);
				return r;
				break;
			case NODE_ADDR:
				r = getReg();
				entry = Lookup(t->left->varname);	
				fprintf(fileptr, "MOV R%d, %d\n", r, entry->binding);	
				return r;
				break;		


								
		}
	return -1;
	}

