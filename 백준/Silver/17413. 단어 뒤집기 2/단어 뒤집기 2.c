#include <stdio.h>

int main(void){
    int stack[100000];
    int idx = -1;
    
    char string[100001];
    scanf("%[^\n]s", string);
    
    int i=0;
    while(string[i] != '\0'){
        if(string[i] == '<'){
            while(string[i] != '>')
                printf("%c", string[i++]);
            printf("%c", string[i++]);
        }
        else if(string[i] == ' ')
            printf("%c", string[i++]);
        else{
            while(string[i] != ' ' && string[i] != '\0' && string[i] != '<')
                stack[++idx] = string[i++];
            
            while(idx != -1)
                printf("%c", stack[idx--]);
            
        }
    }
    
    return 0;
}
