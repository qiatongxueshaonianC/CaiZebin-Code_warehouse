#include<bits/stdc++.h>
using namespace std; 
int main() {
	int N,m,v;
	scanf("%d%d",&N,&m);
	set<int> st;
	for(int i=0;i<m;i++){
		scanf("%d",&v);
		st.insert(v);
	}
	string s;
	pair<int,int> ans(0,0);
	while(N--){
		cin>>s;
		int k;
		scanf("%d",&k);
		vector<int> A;
		for(int i=0;i<k;i++){
			scanf("%d",&v);
			if(st.find(v)!=st.end())
				A.push_back(v);
		}
		if(!A.empty()){
			ans.first++;
			ans.second+=A.size();
			printf("%s:",s.c_str());
			for(auto j:A)
				printf(" %04d",j);
			puts("");
		}
	}
	printf("%d %d",ans.first,ans.second);
	return 0;
}
/*
4 2
2333 6666
CYLL 3 1234 2345 3456
U 4 9966 6666 8888 6666
GG 2 2333 7777
JJ 3 0012 6666 2333
*/
