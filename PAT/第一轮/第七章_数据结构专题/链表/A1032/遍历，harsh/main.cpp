#include<bits/stdc++.h>
using namespace std; 
struct Node{
	char data;
	int id,next,flag;
	Node():flag(-1){}
}L[100005];
int main() {
	int l1,l2,n,id,next;
	char c;
	scanf("%d%d%d",&l1,&l2,&n);
	for(int i=0;i<n;i++){
		scanf("%d ",&id);
		L[id].id=id;
		scanf("%c %d",&L[id].data,&L[id].next);
	}
	while(l1!=-1){
		L[l1].flag=1;
		l1=L[l1].next;
	}
	while(l2!=-1){
		if(L[l2].flag==1) break;
		l2=L[l2].next;
	}
	if(l2==-1) puts("-1");
	else printf("%05d\n",L[l2].id);
	return 0;
}
/*
11111 22222 9
67890 i 00002
00010 a 12345
00003 g -1
12345 D 67890
00002 n 00003
22222 B 23456
11111 L 00001
23456 e 67890
00001 o 00010

00001 00002 4
00001 a 10001
10001 s -1
00002 a 10002
10002 t -1
*/
