#include<bits/stdc++.h>
using namespace std; 
const int maxn=100010;
bool harsh[maxn]; 
void init(){
	for(int i=2;i<maxn;i++){
		if(harsh[i]==false){
			for(int j=i+i;j<maxn;j+=i)
				harsh[j]=true;
		}
	}
}
int main() {
	init();
	int n,ans=0;
	scanf("%d",&n);
	for(int i=2;i+2<=n;i++){
		if(harsh[i]==false&&harsh[i+2]==false)
			ans++;
	}
	printf("%d",ans);
	return 0;
}
/*
234

23
*/
