#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int main() {
	int N,M,a,b;
	scanf("%d%d",&N,&M);
	vector<set<int>> harsh(maxn);
	for(int i=0;i<N;i++){
		scanf("%d%d",&a,&b);
		harsh[a].insert(b);
		harsh[b].insert(a);
	}
	for(int i=0;i<M;i++){
		int k,flag=1;
		scanf("%d",&k);
		set<int> st;
		while(k--){
			scanf("%d",&a);
			for(auto I:harsh[a]){
				if(st.find(I)!=st.end()){
					flag=0;
					break;
				}
			}
			if(flag==0) st.insert(a);
			else break;
		}
		while(k-->0) scanf("%d",&a);
		printf("%s\n",flag?"Yes":"No");
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
