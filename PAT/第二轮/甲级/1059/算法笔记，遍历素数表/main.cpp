#include<bits/stdc++.h>
using namespace std; 
bitset<(int)sqrt(1.0*1e10)> bst;
list<int> Prime;
void init(int N){
	int sqr=(int)sqrt(1.0*N);
	for(int i=2;i<=sqr;i++){
		if(bst[i]==0){
			Prime.insert(Prime.end(),i);
			for(int j=i+i;j<=sqr;j+=i)
				bst[i]=1;
		}
	}
}
map<int,int> ans;
int main() {
	int N;
	scanf("%d",&N);
	printf("%d=",N);
	init(N); 
	for(list<int>::iterator it=Prime.begin();it!=Prime.end();it++){
		if(N%*it==0){
			while(N%*it==0){
				ans[*it]++;
				N/=*it;
			}
		}
		if(N==1) break;
	}
	if(N!=1) ans[N]++;
	for(map<int,int>::iterator it=ans.begin();it!=ans.end();it++){
		if(it->second==1)
			printf("%d%s",(*it).first,it==(--ans.end())?"":"*");
		else
			printf("%d^%d%s",it->first,it->second,it==--ans.end()?"":"*");
	}
	if(ans.empty())
		puts("1");
	return 0;
}
/*
97532468
*/
