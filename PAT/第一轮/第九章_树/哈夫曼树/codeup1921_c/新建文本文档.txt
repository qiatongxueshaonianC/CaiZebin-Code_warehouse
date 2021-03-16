#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int>> q;
int n,x,y,ans;
int main() {
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			q.push(x);
		}
		while(q.size()>1){
			x=q.top();q.pop();
			y=q.top();q.pop();
			q.push(x+y);
			ans+=x+y;
		}
		puts(to_string(ans).c_str());
		ans=0;
		q.pop();
	}
	return 0;
}
/*
2
2 8 
3
5 11 30 
*/
