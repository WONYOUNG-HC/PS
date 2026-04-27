#include <stdio.h>

int main(void){
    int cnt;
    scanf("%d", &cnt);
    getchar();
    
    char stack[100001];
    int idx = -1;
    
    int nice = 0;
    for(int i=0; i<cnt; i++){
        char string[100001];
        scanf("%s", string);
        getchar();
        
        for(int j=0; string[j] != '\0'; j++){
            switch(string[j]){
                case 'A':
                    if(idx == -1)
                        stack[++idx] = 'A';
                    else{
                        if(stack[idx] == 'A')
                            idx--;
                        else
                            stack[++idx] = 'A';
                    }
                    break;
                case 'B':
                    if(idx == -1)
                        stack[++idx] = 'B';
                    else{
                        if(stack[idx] ==  'B')
                            idx--;
                        else
                            stack[++idx] = 'B';
                    }
                    break;
            }
        }
        
        if(idx == -1)
            nice++;
        else
            idx = -1;
    }
    
    printf("%d\n", nice);
    
    return 0;
}
