#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<climits>
#include<numeric>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<iterator>
using namespace std;
const int maxn=10005;
string p[maxn],s;
int main() {
	std::ios::sync_with_stdio(false);
	int T,n;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>p[i];
		cin>>s;
		int ans=0;
		for(int i=0;i<n;i++){
			if(s.find(p[i])!=string::npos)
				ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
1
5
she
he
say
shr
her
yasherhs
*/
