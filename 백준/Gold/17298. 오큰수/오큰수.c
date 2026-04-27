#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct _stack{
    int arr[1000000];
    int idx;
} Stack;

int empty(Stack * ps);
void push(Stack * ps, int num);
void pop(Stack * ps);
int peek(Stack * ps);

int main(void){
    Stack stack;
    stack.idx = -1;
    
    int cnt;
    scanf("%d", &cnt);
    
    int inputArr[cnt], printArr[cnt];
    
    for(int i=0; i<cnt; i++)
        scanf("%d", &inputArr[i]);
    
    for(int i=cnt-1; i>=0; i--){
        while(!empty(&stack) && peek(&stack) <= inputArr[i])
            pop(&stack);
        
        if(empty(&stack))
            printArr[i] = -1;
        else
            printArr[i] = peek(&stack);
        
        push(&stack, inputArr[i]);
    }
    
    for(int i=0; i<cnt; i++)
        printf("%d ", printArr[i]);
    printf("\n");
    
    return 0;
}

int empty(Stack * ps){
    if(ps->idx == -1)
        return TRUE;
    else
        return FALSE;
}

void push(Stack * ps, int num){
    ps->idx += 1;
    ps->arr[ps->idx] = num;
}

void pop(Stack * ps){
    ps->idx -= 1;
}

int peek(Stack * ps){
    return ps->arr[ps->idx];
}
