#include<bits/stdc++.h>
using namespace std; 
const int maxn=100010;
struct Node{
	double price;
	double num;
	vector<int> child;
}Tree[maxn];
int n;
double p,r,sum;
void DFS(int s){
	if(Tree[s].child.size()==0){
		sum=sum+Tree[s].price*Tree[s].num;
		return;
	}
	for(auto i:Tree[s].child){
		Tree[i].price=Tree[s].price*(1+r/100);
		DFS(i);
	}
}
int main() {
	scanf("%d%lf%lf",&n,&p,&r);
	for(int i=0;i<n;i++){
		int loop,v;
		scanf("%d",&loop);
		if(loop==0){
			scanf("%lf",&Tree[i].num);
		}
		while(loop--){
			scanf("%d",&v);
			Tree[i].child.push_back(v);
		}
	}
	Tree[0].price=p;
	DFS(0);
	printf("%.1lf",sum);
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
