#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _person{
    char name[101];
    int age;
    int priority;
} Person;

void sort(Person p[], int left, int right);

int main(void){
    int cnt, age;
    char name[101];
    
    scanf("%d", &cnt);
    
    Person p[cnt];
    for(int i=0; i<cnt; i++){
        scanf("%d", &age);
        getchar();
        scanf("%s", name);
        
        p[i].age = age;
        p[i].priority = i;
        strcpy(p[i].name, name);
    }
    
    sort(p, 0, cnt-1);
    
    for(int i=0; i<cnt; i++)
        printf("%d %s\n", p[i].age, p[i].name);
    
    return 0;
}

int compare(Person p1, Person p2){
    if(p1.age == p2.age)
        return p2.priority - p1.priority;
    
    return p2.age - p1.age;
}

void merge(Person p[], int left, int mid, int right){
    int fIdx = left;
    int rIdx = mid+1;
    
    Person * sort = (Person *)malloc(sizeof(Person)*(right+1));
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

void sort(Person p[], int left, int right){
    int mid;
    
    if(left < right){
        mid = (left+right) / 2;
        
        sort(p, left, mid);
        sort(p, mid+1, right);
        
        merge(p, left, mid, right);
    }
}
