#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data,left,right;
	Node():left(-1),right(-1){}
};
int T,n,num; 
vector<Node> Tree,heap1,heap2;
void postOrder(int root){
	if(root==-1) return;
	postOrder(Tree[root].left);
	postOrder(Tree[root].right);
	printf("%d%s",Tree[root].data,++num==n?"\n":" ");
}
bool downAdjustmax(int low,int high){
	int i=low,j=i*2;
	while(j<=high){
		if(j+1<=high&&heap1[j+1].data>heap1[j].data)
			j=j+1;
		if(heap1[j].data>heap1[i].data)
			return true;
		else return false;
	}
}
bool downAdjustmin(int low,int high){
	int i=low,j=i*2;
	while(j<=high){
		if(j+1<=high&&heap2[j+1].data<heap2[j].data)
			j=j+1;
		if(heap2[j].data<heap2[i].data)
			return true;
		else return false;
	}
}
int main() {
	scanf("%d%d",&T,&n);
	Tree.resize(n+1);
	while(T--){
		num=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&Tree[i].data);
			if(2*i<=n) Tree[i].left=2*i;
			if(2*i+1<=n) Tree[i].right=2*i+1;
		}
		heap1=heap2=Tree;
		bool f1=false,f2=false;
		for(int i=n/2;i>=1;i--){
			if(downAdjustmax(i,n)) {
				f1=1;
				break;
			}
		}
		if(!f1) puts("Max Heap");
		else{
			for(int i=n/2;i>=1;i--){
		   	 if(downAdjustmin(i,n)) {
					f2=1;
					break;
				}
			}
			if(!f2) puts("Min Heap");
		}
		if(f1&&f2) puts("Not Heap");
		postOrder(1);
	}
	return 0;
}
/*
3 8
98 72 86 60 65 12 23 50
8 38 25 58 52 82 70 60
10 28 15 12 34 9 8 56
*/
