#include<bits/stdc++.h>
using namespace std; 
bitset<128> mp; 
int main() {
	string s,s1;
	getline(cin,s);
	getline(cin,s1);
	if(s.find('+')!=string::npos)
		s1=regex_replace(s1,regex("[A-Z,+]*"),"");
	transform(s.begin(),s.end(),s.begin(),::tolower);
	for(int i=0;i<s.size();i++){
		if(mp[s[i]]==0){
			mp.set(s[i]);
			string temp(1,s[i]),t(1,toupper(s[i]));
			temp=temp+t;
			int k,j=0;
			k=s1.find_first_of(temp,j);
			while(k!=string::npos){
				s1.erase(s1.begin()+k);
				j=k;
				k=s1.find_first_of(temp,j); 
			}
		}
	}
	puts(s1.c_str());	
	return 0;
}
/*
7+IE.
7_TTT+++++his_is_a_test.
*/
