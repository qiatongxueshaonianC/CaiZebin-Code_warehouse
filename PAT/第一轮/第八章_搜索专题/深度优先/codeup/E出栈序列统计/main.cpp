#include<bits/stdc++.h>
using namespace std;
const int maxn=22;
bool vis[maxn]; 
int ans,temp,n;
stack<int> s;
void DFS(int in,int out){
	if(out==0) ans++; //全部入完栈，多一种方法；
	else if(in==0){    //还没有元素入过栈 
		DFS(in+1,out-1);   //入栈一个元素 
	} else{       //既有等待入栈又有等待出栈则分两种情况 
		DFS(in+1,out-1);
		DFS(in-1,out); 
	} 
}
int main() {
	scanf("%d",&n);
	DFS(0,n);
	printf("%d\n",ans);
	return 0;
}
/*
3
*/
