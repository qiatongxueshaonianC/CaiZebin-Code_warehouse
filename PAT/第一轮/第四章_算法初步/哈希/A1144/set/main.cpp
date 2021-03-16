#include<bits/stdc++.h>
using namespace std; 
set<int> st; 
int main() {
	int n,v;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		st.insert(v);	
	}
	for(int i=1;true;i++){
		if(st.find(i)==st.end()){
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}
/*
10
5 -25 9 6 1 3 4 2 5 17
*/
