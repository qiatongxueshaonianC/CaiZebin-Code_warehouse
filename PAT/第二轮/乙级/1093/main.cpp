#include<bits/stdc++.h>
using namespace std; 
bitset<200> mp;
void output(string a){
	for(auto i:a){
		if(mp[i]==0){
			mp.set(i);
			printf("%c",i);
		}
	}
}
int main() {
	string a,b;
	getline(cin,a);
	getline(cin,b); 
	output(a);
	output(b);
	return 0;
}
/*
This is a sample test
to show you_How it works
*/
