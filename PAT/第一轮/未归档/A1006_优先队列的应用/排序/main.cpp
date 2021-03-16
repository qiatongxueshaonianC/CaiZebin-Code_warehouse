#include<bits/stdc++.h>
using namespace std;
struct Node{
	string id;
	int H,M,S,h,m,s;
	Node(string s,int a,int b,int c,int d,int e,int f){
		id=s;
		H=a;M=b;S=c;
		h=d;m=e;s=f;
	}
	bool friend operator <(Node u,Node v){
		int a=u.H*3600+u.M*60+u.S;
		int b=v.H*3600+v.M*60+v.S;
		return a>b;
	}
}; 
priority_queue<Node> q;
vector<Node> A; 
bool cmp(Node u,Node v){
		int a=u.h*3600+u.m*60+u.s;
		int b=v.h*3600+v.m*60+v.s;
		return a>b;
	}
int main() {
	int n,H,M,S,h,m,s;
	string id;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>id;scanf("%d:%d:%d %d:%d:%d",&H,&M,&S,&h,&m,&s);
		q.push(Node(id,H,M,S,h,m,s));
		A.push_back(Node(id,H,M,S,h,m,s));
	}
	sort(A.begin(),A.end(),cmp);
	cout<<q.top().id<<' '<<A[0].id<<endl;
	return 0;
}
/*
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40
*/
