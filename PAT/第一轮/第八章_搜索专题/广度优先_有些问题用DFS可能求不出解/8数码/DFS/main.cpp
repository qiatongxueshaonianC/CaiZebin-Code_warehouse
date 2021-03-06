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
bool flag_;
bool judge(Node &s,int X,int Y){
	if(X<0||X>2||Y<0||Y>2) return false;
	swap(s.mp[s.x][s.y],s.mp[X][Y]);
	s.x=X;
	s.y=Y;
	if(flag[s.mp]==true) return false;
	return true;
}
void DFS(Node now){
	if(now.mp==ed.mp){
		printf("%d\n",now.step);
		flag_=true;
		return;
	} 
	flag[now.mp]=true;
	now.step++;
	for(int i=0;i<4;i++){     //DFS可能找不到解 
		Node temp=now;
		int newx=now.x+X[i];
		int newy=now.y+Y[i];
		if(judge(temp,newx,newy)&&now.step<10){  //DFS加上深度的限制可以得一半分数 
			DFS(temp);
		}
		if(flag_==true) return;
	}
	now.step--;
	flag[now.mp]=false;
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
	st.step=1;
	DFS(st);
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
