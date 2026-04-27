#include <stdio.h>

typedef struct _heap{
    int arr[1501];
    int numOfData;
} Heap;

void insert(Heap * ph, int num);
int delete(Heap * ph);

int main(void){
    int N;
    scanf("%d", &N);
    
    Heap h[N];
    int num;
    
    for(int i=0; i<N; i++){
        h[i].numOfData = 0;
        
        for(int j=0; j<N; j++){
            scanf("%d", &num);
            insert(&h[i], num);
        }
    }
    
    for(int i=0; i<N; i++){
        int idx = N-1;
        while(h[idx].arr[1] < h[idx-1].arr[1])
            idx--;
        
        if(i != N-1)
            delete(&h[idx]);
        else
            printf("%d\n", h[idx].arr[1]);
        
        while(idx != 0){
            if(h[idx].arr[1] < h[idx-1].arr[1]){
                int tmp = delete(&h[idx-1]);
                insert(&h[idx-1], delete(&h[idx]));
                insert(&h[idx], tmp);
            }
            idx--;
        }
    }
     
    return 0;
}

int getParentIdx(int idx){
    return idx/2;
}

int getLChildIdx(int idx){
    return idx*2;
}

int getRChildIdx(int idx){
    return idx*2 + 1;
}

int compare(int d1, int d2){
    return d1 - d2;
}

int getHipriChildIdx(Heap * ph, int idx){
    if(getLChildIdx(idx) > ph->numOfData)
        return 0;
    else if(getLChildIdx(idx) == ph->numOfData)
        return getLChildIdx(idx);
    else{
        if(compare(ph->arr[getLChildIdx(idx)], ph->arr[getRChildIdx(idx)]) > 0)
            return getLChildIdx(idx);
        else
            return getRChildIdx(idx);
    }
}

void insert(Heap * ph, int num){
    int idx = ph->numOfData + 1;
    
    while(idx != 1){
        if(compare(num, ph->arr[getParentIdx(idx)]) > 0){
            ph->arr[idx] = ph->arr[getParentIdx(idx)];
            idx = getParentIdx(idx);
        }
        else
            break;
    }
    
    ph->arr[idx] = num;
    ph->numOfData += 1;
}

int delete(Heap * ph){
    int rnum = ph->arr[1];
    int lastnum = ph->arr[ph->numOfData];
    int parentIdx = 1;
    int childIdx;
    
    while(childIdx = getHipriChildIdx(ph, parentIdx)){
        if(compare(lastnum, ph->arr[childIdx]) >= 0)
            break;
        
        ph->arr[parentIdx] = ph->arr[childIdx];
        parentIdx = childIdx;
    }
    
    ph->arr[parentIdx] = lastnum;
    ph->numOfData -= 1;
    return rnum;
}
