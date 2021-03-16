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
int nxt[maxn];
void getNext(string s){
	int j=-1;
	nxt[0]=-1;
	for(int i=1;i<s.size();i++){
		while(j!=-1&&s[i]!=s[j+1])
			j=nxt[j];
		if(s[i]==s[j+1])
			j++;
		nxt[i]=j;
	}
}
bool KMP(string s,string pt){
	getNext(pt);
	int j=-1;
	for(int i=0;i<s.size();i++){
		while(j!=-1&&s[i]!=pt[j+1])
			j=nxt[j];
		if(s[i]==pt[j+1])
			j++;
		if(j==pt.size()-1)
			return true;
	}
	return false;
}
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
			if(KMP(s,p[i]))
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
