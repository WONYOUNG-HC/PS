#include <stdio.h>

typedef struct _stack{
    char stackArr[51];
    int topidx;
} Stack;

void SPush(Stack * pstack, char data);
void SPop(Stack * pstack);
char SPeek(Stack * pstack);

int main(void){
    Stack stack;
    stack.topidx = -1;
    
    int cnt;
    scanf("%d", &cnt);
    getchar();
    
    char c = '\0';
    for(int i=0; i<cnt; i++){
		c = getchar();
        while(c != '\n'){
            switch(c){
                case '(':
                    SPush(&stack, '(');
                    break;
                case ')':
                    if(SPeek(&stack) == '(')
                        SPop(&stack);
                    else
                        SPush(&stack, ')');
                    break;
            }
			c = getchar();
        }

        if(stack.topidx == -1)
            printf("YES\n");
        else
            printf("NO\n");
        
        c = '\0';
		stack.topidx = -1;
    }
    
    return 0;
}

void SPush(Stack * pstack, char data)
{
    pstack->topidx += 1;
    pstack->stackArr[pstack->topidx] = data;
}

void SPop(Stack * pstack)
{
    pstack->topidx -= 1;
}

char SPeek(Stack * pstack)
{
    if(pstack->topidx == -1)
        return 'F';
    return pstack->stackArr[pstack->topidx];
}
