#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
int N,M,degree[maxn],idx[maxn],lowidx[maxn],dfs_num,component[maxn],num_of_cmp; 
vector<vector<int> >G(maxn);
stack<int> stk;
void Tarjan(int u){
	idx[u]=lowidx[u]=++dfs_num;
	stk.push(u);
	for(auto i:G[u]){
		if(idx[i]==0){
			Tarjan(i);
			lowidx[u]=min(lowidx[u],lowidx[i]);
		}else if(component[i]==0){
			lowidx[u]=min(lowidx[u],idx[i]);
		}
	}
	if(lowidx[u]==idx[u]){
		int t=0;
		++num_of_cmp;
		do{
			t=stk.top();stk.pop();
			component[t]=num_of_cmp;
		}while(t!=u);
	}
}
int main() {
//	std::ios::sync_with_stdio(false);
//	cin.tie(nullptr);cout.tie(nullptr);
	cin>>N>>M;
	for(int i=0;i<M;i++){
		int u,v;
		cin>>u>>v;
		degree[u]++;
		degree[v]++;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=N;i++)
		cout<<degree[i]<<(i==N?"\n":" ");
	int odd=0;
	for(int i=1;i<=N;i++){
		if(idx[i]==0){
			Tarjan(i);
		}
	} 
	for(int i=1;i<=N;i++){
		if(degree[i]&1)
			odd++;
	}
	if(num_of_cmp>1||(odd!=0&&odd!=2))
		puts("Non-Eulerian");
	else if(odd==0)
		puts("Eulerian");
	else if(odd==2)
		puts("Semi-Eulerian");
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

4 4
1 2
2 1
3 4
4 3
*/
