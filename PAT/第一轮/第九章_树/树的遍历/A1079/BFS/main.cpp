#include<bits/stdc++.h>
using namespace std; 
const int maxn=100010;
struct Node{
	int layer;
	double num;
	vector<int> child;
}Tree[maxn]; 
double p,r,ans;
int n;
void BFS(int s){
	queue<int> q;
	Tree[s].layer=0;
	q.push(s);
	while(!q.empty()){
		int now=q.front();q.pop();
		if(Tree[now].child.size()==0){
			ans+=Tree[now].num*pow(1+r/100,Tree[now].layer);
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
		int loop,v;
		scanf("%d",&loop);
		if(loop==0){
			scanf("%lf",&Tree[i].num);
		}else{
			while(loop--){
				scanf("%d",&v);
				Tree[i].child.push_back(v); 
			}
		}
	}
	BFS(0);
	printf("%.1lf\n",ans*p);
	return 0;
}
/*
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0 7
2 6 1
1 8
0 9
0 4
0 3
*/
