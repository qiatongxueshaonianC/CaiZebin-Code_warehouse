#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
int father[505],degree[maxn],harsh[maxn],N,M,n,m;//并查集底层数组
int findFather(int x){//查找根节点
    if(father[x]==x) return x;
    int temp=findFather(father[x]);
    father[x]=temp;
    return temp;
}
bool cmp(int a) {
	return a%2==1;
}
int main(){
	scanf("%d%d",&n,&m);
	iota(father,father+n+1,0);
	int u,v;
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		harsh[u]++;
		harsh[v]++;
		int fa=findFather(u),fb=findFather(v);
   	    if(fa!=fb) father[fa]=fb;  //天啊，这个小bug找了一个多小时 2019/11/8/0:27发现 
		   //这里不是father[u]=v;！！！！是对根节点做的合并！！！！！！！！！！！！！！！！！！ 
	}
	for(int i=1;i<=n;i++)
		printf("%d%s",harsh[i],i==n?"\n":" ");
	int flag=0;
	for(int i=1;i<=n;i++) 
		if(findFather(i)==i) 
			flag++;
	if(flag==1){
		int num=count_if(harsh+1,harsh+n+1,cmp);
		if(num==0) puts("Eulerian");
		else if(num==2) puts("Semi-Eulerian");
		else puts("Non-Eulerian");
	}else puts("Non-Eulerian");
	return 0;
}
/*
7 12
5 7
1 2
1 3
2 3
2 4
3 4
5 2
7 6
6 3
4 5
6 4
5 6

6 10
1 2
1 3
2 3
2 4
3 4
5 2
6 3
4 5
6 4
5 6

5 8
1 2
2 5
5 4
4 1
1 3
3 2
3 4
5 3
*/
