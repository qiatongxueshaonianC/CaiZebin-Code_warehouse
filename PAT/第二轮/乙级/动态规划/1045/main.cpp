#include<bits/stdc++.h>
using namespace std; 
const int maxn=100010;
int main() {
	int n,a[maxn][2];
	fill(a[0],a[0]+maxn*2,0);
	scanf("%d",&n); 
	vector<int> A(n+2);
	a[0][0]=-INT_MAX;
	a[n][1]=INT_MAX;
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
		a[i][0]=max(a[i-1][0],A[i]);
	}
	for(int i=n-1;i>0;i--)
		a[i][1]=min(a[i+1][1],A[i+1]);
	set<int> ans;
	for(int i=1;i<=n;i++){
		if(a[i][0]<=A[i]&&A[i]<=a[i][1])
			ans.insert(A[i]);
	}
	printf("%d\n",ans.size());
	for(auto i:ans)
		printf("%d%s",i,i==*(--ans.end())?"\n":" ");
	if(ans.empty()) puts("");
	return 0;
}
/*
5
1 3 2 4 5
*/
