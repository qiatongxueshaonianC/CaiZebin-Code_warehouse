#include<bits/stdc++.h>
using namespace std; 
int N;
map<int,int> ans;
bitset<100010> bst;
vector<int> Prime;
void init(){
	int sqr=(int)sqrt(1.0*N);
	for(int i=2;i<=sqr;i++){
		if(bst[i]==0){
			Prime.push_back(i);
			for(int j=i+i;j<=sqr;j+=i)
				bst.set(j);
		}
	}
}
void DFS(int idx){
	if(idx>=Prime.size()||N==1) return;
	if(N%Prime[idx]==0){
		while(N%Prime[idx]==0){
			ans[Prime[idx]]++;
			N/=Prime[idx];
		}
	}
	DFS(idx+1);
}
int main() {
	scanf("%d",&N);
	printf("%d=",N);
	init();
	DFS(0);
	if(N!=1) ans[N]++;
	for(auto i:ans){
		if(i.second==1)
			printf("%d%s",i.first,i==*(--ans.end())?"":"*");
		else
			printf("%d^%d%s",i.first,i.second,i==*(--ans.end())?"":"*");
	}
	if(ans.empty())
		puts("1");
	return 0;
}
/*
97532468
*/
