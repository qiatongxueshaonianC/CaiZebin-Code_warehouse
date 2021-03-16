#include<bits/stdc++.h>
using namespace std; 
bool judge(string s){
	if(s.find('l')!=string::npos||s.find('1')!=string::npos) return true;
	if(s.find('O')!=string::npos||s.find('0')!=string::npos) return true;
	return false;
}
int main() {
	vector<pair<string,string>> ans;
	vector<pair<string,regex>>trans={{"L",regex("l")},{"@",regex("1")},
	{"o",regex("O")},{"%",regex("0")}};
	int n;
	string name,pass;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>name>>pass;
		if(judge(pass)){
			for(auto i:trans)
				pass=regex_replace(pass,i.second,i.first);
			ans.push_back({name,pass});
		}
	}
	if(ans.size()>0) {
		printf("%d\n",ans.size());
		for(auto i:ans)
			printf("%s %s\n",i.first.c_str(),i.second.c_str());
	}else if(n>1)
		printf("There are %d accounts and no account is modified\n",n);
	else 
		printf("There is 1 account and no account is modified\n");
	return 0;
}
/*
3
Team000002 Rlsp0dfa
Team000003 perfectpwd
Team000001 R1spOdfa

1
team110 abcdefg332

2
team110 abcdefg222
team220 abcdefg333
*/
