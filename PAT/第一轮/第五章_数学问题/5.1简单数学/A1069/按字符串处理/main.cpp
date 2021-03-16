#include<bits/stdc++.h>
using namespace std; 
void addZero(string &s){
	while(s.size()<4)
		s+='0';
}
int main() {
	string s1,s2,pre="100000";
	getline(cin,s1);
	while(s1!=s2){
		addZero(s1);
		sort(s1.begin(),s1.end());
		s2=s1; 
		reverse(s2.begin(),s2.end());
		int num=stoi(s2)-stoi(s1);
		if(stoi(pre)==num) 
			break;
		printf("%s - %s = %04d\n",s2.c_str(),s1.c_str(),num);
		pre=to_string(num);
		s1=pre;
	}
	return 0;
}
/*
6767
1221
*/
