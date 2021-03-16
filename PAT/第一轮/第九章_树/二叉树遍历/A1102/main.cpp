#include<bits/stdc++.h>
using namespace std; 
const int maxn=20;
int n,root,num,father[maxn]; 
struct Node{
	int data,left,right;
	Node(){
		left=right=-1;
	}
}Tree[maxn];
void LayerOrder(int root){
	queue<int> q;
	q.push(root);
	while(q.size()){
		int now=q.front();q.pop();
		printf("%d",Tree[now].data);
		if(Tree[now].right!=-1) q.push(Tree[now].right);  //反转操作； 
		if(Tree[now].left!=-1) q.push(Tree[now].left);
		if(!q.empty()) printf(" ");
		else puts("");
	}
}
void InOrder(int root){
	if(root==-1) return;
	//反转操作： 
	InOrder(Tree[root].right);
	printf("%d",Tree[root].data);
	if(++num<n) printf(" ");
	else puts("");
	InOrder(Tree[root].left);
}
int main() {
	scanf("%d",&n);
	string s1,s2;
	fill(father,father+maxn,-1);
	for(int i=0;i<n;i++){
		cin>>s1>>s2;
		if(s1!="-") {
			Tree[i].left=stoi(s1);
			father[stoi(s1)]=i;   //也可以用一个标志flag[n]来表示 
		}
		if(s2!="-") {
			Tree[i].right=stoi(s2);
			father[stoi(s2)]=i;
		}
		Tree[i].data=i;
	}
	for(int i=0;i<n;i++){
		if(father[i]==-1){
			root=i;
			break;
		}
	}
	LayerOrder(root);
	InOrder(root);
	return 0;
}
/*
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
*/
