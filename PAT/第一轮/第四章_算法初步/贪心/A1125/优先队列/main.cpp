#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int>> q; 
int main() {
	int n,u,v;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		q.push(v);
	}
	while(q.size()>1){
		u=q.top();q.pop();
		v=q.top();q.pop();
		q.push((u+v)/2);
	}
	printf("%d\n",q.top());
	return 0;
}
/*
8
10 15 12 3 4 13 1 15
*/
