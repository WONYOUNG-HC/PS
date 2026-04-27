#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node{
    int num;
    struct _node * next;
} Node;

typedef struct _stack{
    Node * head;
    int count;
} Stack;

void push(Stack * pstack, int num);
int pop(Stack * pstack);
int size(Stack * pstack);
int empty(Stack * pstack);
int top(Stack * pstack);

int main(void){
    Stack stack;
    stack.head = NULL;
    stack.count = 0;
    
    int cnt, num;
    char order[6];
    
    scanf("%d", &cnt);
    getchar();
    
    for(int i=0; i<cnt; i++){
        scanf("%s", order);
        getchar();
        
        if(strcmp(order, "push") == 0){
            scanf("%d", &num);
            getchar();
            push(&stack, num);
        }
        else if(strcmp(order, "pop") == 0)
            printf("%d\n", pop(&stack));
        else if(strcmp(order, "size") == 0)
            printf("%d\n", size(&stack));
        else if(strcmp(order, "empty") == 0)
            printf("%d\n", empty(&stack) == 0);
        else if(strcmp(order, "top") == 0)
            printf("%d\n", top(&stack));
    }
    
    return 0;
}

void push(Stack * pstack, int num){
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->num = num;
    
    newNode->next = pstack->head;
    pstack->head = newNode;
    pstack->count += 1;
}

int pop(Stack * pstack){
    if(!empty(pstack))
        return EOF;
    
    Node * delNode = pstack->head;
    int delNum = pstack->head->num;
    
    pstack->head = pstack->head->next;
    free(delNode);
    pstack->count -= 1;
    
    return delNum;
}

int size(Stack * pstack){
    return pstack->count;
}

int empty(Stack * pstack){
    if(pstack->head == NULL)
        return 0;
    else
        return 1;
}

int top(Stack * pstack){
    if(!empty(pstack))
        return EOF;
    
    return pstack->head->num;
}
