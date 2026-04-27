#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    int num;
    int pos;
} Data;

typedef struct _node{
    Data data;
    struct _node * next;
    struct _node * before;
} Node;

typedef struct _deque{
    Data data;
    Node * head;
    Node * tail;
} Deque;

void DequeInit(Deque * pd);
void AppendFront(Deque * pd, Data data);
Data PopFront(Deque * pd);
Data PopRear(Deque * pd);
Data PeekFront(Deque * pd);
Data PeekRear(Deque * pd);
int IsEmpty(Deque * pd);

int main(){
    int n, l;
    scanf("%d%d", &n, &l);

    int arr[n];
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    Deque dq;
    DequeInit(&dq);

    for(int i=0; i<n; i++){
        if(!IsEmpty(&dq) && i == PeekRear(&dq).pos + l)
            PopRear(&dq);

        while(!IsEmpty(&dq) && PeekFront(&dq).num > arr[i])
            PopFront(&dq);

        Data data = {arr[i], i};
        AppendFront(&dq, data);

        printf("%d ", PeekRear(&dq).num);
    }
    printf("\n");

    return 0;
}

void DequeInit(Deque * pd){
    pd->head = NULL;
    pd->tail = NULL;
}

void AppendFront(Deque * pd, Data data){
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if(pd->head == NULL){
        pd->head = newNode;
        newNode->before = NULL;
    }
    else{
        pd->tail->next = newNode;
        newNode->before = pd->tail;
    }

    pd->tail = newNode;
    newNode->next = NULL;
}

Data PopFront(Deque * pd){
    Node * rnode = pd->tail;
    Data rdata = pd->tail->data;

    if(pd->head == pd->tail){
        pd->head = NULL;
        pd->tail = NULL;
    }
    else{
        pd->tail = pd->tail->before;
        pd->tail->next = NULL;
    }

    free(rnode);
    return rdata;
}

Data PopRear(Deque * pd){
    Node * rnode = pd->head;
    Data rdata = pd->head->data;

    if(pd->head == pd->tail){
        pd->head = NULL;
        pd->tail = NULL;
    }
    else{
        pd->head = pd->head->next;
        pd->head->before = NULL;
    }

    free(rnode);
    return rdata;
}

Data PeekFront(Deque * pd){
    return pd->tail->data;
}

Data PeekRear(Deque * pd){
    return pd->head->data;
}

int IsEmpty(Deque * pd){
    if(pd->head == NULL)
        return TRUE;
    else
        return FALSE;
}