#include<bits/stdc++.h>
using namespace std; 
struct Node{
	int id,data,next;
}L[100005];
vector<Node> adjust(vector<Node> &A){
	for(int i=0;i<A.size()-1;i++)
		A[i].next=A[i+1].id;
	A[A.size()-1].next=-1;
	return A;
}
void output(vector<Node> A){
	for(int i=0;i<A.size()-1;i++)
		printf("%05d %d %05d\n",A[i].id,A[i].data,A[i].next);
	printf("%05d %d -1\n",A[A.size()-1].id,A[A.size()-1].data);
}
int main() {
	int st,n,id;
	scanf("%d%d",&st,&n);
	for(int i=0;i<n;i++){
		scanf("%d",&id);
		L[id].id=id;
		scanf("%d%d",&L[id].data,&L[id].next);
	}
	vector<Node> A,remove;
	unordered_set<int> mp;
	while(st!=-1){
		if(mp.find(abs(L[st].data))==mp.end()){
			A.push_back(L[st]);	
			mp.insert(abs(L[st].data));
		}else
			remove.push_back(L[st]);
		st=L[st].next;
	}
	if(A.size()){  //链表的题都有特殊情况空链表的判断，注意！！！！！！好几次掉坑里了 
		adjust(A);
		output(A);
	}
	if(remove.size()){
		adjust(remove);
		output(remove);
	}
	return 0;
}
/*
00100 5
99999 -7 87654
23854 -15 00000
87654 15 -1
00000 -15 99999
00100 21 23854
*/
