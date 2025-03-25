int variableArray[26];//array for storing values of variables

int isBreak = 0;
int isContinue =0;

	
int evaluator(struct tnode* t){

	if(t == NULL)
		return -1;
	else{
	
		int rl, rr, rm, r;
		int mem_loc, val;
		char c;
		
		switch(t->nodetype){
		
			case NODE_CONNECTOR:
				evaluator(t->left);
				if(!isContinue && !isBreak)
				    evaluator(t->right);
				return -1;
				break;
			case NODE_REPEAT:
		        rl = 0;
		        while(rl == 0){
					evaluator(t->left);
					if(isBreak == 1)    
					    break;
					isContinue = 0;
					rl = evaluator(t->right);
				}
				isBreak = 0;
		        break;
		    case NODE_DOWHILE:
		        rl = 1;
		        while(rl != 0){
					evaluator(t->left);
					if(isBreak == 1)    
					    break;
					isContinue = 0;
					rl = evaluator(t->right);
				}
				isBreak = 0;
		        break;		        			    
			case NODE_WHILEDO:
		        rl = evaluator(t->left);
		        while(rl != 0){
					evaluator(t->right);
					if(isBreak == 1)    
					    break;
					isContinue = 0;
					rl = evaluator(t->left);
				}
				isBreak = 0;
		        break;
		    case NODE_BREAK:
		        isBreak = 1;
		        break;
		    case NODE_CONTINUE:
		        isContinue = 1;
		        break;
		    case NODE_IFELSE:
		        rm = evaluator(t->mid);
		        if(rm != 0)
		            evaluator(t->left);
		        else
		            evaluator(t->right);
		        break;
		    case NODE_IFTHEN:
		        rm = evaluator(t->mid);
		        if(rm != 0)
		            evaluator(t->left);
			    break;
		    case NODE_L:
		        rl = evaluator(t->left);
		        rr = evaluator(t->right);
		        return rl < rr;
		        break;
		    case NODE_LE:
		        rl = evaluator(t->left);
		        rr = evaluator(t->right);
		        return rl <= rr;
		        break;	
		    case NODE_G:
		        rl = evaluator(t->left);
		        rr = evaluator(t->right);
		        return rl > rr;	
		        break;	
		    case NODE_GE:
		        rl = evaluator(t->left);
		        rr = evaluator(t->right);
		        return rl >= rr;
		        break;		
		    case NODE_E:
		        rl = evaluator(t->left);
		        rr = evaluator(t->right);
		        return rl == rr;
		        break;
		    case NODE_NE:
		        rl = evaluator(t->left);
		        rr = evaluator(t->right);
		        return rl != rr;	
		        break;	        		    
			case NODE_PLUS:
				rl = evaluator(t->left);
				rr = evaluator(t->right);
			
				return rl + rr;
				break;
			case NODE_MINUS:
				rl = evaluator(t->left);
				rr = evaluator(t->right);
			
				return rl - rr;
				break;	
			case NODE_MUL:
				rl = evaluator(t->left);
				rr = evaluator(t->right);
			
				return rl * rr;
				break;	
			case NODE_DIV:
				rl = evaluator(t->left);
				rr = evaluator(t->right);
			
				return rl / rr;
				break;	
			case NODE_ASSG:
				c = *(t->left->varname);
				rr = evaluator(t->right);
				
				mem_loc = c - 'a';
				variableArray[mem_loc] = rr;
				return -1;
				break;
			case NODE_READ:
				c = *(t->left->varname);
				
				mem_loc= c - 'a';
				printf("Enter the value for %c: \n", c);
				scanf("%d%*c",variableArray+mem_loc);
				return -1;
				break;
			case NODE_WRITE:
				r = evaluator(t->left);
				printf("%d\n", r);
				return -1;
				break;
			case NODE_VAR:
				c = *(t->varname);
				
				mem_loc = c - 'a';
				return variableArray[mem_loc];
				break;
			case NODE_NUM:
				val = t->val;
				return val;
				break;
								
		}
	return -1;
	}

}
