#include<bits/stdc++.h>
using namespace std;
string s1,s2; 
vector<pair<regex,string>>trans;
bool harsh[256];
int main() {
	getline(cin,s1);
	getline(cin,s2); 
//	cin>>s2;
	for(auto i:s2){
		if(harsh[i]==false&&i!='*'&&i!='+'&&i!='('){
			string tp="";
			tp+=i;
			trans.push_back({regex((tp)),""});  //可能是正则表达式遇到了特殊字符,导致运行时错误 
			harsh[i]=true;
		//	puts(tp.c_str());
		}
	}
	trans.push_back({regex("\\\\"),""});
	trans.push_back({regex("\\*"),""});
	trans.push_back({regex("\\^"),""});
	trans.push_back({regex("\\+"),""});
	trans.push_back({regex("\\("),""});
	trans.push_back({regex("\\["),""});
	for(auto i:trans){
		s1=regex_replace(s1,i.first,i.second);
	}
	puts(s1.c_str());
	return 0;
}
/*
Thee*y are students.
aeio*u s

They are students.
aeiou
*/
