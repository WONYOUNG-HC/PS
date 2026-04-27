#include <stdio.h>
#include <stdlib.h>

void buildStation(int arr[][1000001], int num, int new);
void clearStation(int arr[][1000001], int num);

int main(void){
    int arr[2][1000001];
    int N, M;
    scanf("%d%d", &N, &M);
    
    int num, new;
    int * tmp = (int *)malloc(sizeof(int)*N);
    for(int i=0; i<N; i++){
        scanf("%d", &num);
        tmp[i] = num;
    }
    getchar();
    
    arr[1][tmp[0]] = tmp[1];
    for(int i=1; i<N-1; i++){
        arr[0][tmp[i]] = tmp[i-1];
        arr[1][tmp[i]] = tmp[i+1];
    }
    arr[0][tmp[N-1]] = tmp[N-2];
    
    arr[0][tmp[0]] = tmp[N-1];
    arr[1][tmp[N-1]] = tmp[0];
    free(tmp);
    
    char order, pos;
    for(int i=0; i<M; i++){
        scanf("%c%c", &order, &pos);
        scanf("%d", &num);
        
        switch(order){
            case 'B':
                scanf("%d", &new);
                
                switch(pos){
                    case 'N':
                        printf("%d\n", arr[1][num]);
                        buildStation(arr, num, new);
                        break;
                    case 'P':
                        printf("%d\n", arr[0][num]);
                        buildStation(arr, arr[0][num], new);
                        break;
                }
                break;
                
            case 'C':
                switch(pos){
                    case 'N':
                        printf("%d\n", arr[1][num]);
                        clearStation(arr, arr[1][num]);
                        break;
                    case 'P':
                        printf("%d\n", arr[0][num]);
                        clearStation(arr, arr[0][num]);
                        break;
                }
                break;
        }
        
        getchar();
    }
        
    return 0;
}

void buildStation(int arr[][1000001], int num, int new){
    int next = arr[1][num];
    
    arr[1][num] = new;
    arr[0][new] = num;
    
    arr[1][new] = next;
    arr[0][next] = new;
}

void clearStation(int arr[][1000001], int num){
    arr[1][arr[0][num]] = arr[1][num];
    arr[0][arr[1][num]] = arr[0][num];
    
    arr[1][num] = 0;
    arr[0][num] = 0;
}
