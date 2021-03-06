#include<stdio.h>
#include<queue>
#include<algorithm>
#include<map>
using namespace std; 
struct Node{
	double stor,p;
	Node(double a,double b):stor(a),p(b){}
	bool friend operator <(Node a,Node b){
		return a.p/a.stor<b.p/b.stor;
	}
};
priority_queue<Node> q;
int main() {
	int kind,need;
	scanf("%d%d",&kind,&need);
	double ans=0;
	vector<double> storage(kind),price(kind);
	for(int i=0;i<kind;i++)
		scanf("%lf",&storage[i]);
	for(int i=0;i<kind;i++)
		scanf("%lf",&price[i]);
	for(int i=0;i<kind;i++)
		q.push(Node(storage[i],price[i]));
	while(q.size()&&need>0){
		Node now=q.top();q.pop();
		if(need>now.stor){
			ans+=now.p;
			need-=now.stor;
		}
		else {
			ans+=(need/now.stor*now.p);
			need=0;
		}	
	}
	printf("%.2lf",ans);
	return 0;
}
/*
3 200
180 150 100
7.5 7.2 4.5
*/
