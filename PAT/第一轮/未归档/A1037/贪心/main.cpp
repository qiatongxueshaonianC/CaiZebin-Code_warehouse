#include<bits/stdc++.h>
using namespace std; 
vector<int> q,Q;
long long ans;
int main() {
	int n,index;
	scanf("%d",&n);
	q.resize(n);Q.resize(n);
	for(int i=0;i<n;i++)
		scanf("%d",&q[i]);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&Q[i]);
	sort(q.begin(),q.end());
	sort(Q.begin(),Q.end());
	for(int i=0;q[i]<0&&Q[i]<0&&i<q.size()&&i<Q.size();i++)
		ans+=q[i]*Q[i];
	for(int i=q.size()-1,index=Q.size()-1;q[i]>0&&Q[index]>0&&i>=0&&index>=0;i--,index--)
		ans+=q[i]*Q[index];
	printf("%lld\n",ans);
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
