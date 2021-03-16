#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int isroot[maxn]={0};
int father[maxn]={0};
int n,m,k,query;
vector<pair<int,int> >G;
void init(){
	for(int i=1;i<=n;i++){
		father[i]=i;
	}
} 
int findFather(int a){
	if(father[a]==a) return a;
	int temp=findFather(father[a]);
	father[a]=temp;
	return temp;
}
void Union(int a,int b){
	int fa=findFather(a);
	int fb=findFather(b);
	if(fa!=fb) father[fa]=fb;
}
int calblock(int occupy){
	fill(isroot+1,isroot+n+1,0);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(i==occupy) continue;
		isroot[findFather(i)]++;
	}
	for(int i=1;i<=n;i++)
		if(isroot[i]>0) ans++;
	return ans;
}
int main() {
	int c1,c2;
	scanf("%d%d%d%*c",&n,&m,&k);
	while(m--){
		scanf("%d%d",&c1,&c2);
		G.push_back(make_pair(c1,c2));
	}
	int ans;
	while(k--){
		init();
		scanf("%d",&query);
		for(auto i:G){
			if(i.first==query||i.second==query) continue;
			Union(i.first,i.second);
		}
		ans=calblock(query);
		printf("%d\n",ans-1);
	}
	return 0;
}
/*
3 2 3
1 2
1 3
1 2 3
*/
