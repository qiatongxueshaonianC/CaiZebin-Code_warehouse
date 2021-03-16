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
int T; 
string s,s1;
int main() {
	
    std::ios::sync_with_stdio(false);
	cin>>T; 
//	scanf("%d",&T);
	while(T--){
		cin>>s1>>s;
		int ans=0,k=0,j=0;
		k=s.find(s1);
		while(k!=string::npos){
			ans++;
			j=k+1;
			k=s.find(s1,j);
		}
		printf("%d\n",ans);
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
