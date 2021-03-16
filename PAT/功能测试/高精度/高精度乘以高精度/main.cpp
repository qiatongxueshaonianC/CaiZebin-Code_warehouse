#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std; 
const int maxn=8010;
int a[maxn],b[maxn];
void mul(int (&ans)[2*maxn],int a[],int b[]){
	for(int t=0;t<maxn;t++){
		for(int j=0;j<maxn;j++){
			ans[t+j]+=a[t]*b[j];
			ans[t+j+1]+=(ans[t+j]/10);
			ans[t+j]%=10;
		}
	}
}
int main() {
	string s;
	cin>>s;
	int idx=0;
	for(int i=s.size()-1;i>=0;i--)
		a[idx++]=s[i]-'0';
	cin>>s;
	idx=0;
	for(int i=s.size()-1;i>=0;i--)
		b[idx++]=s[i]-'0';
	int ans[2*maxn]={0};
	mul(ans,a,b);
	for(int t=2*maxn-1;t>=0;t--)
		printf("%d",ans[t]);
	return 0;
}
/*
11111118 111111119
597 321647
1113 1971
3987 316771
*/
