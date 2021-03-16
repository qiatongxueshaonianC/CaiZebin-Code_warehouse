#include<bits/stdc++.h>
using namespace std; 
struct Node{
	int id,de,cai,flag;
	bool friend operator <(Node u,Node v){
		if(u.flag!=v.flag) return u.flag<v.flag;
		else if(u.de+u.cai!=v.de+v.cai) return u.de+u.cai>v.de+v.cai;
		else if(u.de!=v.de) return u.de>v.de;
		else return u.id<v.id;
	}
}now;
set<Node> st;
int main() {
	int N,L,H,id,de,cai;
	scanf("%d%d%d",&N,&L,&H);
	for(int i=0;i<N;i++){
		scanf("%d%d%d",&now.id,&now.de,&now.cai);
		if(now.de<L||now.cai<L) continue;
		if(now.de>=H&&now.cai>=H) now.flag=1;
		else if(now.de>=H&&now.cai<H) now.flag=2;
		else if(now.de>=now.cai) now.flag=3;   //2019/11/23/0:02发现错误，是ne>=cai,不是说只大于 
		else now.flag=4;
		st.insert(now);
	}
	printf("%d\n",st.size());
	for(auto i:st)
		printf("%d %d %d\n",i.id,i.de,i.cai);
	return 0;
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
