#include <stdio.h>
#define LEN 100000

typedef struct _stack{
    int stackArr[LEN];
    int topidx;
} Stack;

void SPush(Stack * pstack, int data);
int SPop(Stack * pstack);
int SPeek(Stack * pstack);

int main(void){
    int trg[LEN], asc[LEN+1];
    char prt[LEN*2+1];
    int cnt, num;
    Stack stack;
    stack.topidx = -1;
    
    scanf("%d", &cnt);
    
    for(int i=0; i<cnt; i++){
        scanf("%d", &num);
        trg[i] = num;
        asc[i] = i+1;
    }
    asc[cnt] = cnt+1;
    
    int trgIdx=0, ascIdx=0, prtIdx=0;
    for(int i=0; i<cnt*2; i++){
        if(asc[ascIdx] <= trg[trgIdx]){
            SPush(&stack, asc[ascIdx]);
            ascIdx++;
            prt[prtIdx] = '+';
            prtIdx++;
        }
        else{
            if(SPeek(&stack) == trg[trgIdx]){
                SPop(&stack);
                trgIdx++;
                prt[prtIdx] = '-';
                prtIdx++;
            }
            else{
                printf("NO\n");
                return 0;
            }
        }
    }
    
    for(int i=0; i<cnt*2; i++)
        printf("%c\n", prt[i]);
    
    return 0;
}

void SPush(Stack * pstack, int data)
{
    pstack->topidx += 1;
    pstack->stackArr[pstack->topidx] = data;
}

int SPop(Stack * pstack)
{
    int rIdx;
    
    rIdx = pstack->topidx;
    pstack->topidx -= 1;

    return pstack->stackArr[rIdx];
}

int SPeek(Stack * pstack)
{
    return pstack->stackArr[pstack->topidx];
}
