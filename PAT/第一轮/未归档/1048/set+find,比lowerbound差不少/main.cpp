#include<bits/stdc++.h>
using namespace std; 
multiset<int> A;
int n,Sum;
int main() {
	scanf("%d%d",&n,&Sum);
	int v;
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		A.insert(v);
	}
	bool flag=false;
	for(auto i=A.begin();i!=A.end();i++){
		auto it=A.find(Sum-*i);
		if(it!=A.end()&&it!=i){
			printf("%d %d\n",*i,Sum-*i);
			flag=true;
			break;
		}
	}
	if(!flag) puts("No Solution");
	return 0;
}
/*
8 15
1 2 8 7 2 4 11 15
8 4
1 2 8 7 2 4 11 15
*/
