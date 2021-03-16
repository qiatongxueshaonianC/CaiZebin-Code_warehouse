#include<bits/stdc++.h>
using namespace std; 
int main() {
	int N,u;
	scanf("%d",&N);
	vector<int> A(N);
	iota(A.begin(),A.end(),1); 
	for(int i=0;i<N;i++){
		scanf("%d",&u);
		A[i]=abs(u-A[i]);
	}
	sort(A.begin(),A.end(),[](int a,int b){
		return a>b;
	});
	map<int,int,greater<int>> mp;
	for(auto i:A)
		mp[i]++;
	for(auto i:mp)
		if(i.second>1)
			printf("%d %d\n",i.first,i.second);
	return 0;
}
/*
8
3 5 8 6 2 1 4 7
*/
