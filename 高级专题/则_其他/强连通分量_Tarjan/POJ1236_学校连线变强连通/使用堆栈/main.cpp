#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
using namespace std; 
const int maxn=105;
vector<vector<int> >G(maxn);
int N,components_cnt,components[maxn],idx[maxn],lowidx[maxn],vis_num;
int indegree[maxn],outdegree[maxn];
stack<int> stk;
void Tarjan(int s){
	idx[s]=lowidx[s]=++vis_num;
	stk.push(s);
	for(int i=0;i<G[s].size();i++){
		int v=G[s][i];
		if(idx[v]==0){		//如果这个点还没访问 
			Tarjan(v);
			lowidx[s]=min(lowidx[s],lowidx[v]);
		}else if(components[v]==0){	//属于当前的强连通分量 
			lowidx[s]=min(lowidx[s],idx[v]); 
		}
	}
	if(lowidx[s]==idx[s]){	//以s为起点的一系列点构成了一个强连通分量 
		int t;
		components_cnt++;	//强连通分量数加一；
		do{
			t=stk.top();stk.pop();
			components[t]=components_cnt;
		} while(t!=s);
	}
} 
int main() {
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		int v;
		while(~scanf("%d",&v)&&v!=0){
			G[i].push_back(v);
		}
	}
	for(int i=1;i<=N;i++){
		if(idx[i]==0){	//第i个点还没访问过 
			Tarjan(i);
		}
	}
	if(components_cnt==1){		//若整幅图就是一个强连通分量 
		printf("%d\n%d",1,0);
		return 0;
	} 
	for(int i=1;i<=N;i++){
		for(int j=0;j<G[i].size();j++){
			int nxt=G[i][j];	//遍历i的邻接点
			if(components[i]!=components[nxt]){	//两个点不属于同一个强连通分量 ，连通分量压缩成一个点 
				indegree[components[nxt]]++;	//nxt所在的联通分量的入度加一 
				outdegree[components[i]]++;	//i所在的联通分量的出度加一 
			} 
		}
	} 
	int ans1=0,ans2=0; 
	for(int i=1;i<=components_cnt;i++){
		if(indegree[i]==0)		//入度为0的强连通块有几个，即为第一问答案 
			ans1++;
		if(outdegree[i]==0)
			ans2++;
	} 
	printf("%d\n%d",ans1,max(ans1,ans2));
	return 0;
}
/*
5
2 4 3 0
4 5 0
0
0
1 0
*/
