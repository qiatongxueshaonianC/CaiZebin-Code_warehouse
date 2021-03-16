#include<bits/stdc++.h>
using namespace std;
const int maxn=60;
vector<int> G[maxn],ans;
int inDegree[maxn],n; 
bool TopoSort(){
	int num_node=0;     //一定要写等于0！！！！！ 
	stack<int> s;
	for(int i=0;i<n;i++){
		if(inDegree[i]==0){
			s.push(i);
		}
	}
	while(!s.empty()){
		int u=s.top();s.pop();
		num_node++;
		ans.push_back(u);
		for(auto i:G[u]){
			inDegree[i]--;
			if(inDegree[i]==0) s.push(i);
		}
	}
	if(num_node!=n) return false;
	return true;
}
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int edge;
		for(int j=0;j<n;j++){
			scanf("%d",&edge);
			if(edge==1){
				G[i].push_back(j);
				inDegree[j]++;
			}
		}
	}
	if(TopoSort()){
		for(auto i:ans){
			printf("%d",i);
			if(i!=*(ans.end()-1)) printf(" ");
		}
		puts("");
	}else puts("ERROR");
	return 0;
}
/*
4
0 1 0 0
0 0 1 0
0 0 0 0
0 0 1 0
*/
