#include<bits/stdc++.h>
using namespace std; 
const int maxn=1000010;
bitset<maxn> bst;
vector<int> prime;
void init(){
	for(int i=2;i<maxn;i++){
		if(bst[i]==0){
			prime.push_back(i);
			for(int j=i+i;j<maxn;j+=i){
				bst[j]=1;
			}
		}
	}
}
int main() {
	init(); 
	int n,m,index=1;
	scanf("%d%d",&n,&m);
	for(int i=n-1;i<m;i++,index++)
		printf("%d%s",prime[i],index%10==0||i==m-1?"\n":" ");
}
/*
5 27
*/
