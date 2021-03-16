#include<bits/stdc++.h>
using namespace std; 
struct Node{
	vector<vector<int>> mp;   //如果定义了初始大小为3则后续无法比较是否相对 
	int x,y,step;
	Node(){
		x=y=step=-1;
	}
}st,ed;
int X[]={1,-1,0,0};
int Y[]={0,0,1,-1};
map<vector<vector<int>>,bool> flag;
bool judge(Node &s,int X,int Y){
	if(X<0||X>2||Y<0||Y>2) return false;
	swap(s.mp[s.x][s.y],s.mp[X][Y]);
	s.x=X;
	s.y=Y;
	if(flag[s.mp]==true) return false;
	return true;
}
void BFS(Node s){
	queue<Node> q;
	s.step=1;
	q.push(s);
	flag[s.mp]=true;
	while(!q.empty()){
		Node now=q.front();q.pop();
		if(now.mp==ed.mp){
			puts(to_string(now.step).c_str());
			break;
		}
		for(int i=0;i<4;i++){
			Node temp=now;
			int newx=now.x+X[i];
			int newy=now.y+Y[i];
			if(judge(temp,newx,newy)){
				temp.step++;
				q.push(temp);
				flag[temp.mp]=true;
			}
		}
	}
}
int main() {
	int v;
	for(int i=0;i<3;i++){
		vector<int> tp;
		st.mp.push_back(tp);
		for(int j=0;j<3;j++){
			scanf("%d",&v);
			st.mp[i].push_back(v);
			if(v==0){
				st.x=i;
				st.y=j;
			}
		}
	}
	for(int i=0;i<3;i++){
		vector<int> tp;
		ed.mp.push_back(tp);
		for(int j=0;j<3;j++){
			scanf("%d",&v);
			ed.mp[i].push_back(v);
			if(v==0){
				ed.x=i;
				ed.y=j;
			}
		}
	}
	BFS(st);
	return 0;
}
/*
2 8 3 
1 6 4 
7 0 5 
1 2 3 
8 0 4 
7 6 5 
*/ 
