#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100010;
//bitset<maxn> harsh;
bool harsh[maxn];
vector<int> Prime;
void getPrimeTable(){
	for(int i=2;i<maxn;i++){
		if(harsh[i]==0){
			Prime.push_back(i);
			for(int j=i+i;j<maxn;j+=i)
				harsh[j]=1;
		}
	}
}
int main() {
	getPrimeTable();
	ll n,p;
	map<int,int> ans;
	scanf("%lld",&p);
	if(p==1) puts("1=1");
	else{
		n=p;
		for(int i=0;i<Prime.size();i++){  //��ôд������n==1�Ƴ�ѭ����ʡʱ�� 
	//	for(int i=0;Prime[i]<n;i++){
			if(n%Prime[i]==0){
			    ans[Prime[i]]=1;
			    n/=Prime[i];
			    while(n%Prime[i]==0){
		   		 	ans[Prime[i]]++;
		    		n/=Prime[i];
				}
			}
			if(n==1) break;
		}
		if(n!=1) ans[n]=1;
		printf("%lld=",p);
		for(auto i=ans.begin();i!=ans.end();i++){
			if(i->second==1)
				printf("%d%s",i->first,i==(--ans.end())?"":"*");
			else printf("%d^%d%s",i->first,i->second,i==(--ans.end())?"":"*");
		}
	}
	return 0;
}
/*
97532468
*/
