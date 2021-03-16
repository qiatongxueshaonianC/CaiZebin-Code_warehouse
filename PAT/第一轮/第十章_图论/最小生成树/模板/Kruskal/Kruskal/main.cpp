#include<bits/stdc++.h> 
using namespace std;
const int maxn=50010;
struct Node{
	int u,v,dis;
	Node(int a,int b,int c){
		u=a;v=b;dis=c;
	}
	Node(){}
}G[maxn];
int n,m,father[maxn];
int findFather(int a){
	if(father[a]==a)
		return a;
	int temp=findFather(father[a]);
	father[a]=temp;
	return temp;
} 
bool cmp(Node a,Node b){
	return a.dis <b.dis;
}
int Kruskal(){
	iota(father,father+n,0);
	int ans=0,num_edge=0;
	sort(G,G+m,cmp);
	for(int i=0;i<m;i++){
		int fa=findFather(G[i].u );
		int fb=findFather(G[i].v);
		if(fa!=fb){
			father[fa]=fb;
			ans+=G[i].dis;
			num_edge++;
		}
		if(num_edge==n-1) break;
	}
	if(num_edge!=n-1) return -1;
	else return ans;
}
int main() {
	int u,v,dis;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&dis);
		Node node(u,v,dis);
		G[i]=node;
	}
	int ans=Kruskal();
	printf("%d\n",ans);
	return 0;
}
/*
6 10
0 1 4
0 4 1
0 5 2
1 2 1
1 5 3
2 3 6
2 5 5
3 4 5
3 5 4
4 5 3
*/
