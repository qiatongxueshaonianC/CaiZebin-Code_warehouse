#include<bits/stdc++.h>
using namespace std; 
const int maxn=100010;
struct Node{
	int layer;
	vector<int> child;
}Tree[maxn];
int n;
double p,r;
pair<int,int> ans;
void DFS(int s){
	if(Tree[s].child.size()==0){
		if(Tree[s].layer>ans.first){
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
	int v,root;
	scanf("%d%lf%lf",&n,&p,&r);
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		//(v==-1)?(root=i):(Tree[i].child.push_back(v));
		if(v==-1) root=i;
		else Tree[v].child.push_back(i); //这里需要注意，给的是供应商的下标 
	}
	Tree[root].layer=0;
	DFS(root);
	printf("%.2lf %d\n",p*pow(1+r/100,ans.first),ans.second);
	return 0;
}
/*
9 1.80 1.00
1 5 4 4 -1 4 5 3 6
*/
