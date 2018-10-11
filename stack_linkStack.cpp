#include <iostream>
#include <malloc.h> 
#include <stdlib.h>
using namespace std;
#define maxsize 100 
#define ElemType int
#define Error -1
//normal stack
typedef struct Stack{
	ElemType top;
	ElemType data[maxsize];
}Stack;

typedef struct SNode{
	ElemType data;
	SNode* next;
}SNode;
//initial the stack
void initStack(Stack &s){
	s.top=-1;
}
//push
ElemType pushStack(Stack &s,ElemType elem){
	//check if stack is full
	if(s.top==maxsize-1){
		return Error;
	}
	++s.top;
	s.data[s.top]=elem;
	return elem;
}
//pop
ElemType popStack (Stack &s, ElemType &elem){
	//check if stack is empty
	if(s.top==-1){
		return Error;
	}
	elem = s.data[s.top];
	--s.top;
	return elem;
}
//inital the linkstack
void initLinkStack(SNode *&head){
	//##########s is the head pointer which point to a space
	//the data will be stored in this space
	head= (SNode*)malloc (sizeof(SNode));
	head->next=NULL;
}
//push into the LinkStack
ElemType pushLinkStack(SNode *head, ElemType elem){
	//there is no maxsize in LinkStack
	SNode* node;
	node = (SNode*)malloc(sizeof(SNode));
	//the head and node are all pointer. they need to use -> rather than .
	node->data = elem;
	node->next = head->next;
	head->next = node;
	//############using head insert method so the head pointer always point to the last pushed data
	//the datas are order reverse
	//it can keep the stack feature : FILO
	return elem;
}
ElemType popLinkStack(SNode *head, ElemType &elem){
	//check whether the stack is empty
	SNode* node;
	//node is point to the pointer which is about to delete
	node = head->next;
	elem = node->data;
	//交代后事
	head->next=node->next;
	free(node);
	return elem;
	 
}
int main(){
	int elem = 12;
	//normal stack using no typedef 
	/*start
	int stack[maxsize];
	int top=-1;
	//push without checking buffer
	
	++top;
	stack[top] = elem+rand()%10;
	cout<<stack[top]<<"\n"; 
	//pop 
	elem = stack[top];
	--top;
	cout<<elem<<"\n";
	end*/
	
	//normal stack using typedef
	/*start
	Stack s;
	initStack(s);
	elem = rand()%10;
	cout<<"the elem is: "<<elem<<"\n";
	pushStack(s,elem);
	popStack(s,elem);
	cout<<"the num in stacktop is: "<<elem<<"\n";
	end*/
	
	//Link Stack
	/*start*/
	//######lstHead is a pointer!!!!
	SNode* lstHead;
	initLinkStack(lstHead);
	elem = rand()%10 + rand()%100;
	cout<<"the elem is: "<<elem<<"\n";
	pushLinkStack(lstHead,elem);
	popLinkStack(lstHead,elem);
	cout<<"the num in the stacktop is: "<<elem<<"\n";
	/*end*/
	return 0;
}
