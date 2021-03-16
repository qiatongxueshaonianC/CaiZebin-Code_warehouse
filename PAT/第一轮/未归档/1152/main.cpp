#include<bits/stdc++.h>
using namespace std;
bool isPrime(long long s){
	if(s<=1) return false;
	int sqr=(int)sqrt(s*1.0);
	for(int i=2;i<=sqr;i++){
		if(s%i==0)
			return false;
	}
	return true;
} 
int main() {
	string s;
	int n,k;
	scanf("%d%d%*c",&n,&k);
	getline(cin,s);
//	cin>>n>>k>>s;
	bool flag=true;
	for(int i=0;i+k-1<s.size();i++){
		long long ans=stoll(s.substr(i,k));
		if(isPrime(ans)){
		//	printf("%lld\n",ans);
			puts(s.substr(i,k).c_str());  //2019/12/5/22:13发现，即使有前导0也要输出 
			flag=false;
			break;
		}
	}
	if(flag)
		puts("404");
	return 0;
}
/*
20 5
23654987725541023819

10 3
2468024680

6 4
200236
*/
