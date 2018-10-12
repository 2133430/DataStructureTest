#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;
#define maxsize 100
#define ElemType int
#define Error -1
#define Success 0

//normal list
typedef struct SQList{
	ElemType data[maxsize];
	int len;
}SQList;
//LinkList
typedef struct LNode{
	ElemType data;
	LNode* next;
}LNode;

//initial the list

void initList(SQList &l){
	l.len=0;
}
//input

ElemType inList(SQList &l, ElemType elem,int index){
	//check if the list is full########
	if(l.len+1==maxsize||index<0||index>maxsize-1){
		return Error;
	}
	//space i start with l.len and end with data[index+1] = datq[index]
	for(int i=l.len;i>index;i--){
		l.data[i+1] = l.data[i];
	}
	l.data[index] = elem;
	l.len++;
	return Success;
}
//output
ElemType outList(SQList &l, ElemType &elem, int index){
	//check if empty###########
	if(l.len==0||index<0||index>maxsize-1){
		return Error;
	}
	elem = l.data[index];
	//space i start with index and end with len-1 
	for(int i=index;i<l.len;i++){
		l.data[i] = l.data[i+1];
	}
	l.len--;
	return Success;
}

//initial the linklist
void initLinkList(LNode*& l){
	l = (LNode*)malloc (sizeof(LNode));
	l->next = NULL;
}
//insert

ElemType insertLinkList(LNode* l , ElemType elem){
	//head insert
	LNode* node;
	node = (LNode*)malloc(sizeof(LNode));
	node->data = elem;
	node->next = l->next;
	l->next = node;
	return Success;
}

//insert tail

ElemType insertTailLinkList(LNode* l,ElemType elem){
	LNode* node,*tail;//#####tail pointer is essential
	node = (LNode*)malloc(sizeof(LNode));
	node->data = elem;
	node->next =NULL;
	tail->next = node;
	l->next =node;
	return Success;
}
//out
/*
ElemType delete(LNode* l,ElemType elem){
	return 0;
}
*/
int main(){
	//normal list
	/*start*
	int list[maxsize];
	int len=-1;
	//input
	int elem = rand()%100;
	len++;
	list[len] = elem;
	cout<<"the elem is: "<<list[len]<<"\n";
	//output
	elem = list[len];
	len--;
	cout<<"the elem in list is: "<<elem<<"\n";
	*end*/
	
	//normal list using dataSt
	/*start**
	SQList l;
	initList(l);
	int elem = rand()%100;
	cout<<"the elem is: "<<elem<<"\n";
	inList(l,elem,l.len+1);
	outList(l,elem,l.len);
	cout<<"the elem in list is: "<<elem<<"\n";
	*end*/
	
	//LinkList
	/*start*/
	LNode * l,*s;
	int elem =rand()%100;
	initLinkList(l);
	initLinkList(s);
	insertLinkList(l,elem);
	insertTailLinkList(l,elem);
	/*end*/
	return 0;
} 
