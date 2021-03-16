#include<bits/stdc++.h>
using namespace std; 
struct Node{
	int id,data,next;
	bool friend operator <(Node a,Node b){  //这里不能用（）必须是小于号，否则编译不过 
		return a.data<b.data;
	}
}L[100005];
int main() {
	int st,n,id,data,next;
	scanf("%d%d",&n,&st);
	for(int i=0;i<n;i++){
		scanf("%d",&id);
		L[id].id=id;
		scanf("%d%d",&L[id].data,&L[id].next);
	}
	vector<Node> ans;
	while(st!=-1){
		ans.push_back(L[st]);
		st=L[st].next;
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)
		ans[i].next=ans[i+1].id;
	if(ans.empty()){
	//	puts("0"); 
		printf("0 -1\n");  //2019/11/17/12:17特殊情况的输出改正，不是只输出0 
		return 0;
	} 
	printf("%d %05d\n",ans.size(),ans.begin()->id);
	for(int i=0;i<ans.size()-1;i++)
		printf("%05d %d %05d\n",ans[i].id,ans[i].data,ans[i].next);
	printf("%05d %d %d\n",(--ans.end())->id,(--ans.end())->data,-1);
	return 0;
}
/*
5 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345

1 00001
00002 0 -1
*/
