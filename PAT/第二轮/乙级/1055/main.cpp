#include<bits/stdc++.h>
using namespace std; 
struct Node{
	string name;
	int tall;
	Node(char a[],int b):name(a),tall(b){}
	bool friend operator <(Node u,Node v){
	//	return u.tall!=v.tall?u.tall<v.tall:u.name<v.name;   
		return u.tall!=v.tall?u.tall<v.tall:u.name>v.name;  //�����˳��о��е����
	} 
};
vector<Node> A;
void deal(int l,int r,vector<list<Node>>& ans,int idx){
	priority_queue<Node> q;
	for(int i=l;i<r;i++)
		q.push(A[i]);
	ans[idx].push_back(q.top());q.pop();
	for(int i=0;!q.empty();i++){
		if(i%2==0)
			ans[idx].push_front(q.top());
		else
			ans[idx].push_back(q.top());
		q.pop();
	}
}
int main() {
	int N,K,t,num,idx;
	scanf("%d%d",&N,&K);
	num=N/K;
	char name[10];
	for(int i=0;i<N;i++){
		scanf("%s%d",&name,&t);
		A.push_back(Node(name,t));
	}
	sort(A.begin(),A.end(),[](const Node& a,const Node& b){
	//	return a.tall!=b.tall?a.tall<b.tall:a.name<b.name;
		return a.tall!=b.tall?a.tall<b.tall:a.name>b.name; //�����˳��о��е����
	});
	vector<list<Node>> ans(K); 
	for(t=0,idx=K-1;t+2*num<=A.size();t+=num)
		deal(t,t+num,ans,idx--);
	deal(t,A.size(),ans,idx);
	for(int i=0;i<ans.size();i++){
		for(auto j=ans[i].begin();j!=ans[i].end();j++){
			printf("%s%s",j->name.c_str(),j==--ans[i].end()?"\n":" ");
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
