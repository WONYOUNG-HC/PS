#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _node{
    int num;
    struct _node * next;
} Node;

typedef struct _queue{
    Node * front;
    Node * rear;
    int count;
} Queue;

void push(Queue * pq, int num);
int pop(Queue * pq);
int size(Queue * pq);
int empty(Queue * pq);
int peek(Queue * pq);

int main(void){
    Queue q;
    q.front = NULL;
    q.rear = NULL;
    q.count = 0;
    
    int card;
    scanf("%d", &card);
    
    for(int i=1; i<=card; i++)
        push(&q, i);
    
    while(size(&q) != 1){
        pop(&q);
        
        if(size(&q) == 1)
            break;
        
        push(&q, pop(&q));
    }
    
    printf("%d\n", peek(&q));
    
    return 0;
}

void push(Queue * pq, int num){
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->num = num;
    newNode->next = NULL;
    
    if(empty(pq)){
        pq->front = newNode;
        pq->rear = newNode;
    }
    else{
        pq->rear->next = newNode;
        pq->rear = newNode;
    }
    
    pq->count += 1;
}

int pop(Queue * pq){
    if(empty(pq))
        return -1;
    
    Node * delNode = pq->front;
    int delNum = pq->front->num;
    
    pq->front = pq->front->next;
    
    free(delNode);
    pq->count -= 1;
    return delNum;
}

int size(Queue * pq){
    return pq->count;
}

int empty(Queue * pq){
    if(pq->front == NULL)
        return TRUE;
    else
        return FALSE;
}

int peek(Queue * pq){
    if(empty(pq))
        return -1;
    
    return pq->front->num;
}
