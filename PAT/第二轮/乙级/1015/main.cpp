#include<bits/stdc++.h>
using namespace std; 
struct Node{
	int id,de,cai,sum;
}node;
vector<Node> A[4]; 
bool cmp(Node a,Node b){
	if(a.sum!=b.sum)
		return a.sum>b.sum;
	else if(a.de!=b.de)
		return a.de>b.de;
	else return a.id<b.id;
}
int main() {
	int N,L,H,num=0;
	scanf("%d%d%d",&N,&L,&H);
	for(int i=0;i<N;i++){
		scanf("%d%d%d",&node.id,&node.de,&node.cai);
		node.sum=node.de+node.cai;
		if(node.de<L||node.cai<L)
			continue;
		if(node.de>=H&&node.cai>=H)
			A[0].push_back(node);
		else if(node.de>=H&&node.cai<H)
			A[1].push_back(node);
		else if(node.de>=node.cai)
			A[2].push_back(node);
		else 
			A[3].push_back(node);
		num++;
	}
	for(auto &i:A)
		sort(i.begin(),i.end(),cmp);
	printf("%d\n",num);
	for(auto i:A){
		for(auto j:i)
			printf("%08d %d %d\n",j.id,j.de,j.cai);
	}
}
/*
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
*/
