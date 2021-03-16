#include<bits/stdc++.h>
using namespace std; 
struct Node{
	int data,next,flag;
}L[100005];
bool cmp(int a,int b){
	return L[a].flag<L[b].flag;
}
int main() {
	int st,n,K,addr,data,next;
	scanf("%d%d%d",&st,&n,&K);
	for(int i=0;i<n;i++){
		scanf("%d",&addr);
		scanf("%d%d",&L[addr].data,&L[addr].next);
		if(L[addr].data<0) L[addr].flag=-1;
		else if(L[addr].data>K) L[addr].flag=1;
		else L[addr].flag=0;
	}
	vector<int> ans;
	while(st!=-1){
		ans.push_back(st); //只存了节点的编号 
		st=L[st].next;
	}
	stable_sort(ans.begin(),ans.end(),cmp); 
	for(int i=0;i<ans.size()-1;i++)
		printf("%05d %d %05d\n",ans[i],L[ans[i]].data,ans[i+1]);
	printf("%05d %d -1\n",*--ans.end(),L[*--ans.end()].data);
//	printf("%05d %d -1\n",ans[ans.size()-1],L[ans[ans.size()-1]].data); //注意，这里要特判输出 
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
