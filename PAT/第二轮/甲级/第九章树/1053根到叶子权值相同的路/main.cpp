#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<climits>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<ctime>
#include<iomanip>
#define lowbit(x) x&(-x0)
using namespace std;
typedef long long LL;
const int maxn=110;
LL w[maxn],N,M,Sum;
vector<vector<int> >G;
multiset<vector<int>,greater<vector<int> > >ans;
vector<int> temp;
void DFS(int id,LL sum){
	if(G[id].size()==0){
		temp.push_back(w[id]);
		sum+=w[id];
		if(sum==Sum){
			ans.insert(temp);
		}
		temp.pop_back();
		return;
	}
	temp.push_back(w[id]);
	sum+=w[id];
	if(sum>Sum)
		goto loop;
	for(auto i:G[id]){
		DFS(i,sum);
	}
	loop:
	temp.pop_back();
}
int main() {
	std::ios::sync_with_stdio(false);
	cin>>N>>M>>Sum;
	G.resize(N);
	for(int i=0;i<N;i++){
		cin>>w[i];
	}
	for(int i=0;i<M;i++){
		int id,k,u;
		cin>>id>>k;
		while(k--){
			cin>>u;
			G[id].push_back(u);
		}
	}
	DFS(0,0);
	for(auto I:ans){
		for(int i=0;i<I.size();i++){
			cout<<I[i]<<(i==I.size()-1?"\n":" ");
		}
	}
	return 0;
}
/*
20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19
*/
