#include<bits/stdc++.h>
using namespace std; 
int main() {
	bitset<128> hash;
	string s,s1;
	getline(cin,s);
	getline(cin,s1); 
	transform(s.begin(),s.end(),s.begin(),::toupper);
	transform(s1.begin(),s1.end(),s1.begin(),::toupper);
	for(auto i:s){
		if(hash[i]==0){
			hash[i]=1;
			if(s1.find(i)==string::npos)
				printf("%c",i);
		}
	}
	return 0;
}
/*
7_This_is_a_test
_hs_s_a_es
*/
