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
} StringLinkedList;

typedef StringLinkedList List;

int LFirst(List * plist);
int LNext(List * plist, Data * pdata);
int LPrev(List * plist, Data * pdata);

int main() {
	List list;
	Data data;
	int count;
	char sel, c;

	list.head = (Node *)malloc(sizeof(Node));
	list.tail = (Node *)malloc(sizeof(Node));

	list.head->prev = NULL;
    list.head->next = list.tail;
    list.tail->next = NULL;
    list.tail->prev = list.head;

	char * tmp = (char *)malloc(sizeof(char) * 100000);
  	scanf("%s", tmp);
	getchar();
	
	for(int i=0; tmp[i] != '\0'; i++){
		Node * newNode = (Node *)malloc(sizeof(Node));
    	newNode->data = tmp[i];
    	
		newNode->prev = list.tail->prev;
    	list.tail->prev->next = newNode;
    	newNode->next = list.tail;
		list.tail->prev = newNode;
		list.cur = list.tail->prev;
	}
	free(tmp);

	scanf("%d", &count);
	getchar();
	for(int i=0; i<count; i++){
		sel = getchar();
		getchar();
		
		switch(sel){
			case 'L':
				LPrev(&list, &data);
				break;
			case 'D':
				LNext(&list, &data);
				break;
			case 'B':
				if(list.cur == list.head)
					break;
				
				Node * rpos = list.cur;
				list.cur->prev->next = list.cur->next;
    			list.cur->next->prev = list.cur->prev;
    			list.cur = list.cur->prev;
    
    			free(rpos);
				break;
			case 'P':
				c = getchar();
				getchar();
				    
				Node * newNode = (Node *)malloc(sizeof(Node));
    			newNode->data = c;
    
    			newNode->next = list.cur->next;
    			list.cur->next->prev = newNode;
    			newNode->prev = list.cur;
    			list.cur->next = newNode;
				list.cur = list.cur->next;
			break;
		}
	}

	list.cur = list.head;

	while(LNext(&list, &data))
		printf("%c", data);
	printf("\n");
	
 	return 0;
}

int LFirst(List * plist){
    if(plist->head->next == plist->tail)
        return FALSE;
    
    plist->cur = plist->tail->prev;
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