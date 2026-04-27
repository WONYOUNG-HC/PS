#include <stdio.h>

#define STACK_LEN 100000

int main(void){
    int arr[STACK_LEN];
    int idx=0;
    int count, num;
    
    scanf("%d", &count);
    
    for(int i=0; i<count; i++){
        scanf("%d", &num);
        
        if(num == 0)
            idx --;
        else{
            arr[idx] = num;
            idx++;
        }
    }
    
    unsigned int sum=0;
    
    for(int i=0; i<idx; i++)
        sum += arr[i];
    
    if(idx == 0)
        sum = 0;
    
    printf("%u\n", sum);
    
    return 0;
}
