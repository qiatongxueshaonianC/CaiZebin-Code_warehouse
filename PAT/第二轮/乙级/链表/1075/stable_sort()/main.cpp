#include<bits/stdc++.h>
using namespace std; 
const int maxn=100010;
struct Node{
	int add,data,next,flag;
}L[maxn]; 
bool cmp(Node a,Node b){
	return a.flag<b.flag;
}
int main() {
	int st,n,k,add;
	scanf("%d%d%d",&st,&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&add);
		scanf("%d%d",&L[add].data,&L[add].next);
		L[add].add=add;
		L[add].flag=L[add].data<0?-1:L[add].data>k?2:1;
	}
	vector<Node> A;
	while(st!=-1){
		A.push_back(L[st]);
		st=L[st].next;
	}
	stable_sort(A.begin(),A.end(),cmp);
	for(int i=0;i<A.size()-1;i++)
		printf("%05d %d %05d\n",A[i].add,A[i].data,A[i+1].add);
	printf("%05d %d -1",A[A.size()-1].add,(--A.end())->data);
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
