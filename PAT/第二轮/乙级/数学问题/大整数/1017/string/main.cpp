#include<bits/stdc++.h>
using namespace std;
string s; 
string div(string s,int d,int& r){
	string ans="";
	char c;
	for(int i=0;i<s.size();i++){
		r=r*10+(s[i]-'0');
		if(r>=d){
			ans+=(r/d+'0');
			r=r%d;
		}
		else
			ans+='0';
	}
	while(ans.size()>=2&&ans[0]=='0')
		ans.erase(ans.begin());
	return ans;
}
int main() {
	int d,r=0;
	cin>>s>>d;
	string ans=div(s,d,r);
	printf("%s %d",ans.c_str(),r);
}
/*
123456789050987654321 7
*/
