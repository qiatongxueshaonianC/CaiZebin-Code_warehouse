#include<bits/stdc++.h>
using namespace std; 
unordered_map<int,string> mp;
void init(){
	string s="0123456789ABC";
	for(int i=0;i<s.size();i++)
		mp[i]=s[i];
}
string change(int a){
	string ans="";
	ans+=mp[a/13];
	ans+=mp[a%13];
	return ans;
}
int main() {
	init();
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c); 
	string ans="";
	ans+=change(a);
	ans+=change(b);
	ans+=change(c);
	cout<<'#'<<ans<<endl;
	return 0;
}
/*
15 43 71

13 12 1
*/
