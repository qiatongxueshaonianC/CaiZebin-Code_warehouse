#include<bits/stdc++.h>
using namespace std; 
bool isPrime(int n){
	if(n<=1) return false;    //201*//11/20/16:51发现，注意这里要特判 
	int sqr=(int)sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){
		if(n%i==0) return false;
	}
	return true;
}
int trans(int n,int radix){
	vector<int> temp;
	int ans=0;
	do{
		temp.push_back(n%radix);
		n=n/radix;
	}while(n!=0);
	for(auto i:temp)   //包含了反转 
		ans=ans*radix+i;
	return ans;
}
int main() {
	int n,radix;
	while(scanf("%d",&n)&&n>=0){
		scanf("%d",&radix);
		if(isPrime(n)==false) puts("No");
		else if(isPrime(trans(n,radix))==true) puts("Yes");
		else puts("No");
	}
	return 0;
}
/*
73 10
23 2
23 10
-2
*/
