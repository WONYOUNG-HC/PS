#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct _stack{
    char arr[102];
    int idx;
}Stack;

int empty(Stack * ps);
void push(Stack * ps, char bracket);
void pop(Stack * ps);
char peek(Stack * ps);

int main(void){
    Stack s;
    s.idx = -1;
    
    char sentence[102];
    scanf("%[^\n]s", sentence);
    getchar();
    while(sentence[0] != '.'){
        for(int i=0; sentence[i] != '.'; i++){
            if(sentence[i] == '(')
                push(&s, '(');
            else if(sentence[i] == ')'){
                if(peek(&s) == '(')
                    pop(&s);
                else
                    push(&s, ')');
            }
            else if(sentence[i] == '[')
                push(&s, '[');
            else if(sentence[i] == ']'){
                if(peek(&s) == '[')
                    pop(&s);
                else
                    push(&s, ']');
            }
        }
        
        if(empty(&s))
            printf("yes\n");
        else
            printf("no\n");
        
        s.idx = -1;
        
        scanf("%[^\n]s", sentence);
        getchar();
    }
    
    return 0;
}

int empty(Stack * ps){
    if(ps->idx == -1)
        return TRUE;
    else
        return FALSE;
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


