#include <iostream>
#include <malloc.h>
#include <stdlib.h>
using namespace std;
#define maxsize 100
#define Success 0
#define Error -1
int visit[maxsize];
//############
//Graph adjacency matrix
//############
typedef struct{
	int no;
	char info;
}VertexType;
typedef struct{
	int edge[maxsize][maxsize];
	int n,e;
	VertexType vex[maxsize];
}MGraph;

typedef struct ArcNode{
	int adjvex;
	ArcNode *nextarc;
	int info;
}ArcNode;

typedef struct VNode{
	char data;
	ArcNode* firstarc;
}VNode;

typedef struct{
	VNode adjlist[maxsize];
	int n,e;
}AGraph;

void Visit(int v){
	cout<<v<<"\n";
}
//DFS
void DFS(AGraph *G,int v){
	ArcNode *node;
	visit[v]=1;
	Visit(v);
	node=G->adjlist[v].firstarc;
	while(node!=NULL){
		if(visit[node->adjvex]==0){
			DFS(G,node->adjvex);
			node= node->nextarc;
		}
	}
	
}
//BFS
int main(){
	
	return 0;
}
