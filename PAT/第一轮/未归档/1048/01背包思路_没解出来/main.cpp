#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
const int maxv=1010;
int n,sum,dp[maxn][maxv],w[maxn]; 
bool choice[maxn][maxv];
vector<pair<int,int>>ans;
bool cmp(int a,int b){
	return a>b;
}
int main() {
	scanf("%d%d",&n,&sum);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	sort(w+1,w+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=sum;j>=w[i];j--){  //选择用choice[][]就一定要从小到大 
			if(dp[i-1][j-w[i]]+w[i]>=dp[i-1][j]){
				dp[i][j]=dp[i-1][j-w[i]]+w[i];
				choice[i][j]=true;
			}else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	if(dp[n][sum]!=sum){
		puts("No Solution");
		return 0;
	}
	int k=n,num=0,j;
	while(1){
		k=n,j=sum;
		while(k>0&&j>0){
			if(choice[k][j]==true){
				ans.push_back({k,j});
				j-=w[k];
			}
			k--;
		}
		if(ans.size()==0){
			puts("No Solution!");
			break;
		}
		if(ans.size()>2||ans.size()<2){
			for(auto i:ans)
				choice[i.first][i.second]=0;
			ans.clear();
		}else {
			auto it=ans.begin();
			printf("%d ",w[it->first]);
			printf("%d",w[(++it)->first]);
			break;
		}
	}
	return 0;
}
/*
8 15
1 2 8 7 2 4 11 15
*/
