#include<bits/stdc++.h>
using namespace std; 
int main() {
	int n,ans=0;
	scanf("%d",&n);
	while(n!=1){
		if(n%2==0){
			n/=2;
			ans++;
		}else
			n=3*n+1;
	}
	printf("%d",ans);
	return 0;
}
