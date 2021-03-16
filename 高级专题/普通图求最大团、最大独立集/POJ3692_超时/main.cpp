#include<iostream> 
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=420;
int G[maxn][maxn],mx,dp[maxn],Stack[maxn][maxn];
int GL,B,M,idx=1,N; 
bool DFS(int step,int total,int cnt){
	if(total==0){
		if(cnt>mx){
			mx=cnt;
			return true;
		}
		return false;
	}
	for(int i=0;i<total;i++){
		int u=Stack[step][i];
		if(cnt+total-i<=mx)  //��֦1����ǰ�����������������Լ�û�� ��ǰ�����Ž�� 
			return false;
		if(cnt+dp[u]<=mx)  //��֦2����ǰ��������֮ǰ�����������û�г������Ž� 
			return false;
		int sz=0;
		for(int j=i+1;j<total;j++){
			int v=Stack[step][j];
			if(G[u][v])
				Stack[step+1][sz++]=Stack[step][j];
		}
		if(DFS(step+1,sz,cnt+1)) //��֦3���������ؼ�֦���Ѿ����£�˵��dp[i]�Ѿ�����dp[i+1]+1�� 
			return true;		//����ֻ��������ŵ���������Ҫ��һ�����ţ���۸���С�����ܼ�֦ 
	}
}
int Max_clique(){
	mx=0;
	for(int i=N;i>0;i--){
		int sz=0;
		for(int j=i+1;j<=N;j++){
			if(G[i][j])
				Stack[1][sz++]=j;
		}
		DFS(1,sz,1);
		dp[i]=mx;	//i�ڵ�֮������е����ܴﵽ������� 
	}
	return mx;
}
void Solve(){
	memset(G,1,sizeof(G));
	memset(dp,0,sizeof(dp));
	memset(Stack,0,sizeof(Stack));
	int harsh[maxn][maxn]={false};
	for(int i=0;i<M;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		v+=GL;
		harsh[u][v]=true;
	}
	for(int i=1;i<=GL;i++){
		for(int j=GL+1;j<=N;j++){
			if(harsh[i][j]==false)
				G[i][j]=0;
		}
	}
	printf("Case %d: %d\n",idx++,Max_clique());
}
int main() {
	while(~scanf("%d%d%d",&GL,&B,&M)&&(GL+B+M)){
		N=GL+B;
		Solve();
	}
	return 0;
}
/*
2 3 3
1 1
1 2
2 3
2 3 5
1 1
1 2
2 1
2 2
2 3
0 0 0
*/
