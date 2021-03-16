#include<bits/stdc++.h>
using namespace std;
int T,n,num; 
vector<int> Tree,heap1,heap2;
void postOrder(int root){
	if(root>n) return;
	postOrder(2*root);
	postOrder(2*root+1);
	printf("%d%s",Tree[root],++num==n?"\n":" ");
}
bool downAdjust(int low,int high,bool flag){
	int i=low,j=i*2;
	while(j<=high){
		if(flag){
			if(j+1<=high&&heap1[j+1]>heap1[j])
				j=j+1;
			if(heap1[j]>heap1[i])
				return true;
			else return false;
		}else{
			if(j+1<=high&&heap2[j+1]<heap2[j])
				j=j+1;
			if(heap2[j]<heap2[i])
				return true;
			else return false;
		}
	}
}
int main() {
	scanf("%d%d",&T,&n);
	Tree.resize(n+1);
	while(T--){
		num=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&Tree[i]);
		heap1=heap2=Tree;
		bool f1=false,f2=false;
		for(int i=n/2;i>=1;i--){
			if(downAdjust(i,n,1)) f1=1;
			if(downAdjust(i,n,0)) f2=1;
		}
		printf("%s\n",!f1?"Max Heap":!f2?"Min Heap":"Not Heap");
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
