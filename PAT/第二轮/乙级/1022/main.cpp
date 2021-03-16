#include<bits/stdc++.h>
using namespace std;
string change(long long a,long long c){
	string ans="";
	do{
		char d=(a%c+'0');
		ans=d+ans;
		a/=c;
	}while(a!=0);
	return ans;
}
int main() {
	long long a,b,c;
	scanf("%lld%lld%lld",&a,&b,&c);
	a=a+b; 
	printf("%s",change(a,c).c_str());
}
/*
123 456 8
*/
