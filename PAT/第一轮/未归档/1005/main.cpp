#include<bits/stdc++.h>
using namespace std;
int main(){
	int ans;
	string s,trans[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    cin>>s;
    while(s.size()){
    	ans+=s[0]-'0';
    	s.erase(0,1);
	}
	s=to_string(ans);
	for(auto i=s.begin();i!=s.end();i++){
		printf("%s%s",trans[*i-'0'].c_str(),i!=--s.end()?" ":"\n");
	}
    return 0;
}
/*
12345
9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999
*/
