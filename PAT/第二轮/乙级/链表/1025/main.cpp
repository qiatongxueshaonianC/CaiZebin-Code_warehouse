#include<bits/stdc++.h>
using namespace std; 
const int maxn=100010;
struct Node{
	int add,data,next;
}L[maxn]; 
int main() {
	int start,n,k,add;
	scanf("%d%d%d",&start,&n,&k);
	vector<Node> A;
	for(int i=0;i<n;i++){
		scanf("%d",&add);
		scanf("%d%d",&L[add].data,&L[add].next);
		L[add].add=add;
	}
	while(start!=-1){
		A.push_back(L[start]);
		start=L[start].next;
	}
	for(int i=0;i+k<=A.size();i+=k)  //2020/1/20/15:20发现改正，这里是A.size(),不是n； 
		reverse(A.begin()+i,A.begin()+i+k);
	for(int i=0;i+1<A.size();i++)
		printf("%05d %d %05d\n",A[i].add,A[i].data,A[i+1].add);
	printf("%05d %d -1",(--A.end())->add,A[A.size()-1].data); 
	return 0;
}
/*
00100 6 1
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
*/
