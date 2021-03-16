#include<bits/stdc++.h>
using namespace std; 
struct Node{
	int addr,next;
	char data;
}List[1000000];
int main() {
//	unordered_map<char,int> mp;   //同一个char可能对应多个id，所以不能这么存 
	int a1,a2,n,add,next;
	char c;
	scanf("%d%d%d",&a1,&a2,&n);
	for(int i=0;i<n;i++){
		scanf("%d ",&add);
		scanf("%c %d",&List[add].data,&List[add].next);
		List[add].addr=add;
	}
	vector<Node> s1,s2;
	while(a1!=-1){
		s1.push_back(List[a1]);
		a1=List[a1].next;
	}
	while(a2!=-1){
		s2.push_back(List[a2]);
		a2=List[a2].next;
	}
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	int len=min(s1.size(),s2.size());
	for(n=0;n<len;n++){
		if(s1[n].addr!=s2[n].addr) 
			break;
	}
	if(n==0||s1.size()==0||s2.size()==0) 
		puts("-1");
	else
		printf("%05d",s1[n-1].addr);
	return 0;
}
/*
11111 -1 9
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
