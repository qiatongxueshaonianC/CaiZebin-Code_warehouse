#include<bits/stdc++.h>
const int maxn=1010;
using namespace std; 
vector<set<int> >vct(maxn);
priority_queue<pair<int,int>> ans;
int father[maxn],isRoot[maxn]; 
int findFather(int s){
	if(father[s]==s) return s;
	int temp=findFather(father[s]);
	father[s]=temp;
	return temp;
}
int main() {
	int n,u,v;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d:",&u);
		while(u--){
			scanf("%d",&v);
			vct[i].insert(v);
		}
	}
	iota(father,father+maxn,0);
	for(int i=1;i<vct.size()-1&&vct[i].size();i++){
		for(int j=i+1;j<vct.size()&&vct[j].size();j++){
			int fa=findFather(i);
			int fb=findFather(j);
			if(fa!=fb){
				for(auto k:vct[i]){
					for(auto t:vct[j]){
						if(k==t) {
							father[fa]=fb;
							break;
						}	
					}
					if(father[fa]==fb) break;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
		isRoot[findFather(i)]++;
	for(int i=1;i<=n;i++){
		if(isRoot[i]>0) ans.push({isRoot[i],i});
	//	printf("%d ",isRoot[i]);
	}
	printf("%d\n",ans.size());
	while(ans.size()){
		printf("%d%s",ans.top().first,ans.size()>1?" ":"");
		ans.pop();
	}
	return 0;
}
/*
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4
*/
