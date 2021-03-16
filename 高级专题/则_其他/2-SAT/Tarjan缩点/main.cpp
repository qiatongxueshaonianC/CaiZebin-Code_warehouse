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
struct Node{
	static const int maxn=1e5*2+10;
	int S[maxn],T[maxn],D[maxn],N,cmp[maxn],num_cmp,idx[maxn],lowidx[maxn],dfs_num;
	bool used[maxn];
	vector<vector<int> >G;
	stack<int> stk;
	void init(){
		G.resize(maxn);
		num_cmp=dfs_num=0;
		memset(S,0,sizeof(S));
		memset(T,0,sizeof(T));
		memset(D,0,sizeof(D));
		memset(cmp,0,sizeof(cmp));
		memset(used,0,sizeof(used));
		memset(idx,0,sizeof(idx));
		memset(lowidx,0,sizeof(lowidx));
	}
	void Read(){
		init();
		scanf("%d",&N);
		for(int i=0;i<N;i++){
			int a,b,c,d;
			scanf("%d:%d %d:%d %d",&a,&b,&c,&d,&D[i]);
			S[i]=a*60+b;
			T[i]=c*60+d;
		}
	}
	void Insert_edge(int from,int to){
		G[from].push_back(to);
	}
	void Tarjan(int u){
		idx[u]=lowidx[u]=++dfs_num;
		stk.push(u);
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i];
			if(idx[v]==0){
				Tarjan(v);
				lowidx[u]=min(lowidx[u],lowidx[v]);
			}else if(cmp[v]==0){
				lowidx[u]=min(lowidx[u],idx[v]);
			}
		}
		if(lowidx[u]==idx[u]){
			int t=0;
			num_cmp++;
			do{
				t=stk.top();stk.pop();
				cmp[t]=num_cmp;	//是逆序的拓扑排序 
			}while(t!=u); 
		}
	}
	void Solve(){
		for(int i=0;i<N;i++){
			for(int j=0;j<i;j++){
				if(min(S[i]+D[i],S[j]+D[j])>max(S[i],S[j])){
					//(xi^xj)==0 ~xiV~xj==1
					Insert_edge(i,j+N);
					Insert_edge(j,i+N);
				}
				if(min(S[i]+D[i],T[j])>max(S[i],T[j]-D[j])){
					//(xi^~xj)==0
					Insert_edge(i,j);
					Insert_edge(j+N,i+N);
				}
				if(min(T[i],S[j]+D[j])>max(T[i]-D[i],S[j])){
					//(~xi^xj)==0
					Insert_edge(i+N,j+N);
					Insert_edge(j,i);
				}
				if(min(T[i],T[j])>max(T[i]-D[i],T[j]-D[j])){
					//(~xi^~xj)==0
					Insert_edge(i+N,j);
					Insert_edge(j+N,i);
				}
			}
		}
		for(int i=0;i<2*N;i++){		//注意，这里要对所有的点做Tarjan，是到2*N； 
			if(idx[i]==0){
				Tarjan(i); 
			} 
		}
		for(int i=0;i<N;i++){
			if(cmp[i]==cmp[i+N]){
				puts("NO");
				return;
			}
		}
		puts("YES");
		for(int i=0;i<N;i++){
			if(cmp[i]<cmp[i+N]){	//是逆序的，实际上是cmp[i]的拓扑序列在cmp[i+N]之后 ,即xi为“真” 
				printf("%02d:%02d %02d:%02d\n",S[i]/60,S[i]%60,(S[i]+D[i])/60,(S[i]+D[i])%60);
			}
			else{
				printf("%02d:%02d %02d:%02d\n",(T[i]-D[i])/60,(T[i]-D[i])%60,T[i]/60,T[i]%60);
			}
		}
	}
}A;
int main() {
//	Node A; 	//注意！！！！，A里面的数组开的太大了，要写在外面，否则会显示段错误 
	A.Read();
	A.Solve();       
	return 0;
}
/*
2
08:00 09:00 30
08:15 09:00 20
*/
