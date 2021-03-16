#include<bits/stdc++.h>
using namespace std;
bool isPrime(int a){
	if(a<=1) return false;
	int sqr=(int)sqrt(1.0*a);
	for(int i=2;i<=sqr;i++){
		if(a%i==0) 
			return false;
	}
	return true;
} 
int main() {
	int Tmax,n,m,v,ans=0;
	scanf("%d%d%d",&Tmax,&n,&m);
	while(!isPrime(Tmax)){
		Tmax++;
	}
	int table[Tmax]={0};
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		int a=v%Tmax,k=1;
		for(;table[a]!=0&&k<Tmax;a=(v+k*k)%Tmax,k++); //2019/12/5/0:58发现，改正
		if(table[a]!=0)
			printf("%d cannot be inserted.\n",v);
		else 
			table[a]=v;
	}
	for(int i=0;i<m;i++){
		scanf("%d",&v);
		int a=v%Tmax,k=1;
		//table[a]==0说明这个数不在哈希表中 
	//	for(;table[a]!=0&&table[a]!=v&&k<=Tmax;a=(a+k*k)%Tmax,k++); //2019/12/5/0:58发现，改正
		for(;table[a]!=0&&table[a]!=v&&k<=Tmax;a=(v+k*k)%Tmax,k++); //这里是v不是k!! 
		ans+=k;														//这里的k是<=Tmax 
	}
	printf("%.1lf",ans*1.0/m); 
	return 0;
}
/*
4 5 4
10 6 4 15 11
11 4 15 2
*/
