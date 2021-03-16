#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#include<set>
using namespace std; 
const int maxn=10005;
vector<vector<int> >G(maxn);
int N,M,idx[maxn],lowidx[maxn],components[maxn],vis_num,components_cnt; 
int du[maxn]; 
vector<set<int> > Cpnt(1,set<int>());	//初始化成一个空集合 
stack<int> stk;
void Tarjan(int s){
	idx[s]=lowidx[s]=++vis_num;
	stk.push(s);
	for(int i=0;i<G[s].size();i++){
		int v=G[s][i];
		if(idx[v]==0){
			Tarjan(v);
			lowidx[s]=min(lowidx[s],lowidx[v]);
		}else if(components[v]==0){		//这么做就要保证components是从1开始 
			lowidx[s]=min(lowidx[s],idx[v]);
		}
	}
	if(lowidx[s]==idx[s]){
		set<int> temp;
		++components_cnt;
		int t;
		do{
			t=stk.top();stk.pop();
			components[t]=components_cnt;
			temp.insert(t);
		} while(t!=s);
		Cpnt.push_back(temp);
	}
}
int main() {
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
	}
	for(int i=1;i<=N;i++){
		if(idx[i]==0){
			Tarjan(i);
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=0;j<G[i].size();j++){
			if(components[i]!=components[G[i][j]]){	//不属于同一个强连通分量 
				++du[components[i]];	//出度加1 
			}
		}
	}
	int du_eqs_zero=0,idx;
	for(int i=1;i<=components_cnt;i++){
		if(du[i]==0){
			du_eqs_zero++;
			idx=i; 
		}
	}
	printf("%d\n",du_eqs_zero==1?Cpnt[idx].size():0);
	return 0;
}
/*
3 3
1 2
2 1
2 3
*/
