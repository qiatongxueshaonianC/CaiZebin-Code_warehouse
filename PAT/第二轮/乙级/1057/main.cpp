#include<bits/stdc++.h>
using namespace std; 
string trans(int a){
	string A="";
	do{
		A+=(a%2+'0');
		a/=2;
	}while(a!=0);
	return A;
}
int main() {
	string s;
	getline(cin,s);
	transform(s.begin(),s.end(),s.begin(),::tolower);
	s=regex_replace(s,regex("[^a-z]"),"");
	int mp[129]={0},ans=0;
	for(int i=1;i<=26;i++)
		mp[i-1+'a']=i; 
	for(auto i:s)
		ans+=mp[i];
	if(ans==0)
		puts("0 0");
	else{
		string A=trans(ans);
		printf("%d %d",count(A.begin(),A.end(),'0'),count(A.begin(),A.end(),'1'));	
	}
	return 0;
}
/*
PAT (Basic)
*/
