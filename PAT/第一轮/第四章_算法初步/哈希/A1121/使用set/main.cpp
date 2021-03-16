#include<bits/stdc++.h>
using namespace std; 
set<int> st; 
unordered_map<int,int> mp;
int main() {
	int n,u,v;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&u,&v);
		mp[u]=v;
		mp[v]=u;
	}
	scanf("%d",&n);
	while(n--){
		scanf("%d",&u);
		auto it=st.find(mp[u]);
		if(it==st.end()){
			st.insert(u);
		}else{
			st.erase(it);
		}
	}
	printf("%d\n",st.size());
	for(auto i:st)
		printf("%05d%s",i,i==*(--st.end())?"\n":" ");
	return 0;
}
/*
3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333
*/
