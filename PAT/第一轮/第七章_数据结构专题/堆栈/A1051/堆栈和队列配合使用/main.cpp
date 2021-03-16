#include<bits/stdc++.h>
using namespace std; 
int main() {
	int m,n,k,v;
	scanf("%d%d%d",&m,&n,&k);
	queue<int> Q;
	for(int i=1;i<=n;i++)
		Q.push(i);
	while(k--){
		bool flag=true;
		stack<int> stk;
		queue<int> q,t;
		q=Q;
		for(int i=0;i<n;i++){
			scanf("%d",&v);
			t.push(v); 
		} 
		for(int i=0;i<n;i++){
			stk.push(q.front());q.pop();
			if(stk.size()>m){
				flag=false;
				break;
			}
			while(stk.size()&&stk.top()==t.front()){
				stk.pop();
				t.pop();
			}	
		}
		if(flag&&stk.empty())
			puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
5 7 5
5 6 4 3 7 2 1
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
1 7 6 5 4 3 2
*/
