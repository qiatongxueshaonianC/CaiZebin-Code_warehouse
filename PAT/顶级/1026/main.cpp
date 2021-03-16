#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,left=0,right=0,ans=0,v=0;
	scanf("%d",&n);
	vector<int> value(n+1),L(n+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&value[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&L[i]);
	unordered_set<int> st;
	for(int i=0,j=0;i<n;i++){
		for(;j<=n;j++){
			if(j==n||st.find(L[j])!=st.end()){
				if(j-i>right-left||(j-i==right-left&&v>ans)){
					ans=v;
					left=i;
					right=j-1;
				}
				break;
			}
			st.insert(L[j]);
			v+=value[L[j]];
		}
		st.erase(L[i]);
		v-=value[L[i]];
	}
	printf("%d %d %d",ans,left,right);
	return 0;
}
/*
8
18 20 2 97 23 12 8 5
3 3 5 8 1 5 2 1
*/
