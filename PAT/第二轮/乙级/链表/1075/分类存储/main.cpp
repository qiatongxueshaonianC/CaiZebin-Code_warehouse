#include<bits/stdc++.h>
using namespace std; 
const int maxn=100010;
struct Node{
	int add,data,next,flag;
}L[maxn]; 
int main() {
	int st,n,k,add;
	scanf("%d%d%d",&st,&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&add);
		scanf("%d%d",&L[add].data,&L[add].next);
		L[add].add=add;
		L[add].flag=L[add].data<0?0:L[add].data>k?2:1;
	} 
	vector<vector<Node>> A(3,vector<Node>());
	while(st!=-1){
		A[L[st].flag].push_back(L[st]);
		st=L[st].next;
	}
	vector<Node> ans;
	for(auto i:A){
		for(auto j:i)
			ans.push_back(j);
	}
	for(int i=0;i+1<ans.size();i++)
		printf("%05d %d %05d\n",ans[i].add,ans[i].data,ans[i+1].add);
	printf("%05d %d -1",ans[ans.size()-1].add,(--ans.end())->data);
	return 0;
}
/*
00100 9 10
23333 10 27777
00000 0 99999
00100 18 12309
68237 -6 23333
33218 -4 00000
48652 -2 -1
99999 5 68237
27777 11 48652
12309 7 33218
*/
