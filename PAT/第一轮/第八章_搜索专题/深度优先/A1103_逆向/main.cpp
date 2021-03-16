#include<bits/stdc++.h>
using namespace std;
int n,k,p;
int bst;
vector<int> temp,ans,pow_num;
void init(){
	pow_num.push_back(0);
	for(int i=1;i<(int)sqrt(1.0*n)+1;i++){
		pow_num.push_back(pow(i,p));
	}
}
void DFS(int now,int sum,int sums,int index){
	if(now<=0||sum>n||index>k) return;
	if(sum==n&&index==k){
		if(sums>bst){
			bst=sums;
			ans=temp;
		}
		return;
	}
		temp.push_back(now);
		DFS(now,sum+pow_num[now],sums+now,index+1);
		temp.pop_back();
		DFS(now-1,sum,sums,index);
}
int main() {
	scanf("%d%d%d",&n,&k,&p);
	init();
	DFS(pow_num.size()-1,0,0,0);
	if(!ans.size()){
		puts("Impossible");
		return 0;
	}
	printf("%d = ",n);
	for(int i=0;i<ans.size();i++){
		printf("%d^%d",ans[i],p);
		if(i<ans.size()-1) 
			printf(" + ");
	}
	return 0;
}
/*
169 5 2
4 1 2 
36 4 2
*/
