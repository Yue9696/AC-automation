#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

queue* qInit(queue *Head){
	Head = NULL;
	return Head;
}

queue* qPush(queue *Head,int num){
	queue *new = (queue*)malloc(sizeof(queue));
	new->num = num;
	if(Head == NULL){
		Head = new;
		new->next = NULL;
	}
	else{
		queue *p = Head;
		while(p->next != NULL){
			p = p->next;
		}
		p->next = new;
		new->next = NULL;
	}
	return Head;
}

queue* qPop(queue *Head){
	queue *p = Head;
	Head = p->next;
	free(p);
	p = NULL;
	return Head;
}

int qBack(queue *Head){
	if(qEmpty(Head)){
		printf("empty queue!");
		return 0;
	}
	else{
		queue *p = Head;
		while(p->next != NULL) p = p->next;
		return p->num;
	}
}

int qFront(queue *Head){
	if(qEmpty(Head)){
		printf("empty queue");
		return 0;
	}
	else return Head->num;
}

int qEmpty(queue *Head){ //enpty->true;
	if(Head == NULL) return 1;
	else return 0;
}

int qSize(queue *Head){
	int size = 0;
	queue *temp = Head;
	while(temp != NULL){
		size++;
		temp = temp->next;
	}
	return size;
}

void qPrint(queue *Head){
	if(Head == NULL) printf("empty queue");
	else{
		queue *temp = Head;
		while(temp != NULL){
			printf("%d ",temp->num);
			temp = temp->next;
		}
	}
}
void qClear(queue *Head){
	queue *p = Head;
	while(p != NULL){
		queue *temp = p->next;
		free(p);
		p = temp;
	}
}

queue* qSearch(queue *Head,int i){
	queue *temp = Head;
	while(temp != NULL){
		if(temp->num == i) return temp;
		temp = temp->next;
	}
	return NULL;
}

queue* qDelete(queue *Head,queue *q){
	if(q == Head){
		Head = Head->next;
		return Head;
	}
	else{
		queue *temp = Head;
		while(temp->next != q)temp = temp->next;
		temp->next = q->next;
		free(q);
		q = NULL;
		return Head;
	}
}

queue* qExclude(queue* q1,queue* q2){
	queue *temp = q2;
	queue *fg;
	while(temp != NULL){
		fg = qSearch(q1,temp->num);
		if(fg != NULL){
			q1 = qDelete(q1,fg);
		}
		temp = temp->next;
	}
	return q1;
}

queue* qAdd(queue *Head,int i){
	queue *temp = Head;
	while(temp != NULL){
		temp->num += i;
		temp = temp->next;
	}
	return Head;
}




