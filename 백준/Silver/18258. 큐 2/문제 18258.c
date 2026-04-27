#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int front(Queue * pq);
int back(Queue * pq);

int main(void){
    Queue q;
    q.front = NULL;
    q.rear = NULL;
    q.count = 0;
    
    char order[6];
    int cnt, num;
    
    scanf("%d", &cnt);
    getchar();
    
    for(int i=0; i<cnt; i++){
        scanf("%s", order);
        getchar();
        
        if(strcmp(order, "push") == 0){
            scanf("%d", &num);
            getchar();
            push(&q, num);
        }
        else if(strcmp(order, "pop") == 0)
            printf("%d\n", pop(&q));
        else if(strcmp(order, "size") == 0)
            printf("%d\n", size(&q));
        else if(strcmp(order, "empty") == 0)
            printf("%d\n", empty(&q));
        else if(strcmp(order, "front") == 0)
            printf("%d\n", front(&q));
        else if(strcmp(order, "back") == 0)
            printf("%d\n", back(&q));
    }
    
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

int front(Queue * pq){
    if(empty(pq))
        return -1;
    
    return pq->front->num;
}

int back(Queue * pq){
    if(empty(pq))
        return -1;
    
    return pq->rear->num;
}

