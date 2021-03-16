#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 20;
int d[N][N], p[N], q[N], mark[N][N];

void print_ans(int i, int j){
	if(i == j){  printf("A%d",i+1); return; }
	printf("(");
	print_ans(i, mark[i][j]);
	printf(" x ");
	print_ans(mark[i][j]+1, j);
	printf(")");
}

int f(int i, int j){
	int& ans = d[i][j];
	if(ans < INF) return ans; 
	for(int k = i; k < j; ++k){ // 没有等于！！ 
		if( ans > f(i,k) + f(k+1,j) + p[i]*q[k]*q[j] ){
			ans = f(i,k) + f(k+1,j) + p[i]*q[k]*q[j];
			mark[i][j] = k;
		}
	}
	return ans;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int n, kase = 1;
   	while(scanf("%d",&n) == 1&&n){
   		memset(d,0x3f,sizeof(d));
   		memset(mark,0,sizeof(mark));
   		
		for(int i = 0; i < n; ++i){
			scanf("%d %d",&p[i],&q[i]);
			d[i][i] = 0; 
		}
		
		// 递推
		for(int len = 1; len <= n; ++len){// 枚举链乘长度（区间长度）
			for(int i = 0; i <= n-len; ++i) // 枚举区间起点
				for(int k = i; k < i+len-1; ++k){ // 枚举区间内最后乘法位置 
					int t = d[i][k] + d[k+1][i+len-1] + p[i]*q[k]*q[i+len-1];
					if(d[i][i+len-1] > t){
						d[i][i+len-1] = t;
						mark[i][i+len-1] = k;
					}
				} 
		}
		 
		
		//int ans = f(0,n-1);
		//printf("%d\n",ans);
		printf("Case %d: ",kase++);
		print_ans(0,n-1);
		printf("\n");
	}

	return 0;
}
/*
3
1 5
5 20
20 1
3
5 10
10 20
20 35
6
30 35
35 15
15 5
5 10
10 20
20 25
0
*/


