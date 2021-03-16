#include<bits/stdc++.h>
using namespace std; 
struct Node{
	string name;
	int tall;
	Node(char a[],int b){
	//	name.append(a);
		name=a; 
		tall=b;
	}
	bool friend operator <(Node a,Node b){  //首先矮的在前面，一样高的 
		return a.tall!=b.tall?a.tall>b.tall:a.name<b.name;//2019/11/28/18:25发现 
	//	return a.tall!=b.tall?a.tall<b.tall:a.name>b.name;  //想不通为什么这里是 a.name<b.name
	}
	Node(){}
};
struct cmp{
	bool  operator () (const Node &a,const Node &b){
		return a.tall!=b.tall?a.tall<b.tall:a.name>b.name;  //高的在前面，一样高的名字小的放前面 
	}
};
vector<priority_queue<Node,vector<Node>,cmp>> A;
vector<vector<Node>> ans;
priority_queue<Node> q,test;
void deal(priority_queue<Node,vector<Node>,cmp> a){
	int m=a.size()/2;  //下标从0开始，就不要加一了
	int left=m-1,right=m+1,index=1;
	vector<Node> temp(a.size());
	temp[m]=a.top();a.pop();
	while(a.size()){
		if(index%2==1){
			temp[left--]=a.top();a.pop();
		}else{
			temp[right++]=a.top();a.pop();
		}
		index++;
	}
	ans.push_back(temp);
}
int main() {
	int N,K,tall,row;
	char name[9];
	scanf("%d%d",&N,&K);
	row=N/K;
	for(int i=0;i<N;i++){
		scanf("%s%d",&name,&tall);
		q.push(Node(name,tall));
	}
/*	puts("");
	test=q;
	while(test.size()){
		printf("%s %d\n",test.top().name.c_str(),test.top().tall);
		test.pop();
	}
	puts("");*/
	while(q.size()){
		priority_queue<Node,vector<Node>,cmp> temp;
		for(int i=0;i<row;i++){
			temp.push(q.top());
			q.pop();
		}
		if(q.size()<row){
			while(q.size()){
				temp.push(q.top());
				q.pop();
			}
		}
		A.push_back(temp);
	}
	for(auto &i:A){
		deal(i);
	}
	for(int i=ans.size()-1;i>=0;i--){
		for(int j=0;j<ans[i].size();j++){
			printf("%s%s",ans[i][j].name.c_str(),j==ans[i].size()-1?"\n":" ");
		}
	}
	return 0;
}
/*
10 3
Tom 188
Mike 170
Eva 168
Tim 160
Joe 190
Ann 168
Bob 175
Nick 186
Amy 160
John 159

10 3
Tom 188
Mike 188
Eva 188
Tim 188
Joe 188
Ann 188
Bob 188
Nick 188
Amy 188
John 188
*/
