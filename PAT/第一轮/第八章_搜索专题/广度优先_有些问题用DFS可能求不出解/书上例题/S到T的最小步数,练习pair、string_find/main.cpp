#include<bits/stdc++.h>
using namespace std; 
const int maxn=110;
typedef pair<int,int> P;
struct Node{
	int x,y;
};
int n,m,G[maxn][maxn];
bool inq[maxn][maxn];
pair<int,int> st,ed;
vector<P> XY={{-1,0},{0,1},{0,-1},{1,0}};
bool judge(pair<int,int> a){
	if(a.first>=n||a.first<0||a.second>=m||a.second<0) return false;
	if(inq[a.first][a.second]==true||G[a.first][a.second]==1) return false;
	return true;
}
void BFS(pair<int,int> a){
	queue<pair<pair<int,int>,int>> q;
	q.push(make_pair(a,0));
	inq[a.first][a.second]=true;
	while(!q.empty()){
		pair<pair<int,int>,int> now=q.front();q.pop();
		if(now.first.first==ed.first&&now.first.second==ed.second){
			puts(to_string(now.second).c_str());
			break;
		}
		for(int i=0;i<4;i++){
			P node({now.first.first+XY[i].first,now.first.second+XY[i].second});
			if(judge(node)){
				q.push(make_pair(node,now.second+1));
				inq[node.first][node.second]=true;
			}
		}
	}
}
int main() {
	scanf("%d%d",&n,&m);
	string s1;
	int k,pos;
	for(int i=0;i<n;i++){
		k=pos=0;
		cin>>s1;
		pos=s1.find('S',k);
		if(pos!=string::npos) st=make_pair(i,pos);
		pos=s1.find('T',k);
		if(pos!=string::npos) ed=make_pair(i,pos);
		while(1){
			pos=s1.find('*',k);
			if(pos==string::npos) break;
			G[i][pos]=1;
			k=pos+1;
		}
	}
	cout<<st.first<<','<<st.second<<endl;
	cout<<ed.first<<','<<ed.second<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			printf("%d",G[i][j]);
		puts("");
	}
	BFS(st);
	return 0;
}
/*
5 5
.....
.*.*.
.*S*.
.***.
...T*
*/
