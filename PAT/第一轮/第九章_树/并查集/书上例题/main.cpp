#include<bits/stdc++.h>
using namespace std; 
const int maxn=110;
int father[maxn];
int findFather(int s){
	if(father[s]==s) return s;
	int temp=findFather(father[s]);
	father[s]=temp;
	return temp;
}
int main() {
	int n,m,isRoot[maxn];
	iota(father,father+maxn,0);
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		int fa=findFather(u);
		int fb=findFather(v);
		if(fa!=fb){
			father[fb]=fa;
		}
	}
	memset(isRoot,0,sizeof(isRoot));
	for(int i=1;i<=n;i++)
		isRoot[findFather(i)]++;
	printf("%d",n-count(isRoot+1,isRoot+n+1,0));  //左闭右开，由于下标是从1开始，所以要n+1 
	return 0;
}
/*
4 2
1 4
2 3

7 5
1 2
2 3
3 1
1 4
5 6
*/
