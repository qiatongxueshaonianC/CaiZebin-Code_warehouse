#include<bits/stdc++.h>
using namespace std; 
set<int> harsh[100010];
int main() {
	int n,m,u,v,k;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d%d",&u,&v);
		harsh[u].insert(v);
		harsh[v].insert(u);
	}
	while(m--){
		unordered_set<int> st;
		scanf("%d",&k);
		bool flag=false; 
		while(k--){
			scanf("%d",&u);
			for(auto i:harsh[u]){
				if(st.find(i)!=st.end()){
					flag=true;
					while(k--){  //2019/12/5/21:41发现改正，要把数读完 
						scanf("%d",&v);
					}
					break;
				}
			}
			if(flag) break;
			st.insert(u);
		}
		printf("%s\n",flag?"No":"Yes");
	}
	return 0;
}
/*
6 3
20001 20002
20003 20004
20005 20006
20003 20001
20005 20004
20004 20006
4 00001 20004 00002 20003
5 98823 20002 20003 20006 10010
3 12345 67890 23333
*/
