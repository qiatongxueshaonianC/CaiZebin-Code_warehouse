#include<bits/stdc++.h>
using namespace std;
int main() {
	string s,c,ans="";
	getline(cin,c);
	getline(cin,s);
	if(c=="C"){
		for(int i=0;i<s.size();){
			int k=s.find_first_not_of(s[i],i);
			k=k==string::npos?s.size():k;
			if(k-i>1)
				ans+=to_string(k-i)+s[i];
			else ans+=s[i];
			i=k;
		}
	}else{
		for(int i=0;i<s.size();i++){
			if(!isdigit(s[i])) ans+=s[i];
			else{
				int k=s.find_first_not_of("0123456789",i);
				int temp=stoi(s.substr(i,k-i));
				ans+=string(temp-1,s[k]);
				i=k-1;
			}
		}
	}
	puts(ans.c_str());
//	puts("5T2h4is i5s a3 te4st CA3a as10Z");
	return 0;
}
/*
C
TTTTThhiiiis isssss a   tesssst CAaaa as

C
TTTTThhiiiis isssss a   tesssst CAaaa asZZZZZZZZZZ

D
5T2h4is i5s a3 te4st CA3a as10Z
*/
