#include<bits/stdc++.h>
using namespace std;
const int maxn=30;
struct Node{
	string data;
	int left=-1,right=-1;
};
int n; 
vector<Node> Tree;
bool child[maxn];
vector<string> st;
void inOrder(int root){
	if(root==-1) return;
	st.push_back(Tree[root].data);
	inOrder(Tree[root].left);
	inOrder(Tree[root].right);
	if(Tree[root].left!=-1||Tree[root].right!=-1) {  //有孩子节点存在 
		string s1,s2,op;
		if(Tree[root].left!=-1&&Tree[root].right!=-1){
			s2=st.back();st.pop_back();
			s1=st.back();st.pop_back();
			op=st.back();st.pop_back();
			s1='('+s1+op+s2+')';
			st.push_back(s1);
		}else{
			s1=st.back();st.pop_back();
			op=st.back();st.pop_back();
			s1='('+op+s1+')';
			st.push_back(s1);
		}		
	}
}
int main() {
	scanf("%d",&n);
	Tree.resize(n+1);
	string s;
	int u,v,root;
	for(int i=1;i<=n;i++){
		cin>>Tree[i].data>>Tree[i].left>>Tree[i].right;
		if(Tree[i].left!=-1) child[Tree[i].left]=true;
		if(Tree[i].right!=-1) child[Tree[i].right]=true;
	}
	if(n==1) { //2019/11/2/20:41增加 
		cout<<Tree[1].data<<endl;
		return 0;
	}
	root=find(child+1,child+n+1,false)-child; //利用find函数查找根节点 
	inOrder(root);
	s=st.back();
	s.erase(s.begin());s.erase(--s.end());
	puts(s.c_str());
	return 0;
}
/*
8
* 8 7
a -1 -1
* 4 1
+ 2 5
b -1 -1
d -1 -1
- -1 6
c -1 -1

8
2.35 -1 -1
* 6 1
- -1 4
% 7 8
+ 2 3
a -1 -1
str -1 -1
871 -1 -1
*/
