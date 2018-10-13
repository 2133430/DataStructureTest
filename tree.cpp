#include <iostream>
#include <malloc.h>
#include <stdlib.h>

using namespace std;

#define ElemType int
#define maxsize 100
#define Success 0
#define Error -1

//normal tree
typedef struct BTNode{
	ElemType data;
	struct BTNode* lchild;
	struct BTNode* rchild;
}BTNode;
typedef struct Queue{
	ElemType front,rear;
	BTNode* data[maxsize];
}Queue;

//initial the queue
void initQueue(Queue &q){
	q.front = 0;
	q.rear = 0;
}
//in queue
ElemType inQueue(Queue &q, BTNode* elem){
	//check whether the queue is full
	if((q.rear+1)%maxsize==q.front){
		return Error;
	}
	q.rear = (q.rear+1)%maxsize;
	q.data[q.rear]=elem;
	return Success;
}
//out queue
ElemType outQueue(Queue &q, BTNode* &elem){
	//check whether the queue is empty
	if(q.rear==q.front){//###############
		return Error;
	}
	q.front = (q.front+1)%maxsize;
	elem = q.data[q.front];
	return Success;
}
void visit(BTNode* t){
	cout<<t->data<<"\n";
}
void preOrder(BTNode* t){
	//root first
	//check if the tree is empty
	if(t!=NULL){	
	visit(t);
	preOrder(t->lchild);
	preOrder(t->rchild);
	}
}

void inOrder(BTNode* t){
	//lchild first
	if(t!=NULL){
		
		inOrder(t->lchild);
		visit(t);
		inOrder(t->rchild);
	}
}

void postOrder(BTNode* t){
	//root last
	if(t!=NULL){
		postOrder(t->lchild);
		postOrder(t->rchild);
		visit(t);
	}
}

//beam
void beam(BTNode* t){
	//queue
	Queue queue;
	initQueue(queue);
	BTNode* node;
	//when the tree is has child
	if(t!=NULL){
		//put the root in the queue and recursive
		inQueue(queue,t);
		
		//when the queue is not empty
		while( (queue.front)!=(queue.rear)){
			outQueue(queue,node);
			visit(node);
			
			//if left child-tree is not empty
			if(node->lchild!=NULL){
				inQueue(queue,t->lchild);
			}
			
			//right child-tree is not empty
			
			if(node->rchild!=NULL){
				inQueue(queue,t->rchild);
			}
			
		}
	}
} 

//get depth

int getDepth(BTNode* t){
	int LD,RD;//left depth and right depth
	//if the tree is empty
	if(t==NULL){
		return Error;
	}
	else{
		LD = getDepth(t->lchild);
		
		RD = getDepth(t->rchild);
		
		return (LD>RD?LD:RD)+1;//plus 
	}
}
//initial the tree

void inserTreeNode(BTNode* t, ElemType elem){
	
}
BTNode* initTree(BTNode* t,ElemType arr[], int epoch){
	BTNode* node;
		if(arr[epoch]!=(0)){
			
		
		//new Node
		node = (BTNode*)malloc(sizeof(BTNode));
		node->data = arr[epoch];
		cout<<arr[epoch]<<"\n";
		node->lchild = NULL;
		node->rchild =NULL;
		
		node->lchild = initTree(t->lchild,arr,epoch+1);
		node->rchild = initTree(t->rchild,arr,epoch+2); 
	}
}
int main(){
	BTNode* treeRoot;
	int arr[maxsize] ={0};
	for(int i=0;i<10;i++){
		arr[i]=rand()%100+i;
		cout<<arr[i]<<"\n";
	}
	//initTree(treeRoot,arr,0);
	return 0;
} 
