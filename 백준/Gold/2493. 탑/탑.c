#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct _stack{
    int stackArr[500000];
    int stackIdx;
} Stack;

void push(Stack * pstack, int height);
void pop(Stack * pstack);
int peek(Stack * pstack);
int isEmpty(Stack * pstack);
int compare(int d1, int d2);

int main(void){
    Stack stack;
    Stack index;
    stack.stackIdx = -1;
    index.stackIdx = -1;
    
    int cnt, height;
    
    scanf("%d", &cnt);
    
    
    for(int i=0; i<cnt; i++){
        scanf("%d", &height);
        
        while(!isEmpty(&stack) && compare(height, peek(&stack)) > 0){
            pop(&stack);
            pop(&index);
        }
        
        if(isEmpty(&stack))
            printf("0 ");
        else
            printf("%d ", peek(&index));
        
        push(&stack, height);
        push(&index, i+1);
    }
    
    return 0;
}

void push(Stack * pstack, int height){
    pstack->stackIdx += 1;
    pstack->stackArr[pstack->stackIdx] = height;
}

void pop(Stack * pstack){
    pstack->stackIdx -= 1;
}

int peek(Stack * pstack){
    return pstack->stackArr[pstack->stackIdx];
}

int isEmpty(Stack * pstack){
    if(pstack->stackIdx == -1)
        return TRUE;
    else
        return FALSE;
}

int compare(int d1, int d2){
    if(d1 > d2)
        return 1;
    else
        return -1;
}
