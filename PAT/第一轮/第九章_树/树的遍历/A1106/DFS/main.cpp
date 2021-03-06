#include<bits/stdc++.h>
using namespace std; 
const int maxn=100010;
struct Node{
	int layer;
	vector<int> child;
}Tree[maxn];
int n;
double p,r; 
pair<int,int> ans(maxn,0);
void DFS(int s){
	if(Tree[s].child.size()==0){
		if(Tree[s].layer<ans.first){
			ans.first=Tree[s].layer;
			ans.second=1;
		}else if(Tree[s].layer==ans.first) ans.second++;
		return;
	}
	for(auto i:Tree[s].child){
		Tree[i].layer=Tree[s].layer+1;
		DFS(i);
	}
}
int main() {
	scanf("%d%lf%lf",&n,&p,&r);
	for(int i=0;i<n;i++){
		int loop,v;
		scanf("%d",&loop);
		while(loop--){
			scanf("%d",&v);
			Tree[i].child.push_back(v);
		}
	}
	Tree[0].layer=0;
	DFS(0);
	printf("%.4lf %d\n",p*pow(1+r/100,ans.first),ans.second);
	return 0;
}
/*
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0
2 6 1
1 8
0
0
0
*/
