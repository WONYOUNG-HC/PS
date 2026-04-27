#include <stdio.h>

typedef struct _heap{
    int numOfData;
    int heapArr[1000000];
} Heap;

int compare(int d1, int d2);
int getLeftIdx(int idx);
int getRightIdx(int idx);
int getParentIdx(int idx);
int getHighIdx(Heap * ph, int idx);

void insert(Heap * ph, int num);
int delete(Heap * ph);

int main(void){
    Heap heap;
    heap.numOfData = 0;
    int cnt, num;
    
    scanf("%d", &cnt);
    
    for(int i=0; i<cnt; i++){
        scanf("%d", &num);
        insert(&heap, num);
    }
    
    for(int i=0; i<cnt; i++)
        printf("%d\n", delete(&heap));
    
    return 0;
}

int compare(int d1, int d2){
    return d2 - d1;
}

int getLeftIdx(int idx){
    return idx * 2;
}

int getRightIdx(int idx){
    return idx * 2 + 1;
}

int getParentIdx(int idx){
    return idx / 2;
}

int getHighIdx(Heap * ph, int idx){
    if(getLeftIdx(idx) > ph->numOfData)
        return 0;
    else if(getLeftIdx(idx) == ph->numOfData)
        return getLeftIdx(idx);
    else{
        if(compare(ph->heapArr[getLeftIdx(idx)], ph->heapArr[getRightIdx(idx)]) < 0)
            return getRightIdx(idx);
        else
            return getLeftIdx(idx);
    }
}

void insert(Heap * ph, int num){
    int idx = ph->numOfData + 1;
    
    while(idx != 1){
        if(compare(num, ph->heapArr[getParentIdx(idx)]) > 0){
            ph->heapArr[idx] = ph->heapArr[getParentIdx(idx)];
            idx = getParentIdx(idx);
        }
        else
            break;
    }
    
    ph->heapArr[idx] = num;
    ph->numOfData += 1;
}

int delete(Heap * ph){
    int rnum = ph->heapArr[1];
    int lastnum = ph->heapArr[ph->numOfData];
    
    int parentIdx = 1;
    int childIdx;
    
    while(childIdx = getHighIdx(ph, parentIdx)){
        if(compare(lastnum, ph->heapArr[childIdx]) >= 0)
            break;
        
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;
    }
    
    ph->heapArr[parentIdx] = lastnum;
    ph->numOfData -= 1;
    return rnum;
}
