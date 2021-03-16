#include<bits/stdc++.h>
using namespace std; 
const int maxn=2010;
struct Node{
	int grade[4];
	string id;
	int rank[4];
	Node(string s,int x,int y,int z){
		id=s;
		grade[1]=x;
		grade[2]=y;
		grade[3]=z;
		grade[0]=x+y+z;
	}
	Node(){	}
};
map<string,Node> mp;
vector<Node> vct;
string c="ACME";
int n,m,now;
bool cmp(Node u,Node v){
	return u.grade[now]>v.grade[now]; 
}
int main() {
	cin>>n>>m;
	string id;
	int u,v,w;
	if(n==0){
		for(int i=0;i<m;i++){
			cin>>id;
	 		puts("N/A");
		}
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>id>>u>>v>>w;
		Node node(id,u,v,w);
		mp.insert({id,node});
		vct.push_back(node);
	}
	for(now=0;now<4;now++){
		int index=1;
		sort(vct.begin(),vct.end(),cmp);
		mp[vct[0].id].rank[now]=index;
		for(int i=1;i<vct.size();i++){
		//	mp[vct[i].id].rank[now]=vct[i].grade[now]==vct[i-1].grade[now]?index:++index; 
		//2019年10月22日18：49发现错误
			if(mp[vct[i].id].grade[now]==mp[vct[i-1].id].grade[now])
				 mp[vct[i].id].rank[now]=index;
			else{
				mp[vct[i].id].rank[now]=i+1;
				index=i+1;
			}
		}
	}
	for(int i=0;i<m;i++){
		cin>>id;
		if(mp.find(id)==mp.end()){
			puts("N/A");
			continue;
		}
		int min=maxn,index=0;
		for(int i=0;i<4;i++){
			if(mp[id].rank[i]<min){
				min=mp[id].rank[i];
				index=i;
			}
		}
		printf("%d %c\n",mp[id].rank[index],c[index]);
	}
	return 0;
}
/*
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999

0 6
310101
310102
310103
310104
310105
999999
*/
