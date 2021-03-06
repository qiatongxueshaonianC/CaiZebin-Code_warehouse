/*	思路：首先建树，根据没有父亲的节点为根节点，找到根，遍历一次树，得到各个节点的level，最后使用倍增法*/ 
// 算法复杂度：O(n) 
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std; 
const int maxn=10010; 
vector<vector<int> > G(maxn),query(maxn); 
vector<int> ans(maxn);
int N,query_cnt=1,query_id[maxn][maxn],father[maxn];
bool Have_father[maxn],vis[maxn];
int findFather(int a){
	if(father[a]<0)
		return a;
	int temp=findFather(father[a]);
	father[a]=temp;
	return temp;
} 
void Union(int fa,int cld){	//fa做父节点，顺序不能变 
	int Fa=findFather(fa);
	int Fcld=findFather(cld);
	if(Fa!=Fcld){
		father[Fa]=father[Fa]+father[Fcld];
		father[Fcld]=Fa;
	}
} 
void LCA(int u){
	vis[u]=true;
	for(int i=0;i<G[u].size();i++){
		if(vis[G[u][i]]==false){
			LCA(G[u][i]);
		}
		Union(u,G[u][i]);
	}
	//访问完子树后，开始相关查询
	for(int i=0;i<query[u].size();i++){
		int v=query[u][i];
		if(vis[v]==true){	//如果已经访问，没访问的不管 
			int q_id=query_id[u][v];
			ans[q_id]=findFather(v);
		}
	} 
}
void init(){
	fill(father,father+maxn,-1);
	fill(G.begin(),G.end(),vector<int>());
	fill(query.begin(),query.end(),vector<int>());
	memset(Have_father,false,sizeof(Have_father));
	memset(vis,false,sizeof(vis));
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		init(); 
		scanf("%d",&N);
		int u,v;
		for(int i=0;i<N-1;i++){
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			Have_father[v]=true;
		}
		for(int i=0;i<query_cnt;i++){
			scanf("%d%d",&u,&v);
			query[u].push_back(v);	//注意，这里要建双向边，因为访问完u，以后可能v还没访问，到时候就 
			query[v].push_back(u);	//得靠(v,u)了 
			query_id[u][v]=query_id[v][u]=i;
		}
		int root;
		for(int i=1;i<=N;i++){
			if(Have_father[i]==false){
				root=i;
				break;
			}
		}
		LCA(root);
		for(int i=0;i<query_cnt;i++)
			printf("%d\n",ans[i]);
	}
	return 0;
}
/*
2
16
1 14
8 5
10 16
5 9
4 6
8 4
4 10
1 13
6 15
10 11
6 7
10 2
16 3
8 1
16 12
16 7
5
2 3
3 4
3 1
1 5
3 5
*/
