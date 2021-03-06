/*解题思路：
首先，题目已经给出了一种可行的方法作为已知，每一个女孩都唯一连有一条边到对应的王子；
现在考虑：A王子本来的新娘被其B王子取走了，那么A王子需要一个新年作为替代，而B王子对应的
原女孩现在正好空缺，（如果该女孩嫁给了C王子，那么C王子原来对应的女孩现在也是空缺）其他以此类推。 
当这三对新人在同一个强连通分量内时，总是可以满足要求，每个王子都可以娶到一个女孩）*/

//发现上面说错了，前提是必须是王子喜欢的女孩才行 
#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#include<set>
#include<algorithm>
using namespace std; 
const int maxn=4010;
vector<vector<int> >G(maxn),ans(maxn);
int N,components[maxn],idx[maxn],lowidx[maxn],vis_num,_stack[maxn],top,components_cnt; 
stack<int> stk; 
void Tarjan(int s){
	idx[s]=lowidx[s]=++vis_num;
	stk.push(s);
	for(int i=0;i<G[s].size();i++){
		int v=G[s][i];
		if(idx[v]==0){	//若这个点没访问过 
			Tarjan(v);
			lowidx[s]=min(lowidx[s],lowidx[v]);
		}else if(components[v]==0){	//该点之前就已经访问过，并且属于当前的强连通分量 
			lowidx[s]=min(lowidx[s],idx[v]); 
		} 
	}
	if(idx[s]==lowidx[s]){	//以s为起点的一系列点属于一个强连通分量 
		int t;
		components_cnt++; 
		do{
			t=stk.top();stk.pop();
			components[t]=components_cnt;
		}while(t!=s);
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin>>N;
//	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		int k,v;
		cin>>k;	
	//	scanf("%d",&k);
		while(k--){
			cin>>v;
		//	scanf("%d",&v);
			G[i].push_back(v+N);
		}
	}
	for(int i=1;i<=N;i++){
		int v;
		cin>>v;
	//	scanf("%d",&v);
		G[v+N].push_back(i);
	}
	for(int i=1;i<=N;i++){
		if(idx[i]==0)
			Tarjan(i);
	}
	for(int i=1;i<=N;i++){
		int ans[maxn]={0},k=0;
		for(int j=0;j<G[i].size();j++){
			int v=G[i][j];
			if(components[i]==components[v]){
				ans[k++]=v;
			}
		}
		printf("%d",k);
		sort(ans,ans+k);
		for(int j=0;j<k;j++)
			printf(" %d",ans[j]-N);
		puts("");
	}
	return 0;
}
/*
4
2 1 2
2 1 2
2 2 3
2 3 4
1 2 3 4
*/
