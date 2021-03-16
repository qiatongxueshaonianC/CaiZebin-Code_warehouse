#include<bits/stdc++.h>
using namespace std; 
int harsh[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
string mp="10X98765432";
int main() {
	int n,valid=0,weight;
	string s;
	scanf("%d%*c",&n);
	for(int i=0;i<n;i++){
		getline(cin,s);
		int k=s.find_first_not_of("0123456789");
		weight=0; 
		for(int i=0;i<s.size()-1;i++)
			weight+=(s[i]-'0')*harsh[i];
		if(mp[weight%11]!=s[s.size()-1])
			puts(s.c_str());
		else valid++;
	}
	if(valid==n)
		puts("All passed");
	return 0;
}
/*
4
320124198808240056
12010X198901011234
110108196711301866
37070419881216001X

2
320124198808240056
110108196711301862
*/
