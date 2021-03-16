#include<bits/stdc++.h>
using namespace std; 
int main() {
	vector<pair<int,int>> A;
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		if(a!=0&&b!=0)
			A.push_back(make_pair(a,b));
	} 
	for(auto&i:A){
		i.first=i.first*i.second;
		i.second--;
	}
	for(auto i:A)
		printf("%d %d%s",i.first,i.second,i==*(--A.end())?"":" ");
	if(A.empty())
		puts("0 0");
	return 0;
}
/*
3 4 -5 2 6 1 -2 0 -3 -2
*/
