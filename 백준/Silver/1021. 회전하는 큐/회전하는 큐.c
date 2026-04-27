#include <stdio.h>

typedef struct _queue{
    int arr[50];
    int tail;
    int cur;
} Queue;

void next(Queue * pq);
void prev(Queue * pq);
void delete(Queue * pq);

int main(void){
    Queue q;
    int len, cnt, target, result=0;
    
    scanf("%d%d", &len, &cnt);
    
    for(int i=0; i<len; i++){
        q.arr[i] = i+1;
    }
    
    q.tail = len-1;
    q.cur = 0;
    
    for(int i=0; i<cnt; i++){
        scanf("%d", &target);
        
        int tmp_idx, n_count = 0, p_count = 0;
        tmp_idx = q.cur;
        
        while(q.arr[q.cur] != target){
            next(&q);
            n_count++;
        }
        q.cur = tmp_idx;
        while(q.arr[q.cur] != target){
            prev(&q);
            p_count++;
        }
        
        if(n_count > p_count)
            result += p_count;
        else
            result += n_count;
        
        delete(&q);
    }
    
    printf("%d\n", result);
    
    return 0;
}

void next(Queue * pq){
    if(pq->cur == pq->tail)
        pq->cur = 0;
    else
        pq->cur += 1;
}

void prev(Queue * pq){
    if(pq->cur == 0)
        pq->cur = pq->tail;
    else
        pq->cur -= 1;
}

void delete(Queue * pq){
    for(int i=pq->cur; i<pq->tail; i++)
        pq->arr[i] = pq->arr[i+1];
    
    pq->tail -= 1;
    if(pq->cur > pq->tail)
        pq->cur = 0;
}
