#include<bits/stdc++.h>
using namespace std;
string add(string s1,string s2,string radix){
	string ans="";
	reverse(radix.begin(),radix.end());
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	int len=max(s1.size(),s2.size()),c=0;
	for(int i=0;i<len||c!=0;i++){
		int r=i>=20?10:radix[i]=='0'?10:radix[i]-'0';
		int numA=i<s1.size()?s1[i]-'0':0;
		int numB=i<s2.size()?s2[i]-'0':0;
		ans+=(numA+numB+c)%r+'0';
		c=(numA+numB+c)/r;
	}
	while(ans.back()=='0'&&ans.size()>1) ans.pop_back();
	reverse(ans.begin(),ans.end());
//	while(ans[0]=='0'&&ans.size()>1) ans.erase(0,1);
	return ans;
}
int main() {
	string s1,s2,radix;
	getline(cin,radix);
	getline(cin,s1);
	getline(cin,s2);
	puts(add(s1,s2,radix).c_str()); 
	return 0;
}
/*
30527
06203
415
*/
