#include<bits/stdc++.h>
using namespace std; 
int main() {
	/*
	for(int i=1;i<=n;++i)//长度
        for(int j=1;j+i<=n+1;++j)//起点
        {
            int e=j+i-1;
            for(int k=j;k<e;++k)//分割点
            {
                dp1[j][e]=min(dp1[j][k]+dp1[k+1][e]+sum[e]-sum[j-1],dp1[j][e]);
            }
        }
    */
    
	
		
    /*	
	    void read()
	{
	    memset(dp1,0x3f,sizeof(dp1));
	    red(n);
	    for(int i=1;i<=n;++i)
	    {
	        red(a[i]);
	        a[i+n]=a[i];
	    }
	}
	void work()
	{
	    for(int i=1;i<=2*n;++i)
	    {
	        sum[i]=sum[i-1]+a[i];
	        dp1[i][i]=0;
	    }
	    for(int i=1;i<=n;++i)
	        for(int j=1;j+i<2*n;++j)
	        {
	            int e=j+i-1;
	            for(int k=j;k<e;++k)
	            {
	                dp1[j][e]=min(dp1[j][k]+dp1[k+1][e]+sum[e]-sum[j-1],dp1[j][e]);
	                dp2[j][e]=max(dp2[j][k]+dp2[k+1][e]+sum[e]-sum[j-1],dp2[j][e]);
	            }
	        }
	    minn=INF;
	    for(int i=1;i<=n;++i)
	    {
	        minn=min(minn,dp1[i][i+n-1]);
	        maxx=max(maxx,dp2[i][i+n-1]);
	    }
	    printf("%d\n%d",minn,maxx);
	}
	*/
	
	
	
	
	
		/*
		void read()
	{
	    memset(dp1,0x3f,sizeof(dp1));
	    red(n);
	    for(int i=1;i<=n;++i)
	    {
	        red(a[i]);
	        a[i+n]=a[i];
	    }
	}
	void work()
	{
	    for(int i=1;i<=2*n;++i)
	    {
	        sum[i]=sum[i-1]+a[i];
	        dp1[i][i]=0;
	    }
	    for(int i=1;i<=n;++i)
	        for(int j=1;j+i<2*n;++j)
	        {
	            int e=j+i-1;
	            for(int k=j;k<e;++k)
	            {
	                dp1[j][e]=min(dp1[j][k]+dp1[k+1][e]+sum[e]-sum[j-1],dp1[j][e]);
	                dp2[j][e]=max(dp2[j][k]+dp2[k+1][e]+sum[e]-sum[j-1],dp2[j][e]);
	            }
	        }
	    minn=INF;
	    for(int i=1;i<=n;++i)
	    {
	        minn=min(minn,dp1[i][i+n-1]);
	        maxx=max(maxx,dp2[i][i+n-1]);
	    }
	    printf("%d\n%d",minn,maxx);
	}
	*/
	return 0;
}
