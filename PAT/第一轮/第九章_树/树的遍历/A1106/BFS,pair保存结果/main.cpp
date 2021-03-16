#include<bits/stdc++.h>
using namespace std; 
const int maxn=100010;
struct Node{
	int layer;
	vector<int> child;
}Tree[maxn];
int n;
double p,r;
vector<Node> ans;
void BFS(int s){
	queue<int> q;
	q.push(s);
	while(q.size()){
		int now=q.front();q.pop();
		if(Tree[now].child.size()==0){
			if(ans.size()){
				if(Tree[now].layer<ans[0].layer){
					ans.clear();
					ans.push_back(Tree[now]);
				} else if(Tree[now].layer==ans[0].layer) ans.push_back(Tree[now]);	
			}else ans.push_back(Tree[now]);
		}
		for(auto i:Tree[now].child){
			Tree[i].layer=Tree[now].layer+1;
			q.push(i);
		}
	}
}
int main() {
	scanf("%d%lf%lf",&n,&p,&r);
	for(int i=0;i<n;i++){
		int v,loop;
		scanf("%d",&loop);
		while(loop--){
			scanf("%d",&v);
			Tree[i].child.push_back(v);
		} 
	} 
	Tree[0].layer=0;
	BFS(0);
	printf("%.4lf %d\n",p*pow(1+r/100,ans[0].layer),ans.size());
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
