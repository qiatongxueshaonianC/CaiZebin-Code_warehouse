#include<bits/stdc++.h>
using namespace std; 
string cal(string a,string b){
	int carry=0;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for(int i=0;i<a.size();i++){ //本题a与b的长度一定相同 
		char tp=(a[i]-'0'+b[i]-'0'+carry)%10+'0'; 
		carry=(a[i]-'0'+b[i]-'0'+carry)/10;
		a[i]=tp;
	}
	if(carry!=0) a+=to_string(carry);
	reverse(a.begin(),a.end());
	return a;
}
int main() {
	int b,step;
	string s1,s2; 
	cin>>s1>>b;
	for(step=0;step<b;step++){
		s2=s1;
		reverse(s2.begin(),s2.end());
		if(s1==s2) break;
		s1=cal(s1,s2);
	}
	puts(s1.c_str());
	printf("%d",step);
	return 0;
}
/*
67 3

69 3
*/
