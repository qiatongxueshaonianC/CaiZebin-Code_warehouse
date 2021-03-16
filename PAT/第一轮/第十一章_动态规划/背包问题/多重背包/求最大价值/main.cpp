#include"cstdio"
#include"cstring"
using namespace std;
const int MAXN=100005;
int dp[MAXN];
int n,m;
int A[MAXN];
int C[MAXN];
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF&&(n||m))
    {
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)    scanf("%d",&A[i]);
        for(int i=0;i<n;i++)    scanf("%d",&C[i]);
        dp[0]=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<=m;j++)
                if(dp[j]>=0)
                {
                    dp[j]=C[i];
                }
                else if(j<A[i]||dp[j-A[i]]<=0)
                {
                    dp[j]=-1;
                }
                else
                {
                    dp[j]=dp[j-A[i]]-1;
                }
        int ans=0;
        for(int i=1;i<=m;i++)
            if(dp[i]>=0)    ans++;
        printf("%d\n",ans);
    }
    
    return 0;
}
/*
3 10
1 2 4 2 1 1
2 5
1 4 2 1
0 0
*/
