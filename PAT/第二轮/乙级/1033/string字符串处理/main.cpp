#include<bits/stdc++.h>
using namespace std; 
bitset<128> mp; 
int main() {
	string s,s1;
	getline(cin,s);
	getline(cin,s1);
	if(s.find('+')!=string::npos){
		for(int i=0;i<s1.size();i++){
		//	cout<<s1[i]<<endl;
			if(isupper(s1[i]))
				s1.erase(i--,1); //2020/1/21/21:07发现改正，这里删除后i要减一：i-- 
		//	cout<<s1[i]<<endl;
		} 
	}
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
7_TThis_is_a_test.
*/
