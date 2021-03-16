#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
vector<vector<int> >G(maxn);
int N,M,idx[maxn],lowidx[maxn],vis_num,num_components,components[maxn]; 
stack<int> stk;
void Tarjan(int s){
	idx[s]=lowidx[s]=++vis_num;
	stk.push(s);
	for(auto i:G[s]){
		if(idx[i]==0){
			Tarjan(i);
			lowidx[s]=min(lowidx[s],lowidx[i]);
		}
		else if(components[i]==0){
			lowidx[s]=min(idx[i],lowidx[s]);
		}
	}
	if(idx[s]==lowidx[s]){
		int t=0;
		num_components++;
		do{
			t=stk.top();stk.pop();
			components[t]=num_components;
		}while(t!=s);
	}
}
int main() {
/*	std::ios::sync_with_stdio(false);		//�ᳬʱ 
	cin>>N>>M;*/
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
	}
	for(int i=1;i<=N;i++){
		if(idx[i]==0)
			Tarjan(i);
	}
	int K;
	cin>>K;
	while(K--){
		int u,v;
		scanf("%d%d",&u,&v);
		if(components[u]==components[v])
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
/*
12 19
3 4
1 3
12 11
5 9
6 2
3 2
10 7
9 1
7 12
2 4
9 5
2 6
12 4
11 10
4 8
8 12
11 8
12 7
1 5
20
11 4
12 7
3 6
2 3
5 3
3 9
4 3
8 3
8 10
10 11
7 8
7 1
9 5
1 9
2 6
3 1
3 12
7 3
6 9
6 8
*/
