#include <stdio.h>

#define LEN 10001

int main(void){
    int N;
    scanf("%d", &N);
    
    int arr[LEN] = {0};
    int num;
    for(int i=0; i<N; i++){
        scanf("%d", &num);
        arr[num]++;
    }
    
    for(int i=1; i<LEN; i++){
        for(int j=0; j<arr[i]; j++)
            printf("%d\n", i);
    }
    
    return 0;
}
