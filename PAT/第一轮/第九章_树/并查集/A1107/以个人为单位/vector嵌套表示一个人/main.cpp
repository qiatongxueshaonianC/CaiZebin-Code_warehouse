#include<bits/stdc++.h>
const int maxn=1010;
using namespace std; 
vector<vector<int> >person(maxn);
int n,father[maxn],isRoot[maxn];
priority_queue<pair<int,int>> ans;
int findFather(int s){
	if(father[s]==s) return s;
	int temp=findFather(father[s]);
	father[s]=temp;
	return temp;
}
int main() {
	scanf("%d",&n);
	int k,u,v;
	for(int i=1;i<=n;i++){
		scanf("%d:",&k);
		while(k--){
			scanf("%d",&v);
			person[i].push_back(v);
		}
	}
	iota(father,father+maxn,0);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int fa=findFather(i);
			int fb=findFather(j);
			if(fa!=fb){
				for(auto k:person[i]){
					for(auto t:person[j]){
						if(k==t){
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
	}
	puts(to_string(ans.size()).c_str());
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
