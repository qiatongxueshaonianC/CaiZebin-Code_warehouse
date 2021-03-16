#include<iostream>
#include<vector>
#include<cstdio>
using namespace std; 
const int maxn=6010;
int N,Value[maxn],dp[maxn][2];
vector<vector<int> >G(maxn);
bool have_father[maxn],vis[maxn][2];
int DP(int root,bool father_go,int father){
	if(vis[root][father_go])
		return dp[root][father_go];
	vis[root][father_go]=true;
	int ans=0;	//��ǰ�㲻ȥ����ʼֵΪ0 
	for(int i=0;i<G[root].size();i++){	//��ǰ�㲻ȥ 
		ans+=DP(G[root][i],false,root); 
	}
	if(father<0||(father>=0&&father_go==false)){	//��ǰ�ڵ�ȥ��������Ϊ�������߸��׽ڵ�ûȥ 
		int sum=Value[root];	//��ǰ��ȥ����ʼ��ֵΪValue[root] 
		for(int i=0;i<G[root].size();i++){
			sum+=DP(G[root][i],true,root);
		}
		ans=max(ans,sum);
	}
	return dp[root][father_go]=ans;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>Value[i];
	}
	int u,v;
	while(cin>>u>>v&&(u*v)){
		G[v].push_back(u);
		have_father[u]=true;
	}
	int root=0;
	for(int i=1;i<=N;i++){
		if(have_father[i]==false){
			root=i;
			break;
		}
	}
	cout<<DP(root,0,-1)<<endl;
	return 0;
}
/*
7
1
1
1
1
1
1
1
1 3
2 3
6 4
7 4
4 5
3 5
0 0
*/
