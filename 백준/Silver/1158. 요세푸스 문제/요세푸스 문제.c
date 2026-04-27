#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct _node{
    Data data;
    struct _node * next;
} Node;

typedef struct _CLL{
    Node * tail;
    Node * cur;
    Node * before;
} List;

int main(void){
    List list;
    int n, k;
    
    list.tail = NULL;
    list.cur = NULL;
    list.before = NULL;
    
    scanf("%d %d", &n, &k);
    
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = 1;
    list.tail = newNode;
    newNode->next = newNode;
    
    for(int i=2; i<=n; i++){
        Node * newNode = (Node *)malloc(sizeof(Node));
        newNode->data = i;
        
        newNode->next = list.tail->next;
        list.tail->next = newNode;
        list.tail = newNode;
    }
    
    list.cur = list.tail;
    list.before = list.tail;
    
    printf("<");
    for(int i=0; i<n-1; i++){
        for(int j=0; j<k; j++){
            list.before = list.cur;
            list.cur = list.cur->next;
        }
        printf("%d, ", list.cur->data);
        Node * rpos = list.cur;
        list.before->next = list.cur->next;
        list.cur = list.before;
        free(rpos);
    }
    printf("%d>\n", list.cur->data);
    free(list.cur);
    
    return 0;
}
