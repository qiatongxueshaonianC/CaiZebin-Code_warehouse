#include<bits/stdc++.h>
using namespace std;
const int inf=0x3fffffff; 
const int maxn=110;
struct Node{
	int to,dis;
	Node(int a,int b):to(a),dis(b){}
};
int n,d[maxn],inDegree[maxn],outDegree[maxn],numinq[maxn];
int st,ed,m,k;;
vector<int> temp,ans;
vector<Node> G[maxn];
unordered_map<char,int> mp;
unordered_map<int,char> itoc;
bool inq[maxn];
set<int> pre[maxn];
bool SPFA(int s){
	fill(d,d+maxn,-inf);
	fill(inq,inq+maxn,false);
	fill(numinq,numinq+maxn,0);
	d[s]=0;
	queue<int> q;
	q.push(s);
	inq[s]=true;
	numinq[s]++;
	while(!q.empty()){
		int u=q.front();q.pop();
		inq[u]=false;
		for(auto i:G[u]){
			int v=i.to,dis=i.dis;
			if(dis+d[u]>d[v]){
				d[v]=d[u]+dis;
				pre[v].clear();
				pre[v].insert(u);
				if(!inq[v]){
					q.push(v);
					inq[v]=true;
					numinq[v]++;
					if(numinq[v]>=m)return false;
				
				}
			}//else if(d[u]+dis==d[v])
			//		pre[v].insert(u);
		}
	}
	return true;
}
void DFS(int s){
	if(s==st){
		ans.push_back(s);
		return;
	}
	ans.push_back(s);
	DFS(*pre[s].begin());	
}
int main() {
	scanf("%d",&n);
	while(n--){
		string s1,s2;
		scanf("%d%d%*c",&m,&k);
		cin>>s1;
		for(int i=0;!s1.empty();i++){
			mp[s1[0]]=i;
			itoc[i]=s1[0];
			s1.erase(s1.begin());
		}
		int u,v,dis;
		for(int i=0;i<k;i++){
			cin>>s1>>s2>>dis;
			u=mp[s1[0]];
			v=mp[s2[0]];
			Node node(v,dis);
			G[u].push_back(node);
			inDegree[v]++;
			outDegree[u]++;
		}
		for(int i=0;i<m;i++){
			if(inDegree[i]==0) st=i;
			if(outDegree[i]==0) ed=i;
		}
		SPFA(st);
		DFS(ed);
		reverse(ans.begin(),ans.end());
		for(int i=0;i<ans.size()-1;i++){
			printf("(%c,%c)",itoc[ans[i]],itoc[ans[i+1]]);
			printf(" ");  
		}
		puts(to_string(d[ed]).c_str());
		for(int i=0;i<m;i++)
			G[i].clear();
		mp.clear();
		itoc.clear();
		ans.clear();
		memset(inDegree,0,sizeof(inDegree));
		memset(outDegree,0,sizeof(outDegree));
	}
	return 0;
}
/*
2
5 6
abcde 
a b 3 
a c 2 
b d 5 
c d 7 
c e 4 
d e 6 
4 5 
abcd 
a b 2 
a c 3 
a d 4 
b d 1 
c d 3 
*/
