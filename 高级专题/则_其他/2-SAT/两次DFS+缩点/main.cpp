#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<climits>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<bitset>
#include<iomanip>
#include<ctime>
#define lowbit(x) x&(-x)
using namespace std; 
const int maxn=1e5*2+10;
struct Node{
	int st,ed,len;
};
vector<Node> A;
int N,cmp[maxn];
bool used[maxn];
vector<vector<int> >G(maxn),rG(maxn); 
vector<int> Post_Order;
void Insert_edge(int from,int to){
	G[from].push_back(to);
	rG[to].push_back(from);
}
void DFS(int u){
	used[u]=true;
	for(int i=0;i<G[u].size();i++){
		if(!used[G[u][i]])
			DFS(G[u][i]);
	}
	Post_Order.push_back(u);
}
void RDFS(int u,int k){
	used[u]=true;
	cmp[u]=k;
	for(int i=0;i<rG[u].size();i++){
		int v=rG[u][i];
		if(!used[v]){
			RDFS(v,k);
		}
	}
}
void SCC(){
	memset(used,false,sizeof(used));
	for(int i=0;i<N;i++){
		if(!used[i])
			DFS(i);
	}
	memset(used,false,sizeof(used));
	int k=0;
	for(int i=Post_Order.size()-1;i>=0;i--){
		if(!used[Post_Order[i]])
			RDFS(Post_Order[i],k++);
	}
}
void Solve(){
	for(int i=0;i<N;i++){
		for(int j=0;j<i;j++){
		//	if(A[j].st+A[j].len>A[i].ed||A[i].st+A[i].len>A[j].ed){	//同时开始冲突 
			Node& a=A[i];
			Node& b=A[j];
			if(min(a.st+a.len,b.st+b.len)>max(a.st,b.st)){
				//(xi^xj)==0 ~xiV~xj==1
				Insert_edge(i,j+N);
				Insert_edge(j,i+N);
			}
			if(min(a.st+a.len,b.ed)>max(a.st,b.ed-b.len)){
				//(xi^~xj)==0
				Insert_edge(i,j);
				Insert_edge(j+N,i+N);
			}
			if(min(a.ed,b.st+b.len)>max(a.ed-a.len,b.st)){
				//(~xi^xj)==0
				Insert_edge(i+N,j+N);
				Insert_edge(j,i);
			}
			if(min(a.ed,b.ed)>max(a.ed-a.len,b.ed-b.len)){
				//(~xi^~xj)==0
				Insert_edge(i+N,j);
				Insert_edge(j+N,i);
			}
		}
	}
	SCC();
	for(int i=0;i<N;i++){
		if(cmp[i]==cmp[i+N]){
			puts("NO");
			return;
		}
	}
	puts("YES");
	for(int i=0;i<N;i++){
		if(cmp[i]>cmp[i+N])
			printf("%02d:%02d %02d:%02d\n",A[i].st/60,A[i].st%60,(A[i].st+A[i].len)/60,(A[i].st+A[i].len)%60);
		else
			printf("%02d:%02d %02d:%02d\n",(A[i].ed-A[i].len)/60,(A[i].ed-A[i].len)%60,A[i].ed/60,A[i].ed%60);
	}
}
int main() {
	scanf("%d",&N);
	A.resize(N);  
	for(int i=0;i<N;i++){
		int a,b,c,d;
		scanf("%d:%d %d:%d %d",&a,&b,&c,&d,&A[i].len);
		A[i].st=a*60+b;
		A[i].ed=c*60+d;
	} 
	Solve();          
	return 0;
}
/*
2
08:00 09:00 30
08:15 09:00 20
*/
