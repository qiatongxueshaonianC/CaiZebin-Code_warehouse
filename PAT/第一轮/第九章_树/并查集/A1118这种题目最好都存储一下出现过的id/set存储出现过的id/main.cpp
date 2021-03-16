#include<bits/stdc++.h>
using namespace std; 
const int maxn=10010;
int father[maxn],isRoot[maxn];
int findFather(int a){
	if(father[a]==a) return a;
	int temp=findFather(father[a]);
	father[a]=temp;
	return temp;
}
void Union(int a,int b){
	int fa=findFather(a);
	int fb=findFather(b);
	if(fa!=fb){
		father[fa]=fb;
	}
}
unordered_set<int> A;
int main() {
	iota(father,father+maxn,0);
	int n,k,u,v;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&k);
		scanf("%d",&u);
		A.insert(u);
		while(--k){  //因为已经读入了第一个值 
			scanf("%d",&v);
			Union(u,v); 
			A.insert(v);  //记录出现过的id 
		}
	}
	pair<int,int> ans(0,0);
	for(auto i:A){
		isRoot[findFather(i)]++;
	}
	for(int i=1;i<maxn;i++){
		if(isRoot[i]>0){
			ans.first++;
			ans.second+=isRoot[i];
		}
	}
	scanf("%d",&k);
	printf("%d %d\n",ans.first,ans.second);
	while(k--){
		scanf("%d%d",&u,&v);
		int fu=findFather(u);
		int fv=findFather(v);
		printf("%s\n",fu==fv?"Yes":"No");
	}
	return 0;
}
/*
4
3 10 1 2
2 3 4
4 1 5 7 8
3 9 6 4
2
10 5
3 7
*/
