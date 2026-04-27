#include <stdio.h>
#include <stdlib.h>

typedef struct _pos{
    int x;
    int y;
} Pos;

void sort(Pos p[], int left, int right);

int main(void){
    int cnt, x, y;
    
    scanf("%d", &cnt);
    
    Pos p[cnt];
    for(int i=0; i<cnt; i++){
        scanf("%d%d", &x, &y);
        p[i].x = x;
        p[i].y = y;
    }
    
    sort(p, 0, cnt-1);
    
    for(int i=0; i<cnt; i++)
        printf("%d %d\n", p[i].x, p[i].y);
    
    return 0;
}

int compare(Pos p1, Pos p2){
    if(p1.y == p2.y)
        return p2.x - p1.x;
    
    return p2.y - p1.y;
}

void merge(Pos p[], int left, int mid, int right){
    int fIdx = left;
    int rIdx = mid+1;
    
    Pos * sort = (Pos *)malloc(sizeof(Pos)*(right+1));
    int sIdx = left;
    
    while(fIdx <= mid && rIdx <= right){
        if(compare(p[fIdx], p[rIdx]) > 0)
            sort[sIdx++] = p[fIdx++];
        else
            sort[sIdx++] = p[rIdx++];
    }
    
    if(fIdx > mid)
        for(int i=rIdx; i<=right; i++)
            sort[sIdx++] = p[i];
    else
        for(int i=fIdx; i<=mid; i++)
            sort[sIdx++] = p[i];
    
    for(int i=left; i<=right; i++)
        p[i] = sort[i];
    
    free(sort);
}

void sort(Pos p[], int left, int right){
    int mid;
    
    if(left < right){
        mid = (left+right) / 2;
        
        sort(p, left, mid);
        sort(p, mid+1, right);
        
        merge(p, left, mid, right);
    }
}
