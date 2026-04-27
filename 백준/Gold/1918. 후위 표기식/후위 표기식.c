#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct _stack{
    char stackArr[101];
    int index;
} Stack;

int isEmpty(Stack * pstack);
void push(Stack * pstack, char op);
char pop(Stack * pstack);
char peek(Stack * pstack);

int opPrec(char op);
int compareOp(char op1, char op2);

int main(void){
    Stack stack;
    stack.index = -1;
    
    char prefix[101];
    char postfix[101];
    
    scanf("%s", prefix);
    char tmp = prefix[0];
    
    int idx = 0;
    for(int i=1; tmp != '\0'; i++){
        if(opPrec(tmp) == -1)
            postfix[idx++] = tmp;
        else
            switch(tmp){
                case '(':
                    push(&stack, tmp);
                    break;
                case ')':
                    while(peek(&stack) != '(')
                        postfix[idx++] = pop(&stack);
                    pop(&stack);
                    break;
                case '*':
                case '/':
                case '+':
                case '-':
                    while(!isEmpty(&stack) && compareOp(peek(&stack), tmp) >= 0)
                        postfix[idx++] = pop(&stack);
                    
                    push(&stack, tmp);
                    break;
            }
        
        tmp = prefix[i];
    }
    
    while(!isEmpty(&stack))
        postfix[idx++] = pop(&stack);
    postfix[idx] = '\0';
    
    printf("%s\n", postfix);
    
    
    return 0;
}

int isEmpty(Stack * pstack){
    if(pstack->index == -1)
        return TRUE;
    else
        return FALSE;
}

void push(Stack * pstack, char op){
    pstack->index += 1;
    pstack->stackArr[pstack->index] = op;
}

char pop(Stack * pstack){
    int delIdx = pstack->index;
    
    pstack->index -= 1;
    
    return pstack->stackArr[delIdx];
}

char peek(Stack * pstack){
    return pstack->stackArr[pstack->index];
}

int opPrec(char op){
    switch(op){
        case '*':
        case '/':
            return 5;
        case '+':
        case '-':
            return 3;
        case '(':
        case ')':
            return 1;
    }
    
    return -1;
}

int compareOp(char op1, char op2){
    int op1num = opPrec(op1);
    int op2num = opPrec(op2);
    
    if(op1num > op2num)
        return 1;
    else if(op1num == op2num)
        return 0;
    else
        return -1;
}
