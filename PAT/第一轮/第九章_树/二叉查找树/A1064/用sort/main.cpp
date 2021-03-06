#include<bits/stdc++.h>
using namespace std;
const int maxn=1010; 
int n,x,v; 
vector<int> in;
void create(int s,vector<int>& Tree){
	if(s>n) return;
	create(2*s,Tree);
	Tree[s]=in[x++];
	create(2*s+1,Tree);
}
int main() {
	scanf("%d",&n);
	vector<int> Tree(n+1);
	for(int i=0;i<n;i++){
		cin>>v;
		in.push_back(v);
	}
	sort(in.begin(),in.end());
	create(1,Tree);
	for(auto i=++Tree.begin();i!=Tree.end();i++)
		printf("%d%s",*i,i<--Tree.end()?" ":"");
	return 0;
}
/*
10
1 2 3 4 5 6 7 8 9 0
*/

