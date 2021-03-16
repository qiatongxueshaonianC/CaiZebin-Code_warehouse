#include<bits/stdc++.h>
using namespace std;
struct Node{
	char me;
	int weight;
	vector<int> path;
	Node *left,*right;
	Node(char a,int b){
		me=a;
		weight=b;
		left=right=NULL;
	}
	Node(char a,int b,Node* c,Node* d){
		me=a;
		weight=b;
		left=c;
		right=d;
	}
	bool friend operator <(Node a,Node b){
		if(a.weight!=b.weight) return a.weight>b.weight;  //weight小的放前面 
		else return a.me>b.me;  // 字典序小的放前面 
	}
};
priority_queue<Node> q;
int n; 
vector<int> ans;
void DFS(Node* root){
	if(root->left==NULL&&root->right==NULL){
		printf("%c:",root->me);
		for(auto i:ans)
			printf("%d",i);
		puts("");
		return;
	}
	ans.push_back(0);
	DFS(root->left);
	ans.pop_back();
	ans.push_back(1);
	DFS(root->right);
	ans.pop_back();
}
int main() {
	while(scanf("%d%*c",&n)!=EOF){
		char c;
		int u;
		for(int i=0;i<n;i++){
			scanf("%c %d%*c",&c,&u);
			q.push(Node(c,u));
		}
		while(q.size()>1){
			Node *left=new Node(q.top());q.pop();
			Node *right=new Node(q.top());q.pop();
			q.push(Node(left->me,left->weight+right->weight,left,right));
		}
		Node *root=new Node(q.top()); q.pop();
		DFS(root);
	}
	return 0;
}
/*
3
a 10
b 5
c 8
4
a 1
b 1
c 1
d 1 
*/
