#include<bits/stdc++.h>
using namespace std; 
bitset<128> mp; 
int main() {
	string s,s1;
	getline(cin,s);
	getline(cin,s1);
	transform(s.begin(),s.end(),s.begin(),::toupper);
	if(s.find('+')!=string::npos)
		s1=regex_replace(s1,regex("[A-Z,+]"),""); 
//	puts(s1.c_str());
	for(auto i:s){
		if(mp[i]==0){
			mp[i]=1;
			string s(1,i);
			if(i=='.')
				s.assign("\\.");
			else if(i=='+')
				s.assign("\\+");	
			s1=regex_replace(s1,regex(s),"");
			if(i!='+'&&i!='.'&&i!=','){
				s.assign(1,tolower(i));
				s1=regex_replace(s1,regex(s),"");	
			}
		}
	}
	puts(s1.c_str());	
	return 0;
}
/*
7+IE.
7_TTh+++is_is_a_test.
*/
