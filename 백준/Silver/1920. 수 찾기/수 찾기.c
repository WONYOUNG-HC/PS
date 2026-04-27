#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int left, int right);
int search(int arr[], int first, int last, int target);

int main(void){
    int N;
    scanf("%d", &N);
    
    int arr[N];
    for(int i=0; i<N; i++)
        scanf("%d", &arr[i]);
    sort(arr, 0, N-1);
    
    int M;
    scanf("%d", &M);
    
    int target;
    for(int i=0; i<M; i++){
        scanf("%d", &target);
        
        if(search(arr, 0, N-1, target) == -1)
            printf("0\n");
        else
            printf("1\n");
    }
    
    return 0;
}

void merge(int arr[], int left, int mid, int right){
    int fidx = left;
    int ridx = mid+1;
    
    int * sortArr = (int *)malloc(sizeof(int)*(right+1));
    int sidx = left;
    
    while(fidx <= mid && ridx <= right){
        if(arr[fidx] <= arr[ridx])
            sortArr[sidx++] = arr[fidx++];
        else
            sortArr[sidx++] = arr[ridx++];
    }
    
    if(fidx > mid)
        for(int i=ridx; i<=right; i++)
            sortArr[sidx++] = arr[i];
    else
        for(int i=fidx; i<=mid; i++)
            sortArr[sidx++] = arr[i];
    
    for(int i=left; i<=right; i++)
        arr[i] = sortArr[i];
    
    free(sortArr);
}

void sort(int arr[], int left, int right){
    int mid;
    
    if(left < right){
        mid = (left + right) / 2;
        
        sort(arr, left, mid);
        sort(arr, mid+1, right);
        
        merge(arr, left, mid, right);
    }
}

int search(int arr[], int first, int last, int target){
    int mid;
    if(first > last)
        return -1;
    
    mid = (first+last) / 2;
    
    if(arr[mid] == target)
        return mid;
    else if(target < arr[mid])
        return search(arr, first, mid-1, target);
    else
        return search(arr, mid+1, last, target);
}
