#include<bits/stdc++.h>
using namespace std;
string add(string s1,string s2){
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	int c=0,numA,numB,len=max(s1.size(),s2.size());
	string ans;
	for(int i=0;i<len;i++){
		numA=i<s1.size()?s1[i]-'0':0;
		numB=i<s2.size()?s2[i]-'0':0;
		ans+=(numA+numB+c)%10+'0';
		c=(numA+numB+c)/10;
	}
	while(c!=0){
		ans+=c%10+'0';
		c/=10;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
int main() {
	string s1,s2,sum;
	getline(cin,s1);
	s2=s1;
	reverse(s2.begin(),s2.end());
	int idx=0,flag=s1==s2?1:0;
	while(s1!=s2&&idx++<10){
		sum=add(s1,s2);
		printf("%s + %s = %s\n",s1.c_str(),s2.c_str(),sum.c_str());
		s2=s1=sum;
		reverse(s2.begin(),s2.end());
		flag=s1==s2?1:0;
	}
	if(flag==1)
		printf("%s is a palindromic number.",s1.c_str());
	else
		puts("Not found in 10 iterations.");
	return 0;
}
/*
97152

196
*/
