#include<bits/stdc++.h>
using namespace std; 
int main() {
	int M,a,u,v;
	scanf("%d",&M);
	while(M--){
		scanf("%d",&a);
		bool f=1;
		for(int j=0;j<10;j++){
			int ans=j*pow(a,2),test,temp;
			test=ans,temp=a;
			f=true;
			do{
				u=temp%10;temp/=10;
				v=test%10;test/=10;
				if(u!=v)
					f=false;
			}while(u==v&&temp!=0);
			if(f){
				printf("%d %d\n",j,ans);
				break;
			}
		}
		printf("%s",f?"":"No\n");
	}
	return 0;
}
/*
3
92 5 233
*/
