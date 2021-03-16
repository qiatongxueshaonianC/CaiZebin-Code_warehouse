#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	getline(cin,s);
	map<int,int> mp;
	for(auto i:s)
		mp[i-'0']++;
	for(auto i:mp)
		printf("%d:%d\n",i.first,i.second);
}
/*
100311
*/
