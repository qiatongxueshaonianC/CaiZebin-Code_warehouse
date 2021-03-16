#include<bits/stdc++.h> 
using namespace std;
const int MAXV=1010;
struct Node{
	int id,layer;
	Node(int a,int b){
		id=a;
		layer=b;
	}
	Node(){};
};
vector<Node> Adj[MAXV];
bool inq[MAXV]={false};
int L;
int BFS(int s){
	int numperson=0;
	queue<Node> q;
	q.push(Node(s,0));
	inq[s]=true;
	while(!q.empty()){
		Node now=q.front();
		q.pop();
		int u=now.id;
		inq[u]=false; 
		for(int i=0;i<Adj[u].size();i++){
			Node next=Adj[u][i];
			next.layer =now.layer +1;
			if(next.layer <=L&&inq[next.id ]==false){
				q.push(next);
				inq[next.id ]=true;
				numperson++;
			}
		}
	}
	return numperson;
}
int main() {
	int n,query;
	scanf("%d%d%*c",&n,&L);
	for(int i=1;i<=n;i++){
		int num,follow;
		Node user;
		user.id =i;
		scanf("%d",&num);
		while(num--){
			scanf("%d",&follow);
			Adj[follow].push_back(user);
		}
	}
	scanf("%d",&query);
	while(query--){
		int v;
		scanf("%d",&v);
		memset(inq,false,sizeof(inq));
		int ans=BFS(v);
		string a=to_string(ans);
		//cout<<a<<endl;
		//puts(a.c_str());
		printf("%d\n",stoi(a));
	}
	return 0;
}
