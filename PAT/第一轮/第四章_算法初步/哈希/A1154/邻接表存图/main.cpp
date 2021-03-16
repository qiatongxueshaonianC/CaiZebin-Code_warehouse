#include<bits/stdc++.h>
using namespace std; 
vector<vector<int>> A;
int main() {
	int n,m,k,u,v;
	scanf("%d%d",&n,&m);
	A.resize(n);
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		A[u].push_back(v);
		A[v].push_back(u);
	}
	scanf("%d",&k);
	while(k--){
		unordered_set<int> st;
		int harsh[n];
		for(int i=0;i<n;i++){
			scanf("%d",&harsh[i]);
			st.insert(harsh[i]);
		}
		bool flag=true;
		for(int i=0;i<A.size();i++){
			for(auto j:A[i]){
				if(harsh[i]==harsh[j]){
					flag=false;
					break;
				}
			}
			if(flag==false)
				break;
		}
		if(flag==false)
			puts("No");
		else
			printf("%d-coloring\n",st.size());
	}
	return 0;
}
/*
10 11
8 7
6 8
4 5
8 4
8 1
1 2
1 4
9 8
9 1
1 0
2 4
4
0 1 0 1 4 1 0 1 3 0
0 1 0 1 4 1 0 1 0 0
8 1 0 1 4 1 0 5 3 0
1 2 3 4 5 6 7 8 8 9
*/
