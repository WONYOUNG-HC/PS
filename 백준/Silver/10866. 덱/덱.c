#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct _node{
    int num;
    struct _node * next;
    struct _node * prev;
} Node;

typedef struct _deque{
    Node * front;
    Node * back;
    int count;
} Deque;

void push_front(Deque * pd, int num);
void push_back(Deque * pd, int num);
int pop_front(Deque * pd);
int pop_back(Deque * pd);
int size(Deque * pd);
int empty(Deque * pd);
int front(Deque * pd);
int back(Deque * pd);

int main(void){
    Deque dq;
    dq.count = 0;
    dq.front = NULL;
    dq.back = NULL;
    
    char order[11];
    int cnt, num;
    
    scanf("%d", &cnt);
    getchar();
    
    for(int i=0; i<cnt; i++){
        scanf("%s", order);
        getchar();
        
        if(strcmp(order, "push_front") == 0){
            scanf("%d", &num);
            getchar();
            push_front(&dq, num);
        }
        else if(strcmp(order, "push_back") == 0){
            scanf("%d", &num);
            getchar();
            push_back(&dq, num);
        }
        else if(strcmp(order, "pop_front") == 0)
            printf("%d\n", pop_front(&dq));
        else if(strcmp(order, "pop_back") == 0)
            printf("%d\n", pop_back(&dq));
        else if(strcmp(order, "size") == 0)
            printf("%d\n", size(&dq));
        else if(strcmp(order, "empty") == 0)
            printf("%d\n", empty(&dq));
        else if(strcmp(order, "front") == 0)
            printf("%d\n", front(&dq));
        else if(strcmp(order, "back") == 0)
            printf("%d\n", back(&dq));
    }
    
    return 0;
}

void push_front(Deque * pd, int num){
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->num = num;
    
    newNode->prev = pd->front;
    newNode->next = NULL;
    
    if(empty(pd))
        pd->back = newNode;
    else
        pd->front->next = newNode;
    
    pd->front = newNode;
    
    pd->count += 1;
}

void push_back(Deque * pd, int num){
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->num = num;
    
    newNode->next = pd->back;
    newNode->prev = NULL;
    
    if(empty(pd))
        pd->front = newNode;
    else
        pd->back->prev = newNode;
    
    pd->back = newNode;
    
    pd->count += 1;
}

int pop_front(Deque * pd){
    if(empty(pd))
        return -1;
    
    Node * delNode = pd->front;
    int delNum = pd->front->num;
    
    pd->front = pd->front->prev;
    free(delNode);
    pd->count -= 1;
    
    if(pd->front == NULL)
        pd->back = NULL;
    else
        pd->front->next = NULL;
    
    return delNum;
}

int pop_back(Deque * pd){
    if(empty(pd))
        return -1;
    
    Node * delNode = pd->back;
    int delNum = pd->back->num;
    
    pd->back = pd->back->next;
    free(delNode);
    pd->count -= 1;
    
    if(pd->back == NULL)
        pd->front = NULL;
    else
        pd->back->prev = NULL;
    
    return delNum;
}

int size(Deque * pd){
    return pd->count;
}

int empty(Deque * pd){
    if(pd->front == NULL)
        return TRUE;
    else
        return FALSE;
}

int front(Deque * pd){
    if(empty(pd))
        return -1;
    
    return pd->front->num;
}

int back(Deque * pd){
    if(empty(pd))
        return -1;
    
    return pd->back->num;
}