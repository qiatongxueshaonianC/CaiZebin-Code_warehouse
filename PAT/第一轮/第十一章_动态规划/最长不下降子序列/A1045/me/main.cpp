#include<bits/stdc++.h>
using namespace std; 
const int inf=0x3fffffff;
unordered_map<int,int> mp;
vector<int> A;
int dp[10010],ans;
int main() {
	int n,m,v,index=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d",&v);
		mp[v]=index++; 
	}
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		if(mp.find(v)!=mp.end())
			A.push_back(mp[v]);
		else A.push_back(-1);    //2019/11/24/15:00���ִ������ﲻ�ܸ�ֵ��һ������  ��ȫ���ӽ�������õ� 
	//	else A.push_back(inf);
	}
	for(int i=0;i<n;i++){
		if(A[i]<0) continue;    //2019/11/24/15:20���ֲ����� 
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(A[i]>=A[j]&&dp[i]<=dp[j]){
				dp[i]=dp[j]+1;
			/*	if(dp[i]>ans)  
					ans=dp[i]; */
			}
		}
		ans=max(dp[i],ans);    //2019/11/24/14:48����  
	}
	printf("%d\n",ans);
	return 0;
}
/*
6
5 2 3 1 5 6
12 2 2 4 1 5 5 6 3 1 1 5 6
*/
