#include<bits/stdc++.h>
using namespace std; 
struct Edge{
	int u,v;
	double cost;
	Edge(int a,int b,double c):u(a),v(b),cost(c){}
	bool friend operator < (const Edge& a,const Edge& b){
		return a.cost<b.cost;
	}
};
struct Node{
	int father,ans_id;
	double h,maxweight;
	Node(double a,int b=-1,double c=0.0):h(a),father(b),maxweight(c){}
};
int n,e;
double c; 
vector<int> ddd{1};
vector<Edge> edges;
vector<Node> node;
vector<set<int>> ans;
int findFather(int a){
	if(node[a].father<0)
		return a;
	int temp=findFather(node[a].father);
	node[a].father=temp;
	return temp;
}
void solve(){
	for(auto e:edges){
		int fa=findFather(e.u),fb=findFather(e.v);
		if(fa>fb)
			swap(fa,fb);  //����������ʱҪС����ǰ�� 
		if(fa!=fb&&e.cost<=node[fa].h&&e.cost<=node[fb].h){ //2020/2/9/01��17���֣���������� 
			node[fa].father+=node[fb].father;		//���ڣ����Ժϲ���С�ڵ��� 
			node[fb].father=fa;
			node[fa].maxweight=max(node[fa].maxweight,e.cost);
			node[fa].h=node[fa].maxweight+c/(abs(node[fa].father));
		}
	}
	for(int i=0;i<node.size();i++){
		if(node[i].father<0){
			node[i].ans_id=ans.size();
			ans.push_back({i});  //������ans�д��ֻ�Ǹ� 
		}
	}
	for(int i=0;i<node.size();i++){
		if(node[i].father>=0)
			ans[node[findFather(i)].ans_id].insert(i);
	} 
	for(auto i:ans){
		for(auto j:i)
			printf("%d%s",j,j==*(--i.end())?"\n":" ");
	} 
}
int main() {
	/*	���ܲ��ԣ�set�ĳ�ʼ��
	vector<set<int>> q;
	q.push_back(set<int>{666});
		for(auto i:q)
		for(auto j:i)
			printf("%d",j);*/
	scanf("%d%d%lf",&n,&e,&c);
	for(int i=0;i<n;i++)
		node.push_back(Node(c)); 
	while(e--){
		int a,b,cost;
		scanf("%d%d%d",&a,&b,&cost);
		edges.push_back(Edge(a,b,cost));
	}
	sort(edges.begin(),edges.end());
	solve();
	return 0;
}
/*
10 21 100
0 1 10
0 3 60
0 4 90
1 2 90
1 3 50
1 4 200
1 5 86
2 4 95
2 5 5
3 4 95
3 6 15
3 7 101
4 5 500
4 6 100
4 7 101
4 8 101
5 7 300
5 8 50
6 7 90
7 8 84
7 9 34

7 7 100
0 1 10
1 2 61
2 3 50
3 4 200
4 5 82
5 0 200
3 6 90
*/
