#include<bits/stdc++.h>
using namespace std; 
bool isPrime(long long a){
	if(a<=1) return false;
	int sqr=(int)sqrt(1.0*a);
	for(int i=2;i<=sqr;i++){
		if(a%i==0)
			return false;
	}
	return true;
}
int main() {
	int N,K;
	scanf("%d%d%*c",&N,&K);
	string s;
	getline(cin,s);
	bool flag=false;
	for(int i=0;i+K<=s.size();i++){
		long long temp=stoll(s.substr(i,K));
		if(isPrime(temp)){
			puts(s.substr(i,K).c_str());
		//	printf("%ld\n",temp);  //����ǰ����ҲҪ������� 
			flag=true;
		}
		if(flag) break;
	}
	if(flag==false)
		puts("404");
	return 0;
}
/*
100 5
0000100002

20 5
23654987725541023819

10 3
2468024680
*/
