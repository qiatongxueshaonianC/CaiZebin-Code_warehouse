#pragma warning(disable:4996)
#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
struct relation{
	int x,u,v;
	relation(int a,int b,int c):x(a),u(b),v(c){};
}; 
int N, K, idx[maxn], lowidx[maxn], dfs_num, components[maxn] = { 0 }, num_cmp;
vector<vector<int>>G(maxn);
vector<set<int>> A(maxn);
stack<int> stk;
vector<set<int>> Topo;
int indegree[maxn],cost[maxn];
vector<relation> Relation;
map<pair<int,int>,bool> dp;
void Tarjan(int u) {
	idx[u] = lowidx[u] = ++dfs_num;
	stk.push(u);
	for (auto i : G[u]) {
		int v = i;
		if (idx[v] == 0) {
			Tarjan(v);
			lowidx[u] = min(lowidx[u], lowidx[v]);
		}
		else if (components[v] == 0) {
			lowidx[u] = min(lowidx[u], idx[v]);
		}
	}
	if (idx[u] == lowidx[u]) {
		int t = 0;
		++num_cmp;
		set<int>& st = A[num_cmp];
		do {
			t = stk.top(); stk.pop();
			st.insert(t);
			components[t] = num_cmp;
		} while (t != u);
	}
}
void Solve() {
	queue<int> q;
	for (int i = 1; i <= num_cmp; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			cost[i] = 1;
		}
	}
	long long ans = 0;
	while (!q.empty()) {
		auto now = q.front(); q.pop();
		for (auto i : Topo[now]) {
			indegree[i]--;
			if(dp.find({now,i})!=dp.end())	//2020/8/31/23:25 就是这里出了问题
				cost[i] = max(cost[i], cost[now] + 1); 	//并不是所有情况都要+1的，允许相等  
			else
				cost[i]=max(cost[i],cost[now]);
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
	}
	for(int i=1;i<=num_cmp;i++){
	    ans+=1ll*A[i].size()*cost[i];
	}
	cout << ans;
}
int main() {
	scanf("%d%d", &N, &K);
	int op = 0, u, v;
	for (int i = 0; i < K; i++) {
		scanf("%d%d%d", &op, &u, &v);
		if (op == 1) {
			G[u].push_back(v);
			G[v].push_back(u);
		}
		else if (op == 3) {
			G[v].push_back(u);
		}
		else if(op==5){
		    G[u].push_back(v);
		}else{
			Relation.push_back(relation(op,u,v));
		}
	}
	for (int i = 1; i <= N; i++) {
		if (idx[i] == 0) {
			Tarjan(i);
		}
	}
	//	reverse(A.begin(), A.end());
	Topo.resize(num_cmp + 1);
	for(auto I:Relation){
		if(components[I.u]==components[I.v]){
			cout<<-1<<endl;
			return 0;
		}
		int from=components[I.u];
		int to=components[I.v];
		if(I.x==4)
			swap(from,to);
		if(Topo[from].find(to)==Topo[from].end()){
			Topo[from].insert(to);
			indegree[to]++;
			dp.insert(make_pair(make_pair(from,to),true));	//2020/8/31/23:25 
		}
	}
	for (int i = 1; i <= N; i++) {
		for (auto t : G[i]) {
			int v = t;
			int from = components[i];
			int to = components[v];
			if (components[i] != components[v] ) {
				if (Topo[from].find(to) == Topo[from].end()) {
					Topo[from].insert(to);
					indegree[to]++;
				}
			}
		}
	}
	Solve();
	return 0;
}
/*
5 7
1 1 2
2 3 2
4 4 1
3 4 5
5 4 5
2 3 5
4 5 1
*/
