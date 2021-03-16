#include<bits/stdc++.h>
using namespace std; 
const int maxn=30;
int n,v,weight[maxn],c[maxn],maxvalue;
void DFS(int value,int index,int sumv){
	if(index==n&&value>maxvalue){
		maxvalue=value;
		return;
	}
	if(sumv+weight[index]<=v&&index<n){  //¼ôÖ¦ 
		DFS(value,index+1,sumv);  //²»Ñ¡;
		DFS(value+c[index],index+1,sumv+weight[index]); //Ñ¡ 
	}
}
int main() {
	scanf("%d%d",&n,&v);
	for(int i=0;i<n;i++)
		scanf("%d",&weight[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&c[i]);
	DFS(0,0,0);
	printf("%d\n",maxvalue);
	return 0;
}
/*
5 8
3 5 1 2 2
4 5 2 1 3
*/ 
