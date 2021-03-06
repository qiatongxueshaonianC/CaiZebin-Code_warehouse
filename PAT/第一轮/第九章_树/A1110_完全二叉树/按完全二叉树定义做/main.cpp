#include<bits/stdc++.h>
using namespace std; 
const int maxn=30;
struct Node{
	int left,right;
	Node(){
		left=right=-1;
	}
};
int n; 
	vector<Node> vct(maxn);
	bool harsh[maxn]={false};
int levelOrder(int root){
	queue<int> q;
	q.push(root);
	int v,num=0,now;
	while(q.size()){
	    now=q.front();q.pop();
		if(now!=-1){
			num++;
			v=now;
			q.push(vct[now].left);
			q.push(vct[now].right);
		}else{
			while(q.size()){
				if(q.front()!=-1) return -1;
				q.pop();
			}
		}
	} 
	return v;
}
int main() {
	string c1,c2;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>c1>>c2;
		if(c1!="-"){
			int v=stoi(c1);
			vct[i].left=v;
			harsh[v]=true;
		}
		if(c2!="-"){
			int v=stoi(c2);
			vct[i].right=stoi(c2);
			harsh[v]=true;
		}	
	}
	int root,ans;
	for(int i=0;i<n;i++){
		if(harsh[i]==false){
			root=i;
			break;
		}
	}
	ans=levelOrder(root);
	printf("%s %d\n",ans==-1?"NO":"YES",ans==-1?root:ans);
	return 0;
}
/*
9
7 8
- -
- -
- -
0 1
2 3
4 5
- -
- -

8
- -
4 5
0 6
- -
2 3
- 7
- -
- -
*/
