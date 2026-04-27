#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
	
typedef char Data;

typedef struct _node {
Data data;
struct _node *next;
struct _node *prev;
} Node;

typedef struct _SLinkedList {
Node *head;
Node *tail;
Node *cur;
int numOfData;
} StringLinkedList;

typedef StringLinkedList List;

void ListInit(List * list);
void LInsert(List * plist, Data data);
int LFirst(List * plist);
int LNext(List * plist, Data * pdata);
int LPrev(List * plist, Data * pdata);
int LRemove(List * plist);
void LFree(List * plist, Data * pdata);

int main() {
	List list;
	Data data;
	int count;

	scanf("%d", &count);
	getchar();
	
	for(int i=0; i<count; i++){
		char * tmp = (char *)malloc(sizeof(char) * 1000000);
		ListInit(&list);
		
		scanf("%s", tmp);
		getchar();

		for(int j=0; tmp[j] != '\0'; j++){
			switch(tmp[j]){
				case '<':
					LPrev(&list, &data);
					break;
				case '>':
					LNext(&list, &data);
					break;
				case '-':
					LRemove(&list);
					break;
				default:
					LInsert(&list, tmp[j]);
					break;
			}
		}
		free(tmp);
		
		LFirst(&list);
		while(LNext(&list, &data))
			printf("%c", data);
		printf("\n");

		LFree(&list, &data);
	}
	
 	return 0;
}

void ListInit(List * plist){
	plist->head = (Node *)malloc(sizeof(Node));
	plist->tail = (Node *)malloc(sizeof(Node));

	plist->head->prev = NULL;
    plist->head->next = plist->tail;
    plist->tail->next = NULL;
    plist->tail->prev = plist->head;
	plist->cur = plist->head;
}

int LFirst(List * plist){
    if(plist->head->next == plist->tail)
        return FALSE;
    
    plist->cur = plist->head;
    return TRUE;
}

int LNext(List * plist, Data * pdata){
    if(plist->cur->next == plist->tail)
        return FALSE;
    
    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    return TRUE;
}

int LPrev(List * plist, Data * pdata){
    if(plist->cur == plist->head)
        return FALSE;
    
    plist->cur = plist->cur->prev;
    *pdata = plist->cur->data;
    return TRUE;
}

void LInsert(List * plist, Data data){
	Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

	if(plist->head->next == plist->tail){
		newNode->prev = plist->tail->prev;
    	plist->tail->prev->next = newNode;
    	newNode->next = plist->tail;
    	plist->tail->prev = newNode;
    
    	plist->cur = plist->tail->prev;
	}
	else{
		newNode->next = plist->cur->next;
    	plist->cur->next->prev = newNode;
    	newNode->prev = plist->cur;
    	plist->cur->next = newNode;
    
  	    plist->cur = plist->cur->next;
	}
}

int LRemove(List * plist){
    if(plist->cur == plist->head)
        return FALSE;
    
    Node * rpos = plist->cur;
    
    plist->cur->prev->next = plist->cur->next;
    plist->cur->next->prev = plist->cur->prev;
    plist->cur = plist->cur->prev;
    
    free(rpos);
    
    return TRUE;
}

void LFree(List * plist, Data * pdata){
	LFirst(plist);
	while(LNext(plist, pdata))
		LRemove(plist);
}