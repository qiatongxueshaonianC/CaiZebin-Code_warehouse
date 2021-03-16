#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
vector<int> G[maxn]; 
vector<int> temp,ans;
int n,maxhigh;
bool inq[maxn]={false};
int BFS(int s) {
	queue<int> q;
	q.push(s);
	inq[s]=true;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(auto i:G[now]){
			if(inq[i]==false){
				q.push(i);
				inq[i]=true;
			}
		}
	}
}
int BFSTrave(){
	int block=0;
	for(int i=1;i<=n;i++){
		if(inq[i]==false){
			block++;
			BFS(i);
		}
	}
	return block;
}
void DFS(int now,int pre,int high){
	if(high>maxhigh){
		maxhigh=high;
		temp.clear();
		temp.push_back(now);
	}else if(high==maxhigh) temp.push_back(now);
	for(auto i:G[now]){
		if(i==pre) continue;
		DFS(i,now,high+1);
	}
}
int main() {
	int id1,id2;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&id1,&id2);
		G[id1].push_back(id2);
		G[id2].push_back(id1);
	}
	int Block=BFSTrave();
	if(Block>1) printf("Error: %d components\n",Block);
	else{
		DFS(1,-1,0);
		ans=temp;
		DFS(ans[0],-1,0);
		for(auto i:temp)
			ans.push_back(i);
		sort(ans.begin(),ans.end());
		puts(to_string(ans[0]).c_str());
		for(int i=1;i<ans.size();i++){
			if(ans[i]!=ans[i-1]) printf("%d\n",ans[i]);
		}
	}
	return 0;
}
/*
5
1 2
1 3
1 4
2 5
*/
/*
5
1 3
1 4
2 5
3 4
*/
