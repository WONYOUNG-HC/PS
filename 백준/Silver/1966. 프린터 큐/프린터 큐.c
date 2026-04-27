#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int pos;
    int ord;
    struct _node * next;
} Node;

typedef struct _queue{
    Node * front;
    Node * rear;
} Queue;

void enqueue(Queue * pq, int pos, int ord);
int peek_pos(Queue * pq);
int peek_ord(Queue * pq);
void dequeue(Queue * pq);
void endequeue(Queue * pq);

int main(void){
    int cnt;
    scanf("%d",&cnt);
    
    Queue qu;
    qu.front = NULL;
    qu.rear = NULL;
    
    int N, target, num;
    for(int i=0; i<cnt; i++){
        scanf("%d%d", &N, &target);
        
        int ordArr[10] = {0};
        for(int t=0; t<N; t++){
            scanf("%d", &num);
            enqueue(&qu, t, num);
            ordArr[num]++;
        }
        
        int j=0;
        while(1){
            for(int k=peek_ord(&qu); k<10; k++)
                if(ordArr[k] != 0)
                    while(peek_ord(&qu) < k)
                        endequeue(&qu);
            
            
            
            if(peek_pos(&qu) != target){
                ordArr[peek_ord(&qu)]--;
                dequeue(&qu);
                j++;
            }
            else
                break;
        }
        
        printf("%d\n", j+1);
        
        while(qu.front != NULL)
            dequeue(&qu);
    }
    
    return 0;
}

void enqueue(Queue * pq, int pos, int ord){
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->ord = ord;
    newNode->pos = pos;
    
    if(pq->rear == NULL)
        pq->front = newNode;
    else
        pq->rear->next = newNode;
    
    pq->rear = newNode;
    newNode->next = pq->front;
}

int peek_pos(Queue * pq){
    return pq->front->pos;
}

int peek_ord(Queue * pq){
    return pq->front->ord;
}

void dequeue(Queue * pq){
    Node * rnode = pq->front;
    
    if(pq->front == pq->rear){
        pq->front = NULL;
        pq->rear = NULL;
    }
    else{
        pq->front = pq->front->next;
        pq->rear->next = pq->front;
    }
    
    free(rnode);
}

void endequeue(Queue * pq){
    pq->rear = pq->front;
    pq->front = pq->rear->next;
}

