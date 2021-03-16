#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<climits>
#include<numeric>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<fstream>
#include<ctime>
#include<iomanip>
#include<iterator>
#define lowbit(x) x&(-x)
using namespace std; 
typedef long long ll;
const int maxn=100005;
ll sum[maxn];
ll N,S,v;
int main() {
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		memset(sum,0,sizeof(sum));
		cin>>N>>S;
		for(int i=1;i<=N;i++){
			cin>>v;
			sum[i]=sum[i-1]+v;
		}
		if(sum[N]<S){
			cout<<"0"<<endl;
			continue;
		}
		int l=1,r,ans;
		ans=lower_bound(sum+1,sum+N+1,S)-sum;
		r=ans;
		while(r<=N){
			while(sum[r]-sum[l-1]>=S){
				ans=min(ans,r-l+1);
				l++;
			}
			r++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
2
10 15
5 1 3 5 10 7 4 9 2 8
5 11
1 2 3 4 5
*/
