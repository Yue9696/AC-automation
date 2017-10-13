#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef struct queue{
	int num;
	struct queue *next;
}queue;


queue* qInit(queue *Head);
queue* qPush(queue *Head,int num);
queue* qPop(queue *Head);
queue* qDelete(queue *Head, queue *q);
int qFront(queue *Head);
int qBack(queue *Head);
int qEmpty(queue *Head); //empty->true;
int qSize(queue *Head);
void qPrint(queue *Head);
void qClear(queue *Head);
queue* qSearch(queue *Head,int i);
queue* qExclude(queue* q1,queue* q2);//exclude q2 from q1;
queue* qAdd(queue *Head,int i);//each node add i;

#endif

