#include <stdio.h>

typedef struct _stack{
    char arr[100001];
    int idx;
} Stack;

void push(Stack * ps, char bracket);
void pop(Stack * ps);
char peek(Stack * ps);

int main(void){
    char exp[100001];
    scanf("%s", exp);
    
    Stack stack;
    stack.idx = -1;
    
    int stick = 0;
    int result = 0;
    
    for(int i=0; exp[i] != '\0'; i++){
        if(exp[i] == '('){
            if(peek(&stack) == ')')
                pop(&stack);
            
            push(&stack, '(');
            stick++;
        }
        else{
            if(peek(&stack) == '('){
                stick--;
                result += stick;
            }
            else{
                pop(&stack);
                stick--;
                result++;
            }
            
            pop(&stack);
            push(&stack, ')');
        }
    }
    
    printf("%d\n", result);
    
    return 0;
}

void push(Stack * ps, char bracket){
    ps->idx += 1;
    ps->arr[ps->idx] = bracket;
}

void pop(Stack * ps){
    ps->idx -= 1;
}

char peek(Stack * ps){
    return ps->arr[ps->idx];
}

