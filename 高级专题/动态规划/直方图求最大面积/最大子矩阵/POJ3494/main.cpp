#include<iostream>
#include<cstdio>
#include<cmath>
#include<stack>
using namespace std;
const int maxn=2010;
int G[maxn][maxn],data[maxn][maxn];
int m,n;
int Solve(int row){
	stack<int> stk;
	stk.push(0);
	int ans=0;
	for(int i=1;i<=n;i++){
		while(data[row][i]<data[row][stk.top()]){
			int height=data[row][stk.top()];stk.pop();
			int width=i-stk.top()-1;
			int temp=height*width;
			if(temp>ans)
				ans=temp;
		}
		stk.push(i);	//ע�⣺stack������±� 
	}
	return ans;
}
int main() {
    while(scanf("%d%d",&m,&n)==2){
    	for(int i=1;i<=m;i++){
    		for(int j=1;j<=n;j++){
    			scanf("%d",&G[i][j]);
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(G[i][j]==1)
					data[i][j]=data[i-1][j]+1;
				else
					data[i][j]=0;
			}
			data[i][n+1]=0;
		}
		n++;
		int ans=0; 
		for(int i=1;i<=m;i++){
			ans=max(ans,Solve(i));
		}
		printf("%d\n",ans);
	}
    return 0;
}
/*
4 4
0 1 0 1
1 1 1 0
1 1 1 1
1 0 1 0
*/

