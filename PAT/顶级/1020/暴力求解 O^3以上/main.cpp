#include<bits/stdc++.h>
using namespace std; 
set<string> st;
string s;
int ans=2;
int main() {
	getline(cin,s);
	for(int i=1;i<s.size();i++){  //ɾһ�� 
		if(s[i]!=s[i-1])
			ans++;
	}
	string s1,s2,s3,S;
	for(int i=0;i<s.size();i++){
		for(int j=i+1;j<s.size();j++){
			s1=s.substr(0,i);
			s2=s.substr(i+1,j-(i+1));
			s3=s.substr(j+1,s.size()-(j+1));
			S=s1+s2+s3;
			st.insert(S);
		}
	} 
	printf("%d\n",ans+st.size());
	return 0;
}
/*
ababcc
*/
