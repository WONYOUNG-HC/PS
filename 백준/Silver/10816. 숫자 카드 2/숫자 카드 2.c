#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int left, int right);
int lower(int arr[], int first, int last, int target);
int upper(int arr[], int first, int last, int target);

int main(void){
    int N;
    scanf("%d", &N);
    
    int arr[N];
    for(int i=0; i<N; i++)
        scanf("%d", &arr[i]);
    sort(arr, 0, N-1);
    
    int M;
    scanf("%d", &M);
    
    int target, low, up;
    for(int i=0; i<M; i++){
        scanf("%d", &target);
        
        low = lower(arr, 0, N-1, target);
        up = upper(arr, 0, N-1, target);
        
        if(low == up){
            if(arr[up] == target)
                printf("1 ");
            else
                printf("0 ");
        }
        else{
            if(up == N-1 && arr[up] == target)
                printf("%d ", up - low + 1);
            else
                printf("%d ", up - low);
        }
    }
    
    printf("\n");
    
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

int lower(int arr[], int first, int last, int target){
    while(first < last){
        int mid = (first + last) / 2;
        
        if(target > arr[mid])
            first = mid + 1;
        else
            last = mid;
    }
    
    return last;
}

int upper(int arr[], int first, int last, int target){
    while(first < last){
        int mid = (first + last) / 2;
        
        if(target < arr[mid])
            last = mid;
        else
            first = mid + 1;
    }
    
    return last;
}
