#include<bits/stdc++.h>
using namespace std; 
struct Node{
	string id;
	int Gp,Gmid,Gfinal,G,flag;
	Node(){
		Gp=Gmid=Gfinal=-1;
		G=flag=0;
	} 
}A[30010];  //注意，这里可能会超过10000人  2019/12/5/0：15发现改正 
unordered_map<string,int> mp;
bool cmp(Node a,Node b){
	if(a.flag!=b.flag) return a.flag>b.flag;
	else if(a.G!=b.G) return a.G>b.G;
	else return a.id<b.id;
}
int main() {
	int p,m,n,idx=0,score,addr;
	string id;
	scanf("%d%d%d",&p,&m,&n);
	for(int i=0;i<p;i++){
		cin>>id>>score;
		if(mp.find(id)==mp.end())
			mp[id]=idx++;
		addr=mp[id];
		A[addr].Gp=score;
		A[addr].id=id;
		if(score>=200)
			A[addr].flag=1;
	}
	for(int i=0;i<m;i++){
		cin>>id>>score;
		if(mp.find(id)==mp.end())
			mp[id]=idx++;
		addr=mp[id];
		A[addr].Gmid=score;
		A[addr].id=id;
	}
	for(int i=0;i<n;i++){
		cin>>id>>score;
		if(mp.find(id)==mp.end())
			mp[id]=idx++;
		addr=mp[id];
		A[addr].Gfinal=score;
		A[addr].id=id;
	}
	for(int i=0;i<mp.size();i++){
		if(A[i].flag==0) continue;
		if(A[i].Gmid>A[i].Gfinal)
		//	A[i].G=(A[i].Gmid*0.4+max(A[i].Gfinal,0)*0.6)+0.5;
			A[i].G=round(A[i].Gmid*0.4+A[i].Gfinal*0.6);
		else A[i].G=A[i].Gfinal;
		if(A[i].G<60) A[i].flag=0;
	}
	sort(A,A+mp.size(),cmp); 
	for(auto i:A){
		if(i.flag==0) break;
		printf("%s %d %d %d %d\n",i.id.c_str(),i.Gp,i.Gmid,i.Gfinal,i.G);
	}
	return 0;
}
/*
6 6 7
01234 880
a1903 199
ydjh2 200
wehu8 300
dx86w 220
missing 400
ydhfu77 99
wehu8 55
ydjh2 98
dx86w 88
a1903 86
01234 39
ydhfu77 88
a1903 66
01234 58
wehu8 84
ydjh2 82
missing 99
dx86w 81
*/
