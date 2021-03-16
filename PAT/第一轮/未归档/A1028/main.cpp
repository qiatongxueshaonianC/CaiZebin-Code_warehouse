#include<bits/stdc++.h>
using namespace std;
struct Node{
	int id,grade;
	string name;
	Node(int a,string b,int c):id(a),name(b),grade(c){}
};
int n,now; 
vector<Node> vct;
bool cmp(Node a,Node b){
	if(now==1) return a.id<b.id;
	else if(now==2) return a.name!=b.name?a.name<b.name:a.id<b.id;
	else if(now==3){
		return a.grade!=b.grade?a.grade<b.grade:a.id<b.id;
	}
}
int main() {
	int u,w;
	string v;
	scanf("%d%d",&n,&now);
	for(int i=0;i<n;i++){
		cin>>u>>v>>w;
		vct.push_back(Node(u,v,w));
	}
	sort(vct.begin(),vct.end(),cmp);
	for(auto i:vct)
		printf("%06d %s %d\n",i.id,i.name.c_str(),i.grade);
	return 0;
}
/*
3 1
000007 James 85
000010 Amy 90
000001 Zoe 60

4 2
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 98

4 3
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 90
*/
