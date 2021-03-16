#include<bits/stdc++.h>
using namespace std; 
bool judge(string s){
	for(int i=0,j=s.size()-1;j>=i;i++,j--){
		if(s[i]!=s[j])
			return false;
	}
	return true;
}
string add(string a,string b){
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	int c=0;
	for(int i=0;i<a.size();i++){
		int temp=a[i]-'0'+b[i]-'0'+c;
		a[i]=temp%10+'0';
		c=temp/10;
	}
	if(c!=0) a+=to_string(c);
	reverse(a.begin(),a.end());
	return a;
}
int main() {
	string s,str,sum_s;
	getline(cin,s);
	while(s[0]=='0'&&s.size()>1)
		s.erase(s.begin());
	if(judge(s)){
		printf("%s is a palindromic number.\n",s.c_str());
		return 0;
	}
	bool flag=false;
	for(int i=0;i<10;i++){
		str=s;
		reverse(str.begin(),str.end());
		sum_s=add(s,str);
		printf("%s + %s = %s\n",s.c_str(),str.c_str(),sum_s.c_str());
		if(judge(sum_s)){
			printf("%s is a palindromic number.\n",sum_s.c_str());
			flag=true;
			break;
		}
		s=sum_s;
	}
	if(!flag)
		puts("Not found in 10 iterations.");
	return 0;
}
/*
97152

196
*/
