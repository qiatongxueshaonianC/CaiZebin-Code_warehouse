#include<bits/stdc++.h>
using namespace std; 
struct Node{
	int id,data,next;
}L[100005];
int st,n,l;
vector<Node> A;
int main() {
	scanf("%d%d%d",&st,&n,&l);
	int id,da,nex;
	for(int i=0;i<n;i++){
		scanf("%d",&id);
		L[id].id=id;
		scanf("%d%d",&L[id].data,&L[id].next);
	}
	while(st!=-1){
		A.push_back(L[st]);
		st=L[st].next;
	}
	for(int i=0;i+l<=A.size();i+=l)
		reverse(A.begin()+i,A.begin()+i+l);	
	if(l>A.size()) 
		reverse(A.begin(),A.end());
	for(int i=0;i<A.size();i++){
		if(i!=A.size()-1) printf("%05d %d %05d\n",A[i].id,A[i].data,A[i+1].id);
		else printf("%05d %d %d\n",A[i].id,A[i].data,-1);
	}
	return 0;
}
/*
00100 6 3
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

00100 1 12309
12309 2 33218
33218 3 00000
00000 4 99999
99999 5 68237
68237 6 -1

00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

00100 6 10
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

00100 6 6
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
*/ 
