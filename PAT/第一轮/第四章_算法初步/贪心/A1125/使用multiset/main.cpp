#include<bits/stdc++.h>
using namespace std;
multiset<int> st;
int main() {
	int n,u,v;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&u);
		st.insert(u);
	}
	while(st.size()>1){
		u=*st.begin();st.erase(st.begin());
		v=*st.begin();st.erase(st.begin());
		st.insert((u+v)/2);
	}
	printf("%d\n",*st.begin());
	return 0;
}
/*
8
10 15 12 3 4 13 1 15
*/
