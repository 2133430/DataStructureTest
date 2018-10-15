#include<iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;
#define maxsize 100
//##########################
//normal List
//##########################
typedef struct{
	int data[maxsize];
	int len;
}List;

void initList(List& l){
	l.len=0;
}
int insertList(List& l,int index, int elem){
	//check
	if(l.len+1==maxsize||index<0||index>maxsize-1){
		return -1;
	}
	//后撤 
	for(int i=l.len;i>index;i--){
		l.data[i+1] = l.data[i];
	}
	l.data[index]=elem;
	l.len++;//########!!!!!!!!!111
	return 0;
}
int deleteList(List&l, int index,int &elem ){
	//check
	if(l.len==0||index<0||index>maxsize-1){
		return -1;
	}
	elem = l.data[index]+1;
	//pre
	for(int i=index;i<l.len;i++){
		l.data[i] = l.data[i+1];
	}
	l.len--;
	return 0;
}
//##################
//LinkList
//##################
typedef struct LNode{
	int data;
	struct LNode* next;
}LNode;

void initLinkList(LNode* &lst){//!!!!!!!!!!!!!!#########
	lst = (LNode*)malloc(sizeof(LNode));
	lst->next = NULL;
	lst->data=-1;
	cout<<"initial\n";
}

int insertLinkList(LNode* lst, int elem){
	LNode* node;
	node = (LNode*)malloc(sizeof(LNode));
	node->data = elem;
	node->next =NULL;
	node->next = lst->next;
	lst->next = node;
	cout<<"insert\n";
	return 0;
}
int insertTailLinkList(LNode*lst,int elem){
	LNode* node,*tail;
	tail = lst;
	//find the tail. when the tail->next=NULL, the tail is the tail pointer
	while(tail->next!=NULL){
		tail = tail->next;
	} 
	node=(LNode*)malloc(sizeof(LNode));
	node->data = elem;
	node->next =NULL; 
	tail->next = node;
	tail= node;
	cout<<"tail\n";
	return 0;
}
int deleteLinkList(LNode*lst,LNode* preNode,int &elem){
	
	LNode* node;
	node = preNode->next;
	elem = node->data;
	elem++;
	cout<<elem<<"\n";
	preNode->next = node->next;
	free(node);
	return 0;
}
LNode* searchLinkList(LNode* lst, int elem ){
	
	LNode* node;
	node=lst;
	while(node->next!=NULL){
		if(node->next->data==elem){
			break;
		}
	}
	cout<<node->data<<"\n";
	return node;//return NULL or the real pointer
}
//####################
//Queue
//####################
typedef struct {
	int data[maxsize];
	int front;
	int rear;
}Queue;

void initQueue(Queue &q){
	q.front =0;
	q.rear=0;
	
}
int insertQueue(Queue &q, int elem){
	if((q.rear+1)%maxsize==q.front){
		return -1;
	}
	q.rear = (q.rear+1)%maxsize;
	q.data[q.rear] = elem;
	return 0;
}
int outQueue(Queue&q, int&elem){
	if(q.rear==q.front){//!!!!!!!##########3
		return -1;
	}
	q.front=(q.front+1)%maxsize;
	
	elem = q.data[q.front];
	return 0;
}

//###############
//LinkQueue
//###############
typedef struct QNode{
	int data;
	struct QNode* next;
}QNode;

typedef struct LinkQueue{
	QNode* front;
	QNode* rear;
}LinkQueue;
void initLinkQueue(LinkQueue*& lq){
	lq=(LinkQueue*)malloc(sizeof(LinkQueue));
	lq->rear=NULL;
	lq->front=NULL;
}
int inLinkQueue(LinkQueue* lq,int elem){
	QNode* node;
	node = (QNode*)malloc(sizeof(QNode));
	node->data =elem;
	node->next=NULL;
	//inqueue
	//无处安放的链尾节点 and front pointer
	if(lq->rear==NULL){
		lq->front=node;
		lq->rear=node;
	} 
	else{
		lq->rear->next = node;
		lq->rear=node;
	}
	
	return 0;
}

int outLinkQueue(LinkQueue* lq, int &elem){
	QNode* node;
	if(lq->rear==NULL){
		return -2;
	}
	else{
		node=lq->front;
	}
	//the last node in this queue
	if(lq->rear==lq->front){
		elem = node->data;
		lq->front=NULL;
		lq->rear=NULL;
		
	}
	else{
		elem = node->data;
		lq->front= lq->front->next;//###########
	}
	free(node);
	return 0;
}
//###############
//stack
//###############

typedef struct {
	int data[maxsize];
	int top;
}Stack; 
void initStack(Stack &s){
	s.top=-1;
}
int inStack(Stack &s, int elem){
	//check
	if(s.top+1==maxsize){
		return -1;
	}
	s.top++;
	s.data[s.top]=elem;
	return 0;
}
int outStack(Stack& s,int &elem){
	//check
	if(s.top==-1){
		return -1;
	}
	elem = s.data[s.top];
	s.top--;
	return 0;
}

//####################
//LinkStack
//####################
typedef struct SNode{
	int data;
	SNode* next;
}SNode;

void initLinkStack(SNode* &s){
	s = (SNode*)malloc(sizeof(SNode));
	s->next=NULL;
}

int inLinkStack(SNode* s,int elem){
	SNode* node;
	node = (SNode*)malloc(sizeof(SNode));
	node->next=NULL;
	node->data=elem;
	node->next= s->next;
	s->next = node;
	return 0;
}
int outLinkStack(SNode* s,int &elem){
	SNode* node;
	if(s->next==NULL){
		return -1;
	}
	node = s->next;
	elem = node->data;
	s->next = node->next;
	free(node);
	return 0;
}

//##################3
//tree
//##################
typedef struct TNode{
	int data;
	TNode* lchild;
	TNode* rchild;
}TNode;


void visit(TNode* t) {
	cout<<t->data<<"\n";
}
void preOrder(TNode* t){
	if(t!=NULL){
		visit(t);
		preOrder(t->lchild);
		preOrder(t->rchild);
	}
	
}

void inOrder(TNode* t){
	if(t!=NULL){
		
		inOrder(t->lchild);visit(t);
		inOrder(t->rchild);
	}
	
}
void postOrder(TNode* t){
	if(t!=NULL){
		
		postOrder(t->lchild);
		postOrder(t->rchild);visit(t);
	}
	
}
//####################
//TNodeQueue
//####################
typedef struct {
	TNode* data[maxsize];
	int front;
	int rear;
}TQueue;

void initTQueue(TQueue &q){
	q.front =0;
	q.rear=0;
	
}
int inTQueue(TQueue &q, TNode* elem){
	if((q.rear+1)%maxsize==q.front){
		return -1;
	}
	q.rear = (q.rear+1)%maxsize;
	q.data[q.rear] = elem;
	return 0;
}
int outTQueue(TQueue&q, TNode* &elem){
	if(q.rear==q.front){//!!!!!!!##########3
		return -1;
	}
	q.front=(q.front+1)%maxsize;
	
	elem = q.data[q.front];
	return 0;
}
void beamOrder(TNode* t){
	TQueue q;
	initTQueue(q);
	TNode* node;
	if(t!=NULL){
		//in queue
		inTQueue(q,t);
		while(q.front!=q.rear){
			outTQueue(q,node);
			visit(node);
			if(node->lchild!=NULL){
				inTQueue(q,node->lchild);
			}
			if(node->rchild!=NULL){
				inTQueue(q,node->rchild);
			}
		}
	}
	
}

int main(){
	/*
	List l;
	initList(l);
	int elem = rand()%100;
	insertList(l,0,elem);
	cout<<elem<<"\n";
	deleteList(l,0,elem);
	cout<<elem<<"\n";
	cout<<"";
	*/
	/***
	LNode* lst,*l;
	initLinkList(lst);
	initLinkList(l);
	int elem = rand()%100;
	
	cout<<elem<<"\n";insertLinkList(lst,elem);
	insertTailLinkList(l,elem);
	LNode* node;
	node = searchLinkList(lst,elem) ;
	deleteLinkList(lst,node,elem);
	*/
	/**
	int queue[maxsize];
	int front=0;
	int rear =0;
	int elem = rand()%100;
	cout<<elem<<"\n";
	//inqueue
	rear = (rear+1)%maxsize;
	queue[rear]=elem;
	cout<<queue[rear]<<"\n";
	//outqueue
	elem++;
	front = (front+1)%maxsize;
	elem = queue[front] ;
	cout<<elem<<"\n";
	*/
	/**
	Queue q;
	initQueue(q);
	int elem =rand()%100;
	cout<<elem<<"\n";
	insertQueue(q,elem); elem=0;
	//!!!!!!
	outQueue(q,elem);
	cout<<elem<<"\n";
	*/
	/**
	int stack[maxsize];
	int top=-1;
	//instack
	int elem = rand()%100;cout<<elem<<"\n";
	top++;
	stack[top] =elem;
	cout<<stack[top]<<"\n";
	//outstack
	elem=0;
	elem = stack[top];
	top--;
	cout<<elem<<"\n";
	*/
	/**
	Stack s;
	initStack(s);
	int elem = rand()%100;
	cout<<elem<<"\n";
	inStack(s,elem);
	elem=0;
	outStack(s,elem);
	cout<<elem<<"\n";
	*/
	/*
	LinkQueue* lq;
	initLinkQueue(lq);
	int elem=rand()%100;
	cout<<elem<<"\n";
	inLinkQueue(lq,elem);
	elem=0;
	outLinkQueue(lq,elem);
	cout<<elem<<"\n";
	*/
	/**
	SNode* s;
	initLinkStack(s);
	int elem = rand()%100;
	inLinkStack(s,elem);
	cout<<elem<<"\n";
	elem=0;
	outLinkStack(s,elem);
	cout<<elem;
	*/
}
