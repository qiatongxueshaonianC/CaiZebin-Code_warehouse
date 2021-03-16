#include<bits/stdc++.h>
using namespace std; 
bitset<10010> harsh;
bool isPrime(int n){
	if(n<=1) return false;
	int sqr=(int)sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){
		if(n%i==0) 
			return false;
	}
	return true;
}
int main() {
	int Msize,n,v;
	scanf("%d%d",&Msize,&n);
	if(isPrime(Msize)==false){
		do{
			Msize++;
		}while(isPrime(Msize)==false);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		if(harsh[v%Msize]==0){
			harsh.set(v%Msize);
			printf("%d%s",v%Msize,i==n-1?"":" ");
		}else{
			bool flag=false;
			for(int j=1;j<Msize;j++){
				if(harsh[(v+j*j)%Msize]==0){
					harsh.set((v+j*j)%Msize);
					printf("%d%s",(v+j*j)%Msize,i==n-1?"":" ");
					flag=true;break;
				}
			}
			if(!flag) 
				printf("-%s",i==n-1?"":" ");
		}
	}
	return 0;
}
/*
4 4
10 6 4 15
*/
