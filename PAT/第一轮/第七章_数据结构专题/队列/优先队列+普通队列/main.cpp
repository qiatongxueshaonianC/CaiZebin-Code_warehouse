#include<bits/stdc++.h>
using namespace std; 
struct Node{
	int w,range,turn;
	bool friend operator <(Node a,Node b){
		return a.w<b.w;
	}
}Mouse[1010];
bool cmp(pair<Node,int> a,pair<Node,int> b){
	return a.first.turn>b.first.turn;
}
bool cmp2(pair<Node,int> a,pair<Node,int> b){
	return a.second<b.second;
}
void deal(vector<pair<Node,int>> &A){
	int range=1;
	A[0].first.range=1;
	for(int i=1;i<A.size();i++){
		range=A[i].first.turn==A[i-1].first.turn?range:i+1;
		A[i].first.range=range;
	}
}
int main() {
	int np,ng,v,turn=0;
	scanf("%d%d",&np,&ng);
	for(int i=0;i<np;i++)
		scanf("%d",&Mouse[i].w);
	queue<pair<Node,int> > q;
	for(int i=1;i<=np;i++){
		scanf("%d",&v);
		q.push({Mouse[v],v});
	}
	vector<pair<Node,int>> ans;
	while(q.size()>1){
		turn++;
		queue<pair<Node,int>> temp;
		while(q.size()){
			priority_queue<pair<Node,int>> pri_q;
			for(int i=0;i<ng&&q.size();i++){
				pri_q.push(q.front());
				q.pop();
			}
			temp.push(pri_q.top());pri_q.pop();  //晋级 
			while(pri_q.size()){  //本轮输掉比赛的老鼠 
				pair<Node,int> now=pri_q.top();pri_q.pop();
				now.first.turn=turn;
				ans.push_back(now);
			}
		}
		while(temp.size()){  //进入下一轮 
			q.push(temp.front());
			temp.pop();
		}
	}
	pair<Node,int> now=q.front();
	now.first.turn=++turn;   //冠军老鼠，走到最后一轮 
	ans.push_back(now);
	sort(ans.begin(),ans.end(),cmp);
	deal(ans);
	sort(ans.begin(),ans.end(),cmp2);  //按顺序输出各只老鼠的排名 
	for(auto i=0;i<ans.size();i++)
		printf("%d%s",ans[i].first.range,i==ans.size()-1?"\n":" "); 
	return 0;
}
/*
11 3
25 18 0 46 37 3 19 22 57 56 10
6 0 8 7 10 5 9 1 4 2 3
*/
