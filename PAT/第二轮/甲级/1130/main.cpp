#include<bits/stdc++.h>
using namespace std; 
struct Node{
	string data;
	int left,right;
	Node(){ left=right=-1;}
};
vector<Node> A;
bool isLeaf(int s){
	return A[s].left==-1&&A[s].right==-1;
}
void DFS(int root){
	if(A[root].left!=-1){
		printf("%s",!isLeaf(A[root].left)?"(":"");
		DFS(A[root].left);
		printf("%s",!isLeaf(A[root].left)?")":"");	
	};
	printf("%s",A[root].data.c_str());
	if(A[root].right!=-1){
		printf("%s",!isLeaf(A[root].right)?"(":"");
		DFS(A[root].right);
		printf("%s",!isLeaf(A[root].right)?")":"");
	}
}
int main() {
	int N;
	scanf("%d",&N);
	A.resize(N+1);
	bool child[N+1]={false};
	for(int i=1;i<=N;i++){
		cin>>A[i].data>>A[i].left>>A[i].right;
		if(A[i].left!=-1)
			child[A[i].left]=1;
		if(A[i].right!=-1)
			child[A[i].right]=1;
	}
	int root=find(child+1,child+N+1,false)-child;
	DFS(root);
	return 0;
}
/*
8
* 8 7
a -1 -1
* 4 1
+ 2 5
b -1 -1
d -1 -1
- -1 6
c -1 -1

8
2.35 -1 -1
* 6 1
- -1 4
% 7 8
+ 2 3
a -1 -1
str -1 -1
871 -1 -1
*/
