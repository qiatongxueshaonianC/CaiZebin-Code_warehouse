#include<bits/stdc++.h>
using namespace std;
int n,k,p;
int pow_num[21],bst;
vector<int> temp,ans;
void init(){
	for(int i=1;i<21;i++){
		pow_num[i]=pow(i,p);
	}
}
bool cmp(vector<int> a,vector<int> b){
	vector<int> c,d;
	c=a;d=b;
	sort(c.begin(),c.end());
	sort(d.begin(),d.end());
	for(int i=0;i<c.size()&&i<d.size();i++){
		if(c[i]>d[i]) return true;
	}
	return false;
}
void DFS(int now,int sum,int sums,int index){
	if(now>=21||sum>n||index>k) return;
	if(sum==n&&index==k){
		if(sums>bst){
			bst=sums;
			ans=temp;
		}else if(sums==bst&&cmp(ans,temp)){
			ans=temp;
		}
		return;
	}
	if(sum+pow_num[now]<=n&&index+1<=k){ 
		temp.push_back(now);
		DFS(now,sum+pow_num[now],sums+now,index+1);  //ѡ 
		temp.pop_back();
		DFS(now+1,sum,sums,index);   //��ѡ 
	}
}
int main() {
	scanf("%d%d%d",&n,&k,&p);
	init();
	int now=1,sums=0,sum=0,index=0;
	DFS(now,sum,sums,index);
	if(!ans.size()){
		puts("Impossible");
		return 0;
	}
	sort(ans.begin(),ans.end());
	reverse(ans.begin(),ans.end());
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
