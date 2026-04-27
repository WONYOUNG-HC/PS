#include <stdio.h>
#include <ctype.h>

typedef struct _deque{
    int arr[100000];
    int head;
    int tail;
} Deque;

void reverse(Deque * dq);
void delete(Deque * dq);

int main(void){
    Deque dq;
    int cnt, len;
    char func[100001];
    
    scanf("%d", &cnt);
    getchar();
    
    for(int i=0; i<cnt; i++){
        scanf("%s%d", func, &len);
        getchar();
        
        char exp[len*6 + 3];
        scanf("%s", exp);
        getchar();
        
        dq.head = 0;
        dq.tail = len-1;
        
        int idx = 0;
        int tmp[3] = {0};
        for(int j=0, k=0; exp[j] != '\0'; j++){
            if(isdigit(exp[j])){
                tmp[k] = exp[j] - '0';
                k++;
            }
            else if(k > 0){
                if(k == 1)
                    dq.arr[idx++] = tmp[0];
                else if(k == 2)
                    dq.arr[idx++] = tmp[0]*10 + tmp[1];
                else if(k == 3)
                    dq.arr[idx++] = tmp[0]*100 + tmp[1]*10 + tmp[2];
                
                k = 0;
                tmp[0] = 0;
                tmp[1] = 0;
                tmp[2] = 0;
            }
        }
        
        for(int j=0; func[j] != '\0'; j++)
            switch(func[j]){
                case 'R':
                    reverse(&dq);
                    break;
                case 'D':
                    delete(&dq);
                    break;
            }
        
        if(dq.head == -1)
            printf("error\n");
        else if(dq.tail == -1)
            printf("[]\n");
        else if(dq.head <= dq.tail){
            printf("[");
            for(int j=dq.head; j<dq.tail; j++)
                printf("%d,", dq.arr[j]);
            printf("%d]\n", dq.arr[dq.tail]);
        }
        else if(dq.head > dq.tail){
            printf("[");
            for(int j=dq.head; j>dq.tail; j--)
                printf("%d,", dq.arr[j]);
            printf("%d]\n", dq.arr[dq.tail]);
        }
    }
    
    return 0;
}

void reverse(Deque * pd){
    if(pd->tail == -1)
        return;
    
    int tmp = pd->head;
    pd->head = pd->tail;
    pd->tail = tmp;
}

void delete(Deque * pd){
    if(pd->head == -1)
        return;
    
    if(pd->tail == -1){
        pd->head = -1;
        return;
    }
    
    if(pd->head == pd->tail){
        pd->tail = -1;
        return;
    }
    
    if(pd->head < pd->tail)
        pd->head += 1;
    else if(pd->head > pd->tail)
        pd->head -= 1;
}
