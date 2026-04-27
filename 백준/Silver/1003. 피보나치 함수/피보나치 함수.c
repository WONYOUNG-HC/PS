#include <stdio.h>

int main(){
    int t;
    scanf("%d",&t);

    long long count_zero[41];
    long long count_one[41];
    count_zero[0]=1;
    count_zero[1]=0;
    count_one[1]=1;
    count_one[0]=0;
    for (int i=2; i<41;i++){
        count_zero[i]=count_zero[i-1]+count_zero[i-2];
        count_one[i]=count_one[i-1]+count_one[i-2];
    }
    for (int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        printf("%lld %lld\n",count_zero[n],count_one[n]);
    }
    return 0;
}