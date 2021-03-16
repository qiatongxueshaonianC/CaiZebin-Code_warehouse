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
const int maxn=1000000+5;
const int MOD=1e9+7;
const int P=1e7+19;
typedef long long LL;
string p,txt;
int main() {
	std::ios::sync_with_stdio(false);		//只对G++有用！！！！！ c++的cin比G++的快 
	int t;
	cin>>t;
	while(t--){
		int ans=0;
		cin>>p>>txt;
		LL M=1,pH=0,tH=0;
		for(int i=0;i<p.size();i++){
			M*=P;
			pH=pH*P+p[i];
			tH=tH*P+txt[i];
		}
		int len=p.size();
		for(int i=0;i+len<=txt.size();i++){
			if(pH==tH)
				ans++;
			tH=tH*P+txt[i+len]-txt[i]*M;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
3
BAPC
BAPC
AZA
AZAZAZA
VERDI
AVERDXIVYERDIAN
*/
