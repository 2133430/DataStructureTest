#include <iostream>
#include <malloc.h> 
#include <stdlib.h>
using namespace std;
#define maxsize 100 
#define ElemType int
#define Error -1
#define Success 0
typedef struct Queue{
	ElemType front,rear;
	ElemType data[maxsize];
}Queue;

typedef struct LinkQueue{
	struct LQNode* front;
	struct LQNode* rear;
}LinkQueue;

typedef struct LQNode{
	ElemType data;
	struct LQNode* next;
}LQNode;
//initial the queue
void initQueue(Queue &q){
	q.front = 0;
	q.rear = 0;
}
//in queue
ElemType inQueue(Queue &q, ElemType elem){
	//check whether the queue is full
	if((q.rear+1)%maxsize==q.front){
		return Error;
	}
	q.rear = (q.rear+1)%maxsize;
	q.data[q.rear]=elem;
	return Success;
}
//out queue
ElemType outQueue(Queue &q, ElemType &elem){
	//check whether the queue is empty
	if(q.rear==q.front){//###############
		return Error;
	}
	q.front = (q.front+1)%maxsize;
	elem = q.data[q.front];
	return Success;
}
//intial the link queue
void initLinkQueue(LinkQueue *& lq){
	lq = (LinkQueue*)malloc(sizeof(LinkQueue));
	lq->front = NULL;
	lq->rear = NULL;
}
//in queue
ElemType inLinkQueue(LinkQueue* lq,ElemType elem){
	LQNode *node;
	node = (LQNode*)malloc(sizeof(LQNode));
	node->data = elem;
	node->next =NULL;//##########
	
	//complex
	if(lq->rear==NULL){
		lq->front = node;
		lq->rear = node;
	}
	else{//##### lq->rear is the LQNode pointer by lq.rear
		lq->rear->next = node;
		lq->rear = node;
		
	}
	return Success;
	
}
//outQueue
ElemType outLinkQueue (LinkQueue * lq, ElemType &elem){
	LQNode* node;
	//the queue is empty
	if(lq->front = NULL){
		return Error;
	}
	else{
		node = lq->front;
	}
	
	elem = node->data;
	//the node is the only node in queue
	if(lq->front==lq->rear){
		lq->front = NULL;
		lq->rear =NULL;
	}
	else{
		lq->front = lq->front->next; 
	}
	free(node);
	return Success;
}

int main(){
	int elem = rand()%100;
	//normal queue without typedef
	/*start
	int que[maxsize];
	int front=0,rear=0;
	//in queue
	rear =(rear+1)%maxsize;
	que[rear] = elem;
	cout<<"the elem is: "<<elem<<"\n";
	//out queue
	front = (front+1)%maxsize;
	elem = que[front];
	cout<<"the elem in queue is: "<<elem<<"\n";
	
	end*/
	//normal queue using data structure
	/*start*
	Queue q;
	initQueue(q);
	elem = rand()%10 + rand()%100;
	cout<<"the elem is: "<<elem<<"\n";
	inQueue(q,elem);
	outQueue(q,elem);
	cout<<"the elem in queue is: "<<elem<<"\n";
	*end*/
	//Link Queue
	/*start*/
	elem = rand()%10 + rand()%100;
	LinkQueue* lq;
	initLinkQueue(lq);
	cout<<"the elem is: "<<elem<<"\n";
	inLinkQueue(lq,elem); 
	outLinkQueue(lq,elem);
	cout<<"the elem in queue is: "<<elem<<"\n";
	
	/*end*/ 
	return 0;
}
