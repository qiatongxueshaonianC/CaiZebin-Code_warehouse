#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
struct Node{
	int weight;
	vector<int> child;
	int sumweight,father;
	Node():father(-1){}
	bool friend operator <(Node a,Node b){
		return a.weight<b.weight;
	}
/*	bool operator <(const Node& u)const{
		return weight>u.weight;
	}*/
}Tree[maxn];
int n,m,s; 
/*bool cmp(int a,int b){
	return Tree[a].weight>Tree[b].weight;
}*/
vector<int> temp;
priority_queue<vector<int> > ans;
void BFS(int u){
	priority_queue<int> q;
	q.push(u);
	Tree[u].sumweight=Tree[u].weight;
	while(!q.empty()){
		int now=q.top();q.pop();
		if(Tree[now].sumweight==s&&Tree[now].child.size()==0){
			stack<int> st;
			while(Tree[now].father!=-1){
				st.push(now);
				now=Tree[now].father;
			}
			st.push(now);
			while(!st.empty()){
				temp.push_back(Tree[st.top()].weight);
				st.pop();
			}
			ans.push(temp);
			temp.clear(); 
		}else{
			for(int i:Tree[now].child){
				Tree[i].father=now;
				Tree[i].sumweight=Tree[now].sumweight+Tree[i].weight;
				if(Tree[i].sumweight>s) continue;  //剪枝 
				q.push(i);
			}
		}
	}
}
int main() {
	scanf("%d%d%d",&n,&m,&s);
	for(int i=0;i<n;i++){
		scanf("%d",&Tree[i].weight);
	}
	int id,num,v;
	for(int i=0;i<m;i++){
		scanf("%d%d",&id,&num);
		for(int j=0;j<num;j++){
			scanf("%d",&v);
			Tree[id].child.push_back(v);
		}
	//	sort(Tree[id].child.begin(),Tree[id].child.end(),cmp);  //将weight大的放在前面，在做DFS时直接
	//访问即可，因为是一条道走到底，BFS不行，可能序大的路径长，BFS会导致输出顺序出错 
	}
	BFS(0);
	while(!ans.empty()){
		vector<int> now=ans.top();ans.pop();
		for(int j=0;j<now.size();j++){
			printf("%d",now[j]);
			if(j<now.size()-1) printf(" ");
		}
		puts("");
	}
	return 0;
}
/*
20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 03 02 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19
*/
