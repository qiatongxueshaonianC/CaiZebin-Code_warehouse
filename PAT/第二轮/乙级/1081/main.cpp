#include<bits/stdc++.h>
using namespace std; 
int main() {
	int N;
	string s,str="0123456789.abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	scanf("%d%*c",&N);
	while(N--){
		getline(cin,s);
		if(s.size()<6)
			puts("Your password is tai duan le.");
		else if(s.find_first_not_of(str)!=string::npos)
			puts("Your password is tai luan le.");
		else if(s.find_first_of("0123456789")==string::npos)
			puts("Your password needs shu zi.");
		else if(s.find_first_of(str.substr(11))==string::npos)
			puts("Your password needs zi mu.");
		else puts("Your password is wan mei.");
	} 
	return 0;
}
/*
5
123s
zheshi.wodepw
1234.5678
WanMei23333
pass*word.6
*/
