#include<bits/stdc++.h>
using namespace std;
int n,x,y,ans; 
priority_queue<int,vector<int>,greater<int>>q;
int main() {
	cin>>n;
	int v;
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		q.push(v);
	}
	while(q.size()>1){  //��֤�������������� 
		x=q.top();q.pop();
		y=q.top();q.pop();
		q.push(x+y);
		ans+=x+y;
	}
	printf("%d\n",ans);
	return 0;
}
/*
3
1 2 9
*/
