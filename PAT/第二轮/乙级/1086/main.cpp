#include<bits/stdc++.h>
using namespace std;
int main() {
	int a,b;
	scanf("%d%d",&a,&b);
	string s=to_string(a*b);
	reverse(s.begin(),s.end());
	printf("%d",stoi(s));
/*	string::iterator it=--s.end();
	int idx=s.size()-1;
	while(s[idx]=='0') idx--;
	while(idx>=0)
		printf("%c",s[idx--]);*/
	return 0;
}
/*
1000 1000
*/
