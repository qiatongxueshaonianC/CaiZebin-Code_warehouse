#include<bits/stdc++.h>
using namespace std; 
priority_queue<int,vector<int>,greater<int> > q,Q;
priority_queue<int> qq,QQ;
long long ans1,ans2;
int main() {
	int n,v;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&v);
		q.push(v);
		qq.push(v);
	}
	scanf("%d",&n);
	while(n--){
		scanf("%d",&v);
		Q.push(v);
		QQ.push(v);
	}
	while(q.size()&&Q.size()){
			int temp=q.top()*Q.top();
			if(temp>0)
				ans1+=temp;
			q.pop();
			Q.pop();
	}
	while(qq.size()&&QQ.size()){
		int temp=qq.top()*QQ.top();
		if(temp>0)
			ans2+=temp;
		qq.pop();
		QQ.pop();
	}
	printf("%lld\n",max(ans1,ans2));
	return 0;
}
/*
4
1 2 4 -1
4
7 6 -2 -3

4
-1 -2 -3 -4
5
-6 -5 -4 -3 -1

4
1 2 3 4
5
6 5 4 3 1
*/
