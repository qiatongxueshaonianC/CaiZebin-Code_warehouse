#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,valid=0;
	pair<string,string> old=make_pair("","20140906"),young={"","18140906"};
	string s1,s2,s="20140906",ss="18140906";
	regex r("/");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>s1>>s2;
		s2=regex_replace(s2,r,"");
		if(s2>s||s2<ss)
			continue;
		if(s2<=old.second){
			old.first=s1;
			old.second=s2;
		}
	    if(s2>=young.second){
			young.first=s1;
			young.second=s2;
		} 
		valid++;
	}
	printf("%d",valid);
	if(valid>0)
		 printf(" %s %s",old.first.c_str(),young.first.c_str());
}
/*
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20
*/
