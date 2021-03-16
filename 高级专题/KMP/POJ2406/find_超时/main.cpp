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
string s;
int main() {
    std::ios::sync_with_stdio(false);
	while(getline(cin,s)&&s!="."){
		string s1="";
		for(int i=0;i<s.size();i++){
			int ans=0,pos=0;
			s1+=s[i];
			int len=s1.size();
			if(s.size()%len!=0)
				continue; 
			while(s.substr(pos,len)==s1){
				ans++;
				pos+=len;
			}
			if(pos==s.size()){
				cout<<ans<<'\n';
				break;
			}
		}
	} 
	return 0;
}
/*
abcd
aaaa
ababab
.
*/
