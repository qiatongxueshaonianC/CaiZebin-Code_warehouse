/*	˼·�����Ƚ���������û�и��׵Ľڵ�Ϊ���ڵ㣬�ҵ���������һ�������õ������ڵ��level�����ʹ�ñ�����*/ 
// �㷨���Ӷȣ�O(n) 
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
void Union(int fa,int cld){	//fa�����ڵ㣬˳���ܱ� 
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
	//�����������󣬿�ʼ��ز�ѯ
	for(int i=0;i<query[u].size();i++){
		int v=query[u][i];
		if(vis[v]==true){	//����Ѿ����ʣ�û���ʵĲ��� 
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
			query[u].push_back(v);	//ע�⣬����Ҫ��˫��ߣ���Ϊ������u���Ժ����v��û���ʣ���ʱ��� 
			query[v].push_back(u);	//�ÿ�(v,u)�� 
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
