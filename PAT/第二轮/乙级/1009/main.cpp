#include<bits/stdc++.h>
using namespace std; 
int main() {
	string s;
	getline(cin,s);
	stringstream str(s);
	vector<string> ans;
	while(str>>s){
		ans.push_back(s);
	}
	reverse(ans.begin(),ans.end());
	for(vector<string>::iterator i=ans.begin();i!=ans.end();i++)
		printf("%s%s",(*i).c_str(),i==--ans.end()?"":" ");
	return 0;
}
/*
Hello World Here I Come
*/
