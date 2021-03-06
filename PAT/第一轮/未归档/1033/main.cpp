#include<bits/stdc++.h>
using namespace std;
const int inf=0x3fffffff;
struct Node{
	double price;
	int dis;
	Node(double a,int b):price(a),dis(b){}
};
int C,Dis,P,n; 
vector<Node> q;
bool cmp(Node a,Node b){
	return a.dis<b.dis;
}
int main() {
	scanf("%d%d%d%d",&C,&Dis,&P,&n);
	double price,ans=0;
	int dis;
	for(int i=0;i<n;i++){
		scanf("%lf%d",&price,&dis);
		Node node(price,dis);
		q.push_back(node);
	}
//	Node node(0.00,Dis);
	q.push_back(Node(0.00,Dis));
	sort(q.begin(),q.end(),cmp);
	if(q[0].dis>0) puts("The maximum travel distance = 0.00");
	else{
		int k=C*P;
		int ava=0;
		for(int i=0;i<q.size()-1;){
			bool flag=false;
			price=q[i].price;
			dis=C*P;
			int index=i;
			if(q[i+1].dis-q[i].dis>C*P){
				printf("The maximum travel distance = %.2lf\n",(double)(q[i].dis+C*P));
				return 0;
			}
			for(int j=i+1;q[j].dis<=k&&j<q.size();j++){
				if(price>q[j].price){
					price=q[j].price;
					dis=q[j].dis-q[index].dis;  //计算相对距离； 
					i=j;
					flag=true;
					break;
				}
			}
			if(flag==true){
				if(ava<dis) {
					ans+=(q[index].price*(dis-ava));
					ava=0;
				}else ava-=dis;
				k=q[i].dis+C*P;   //更新距离为下一个站点能到达的最大距离 
			}else{  //没找到比本加油站更便宜的加油站 
				ans+=q[index].price*(C*P-ava);
				k=q[index+1].dis+C*P;
				ava=C*P-q[index+1].dis+q[index].dis;
				i++;
			}
		}
		printf("%.2lf",ans/P);
	}
	return 0;
}
/*
50 1300 12 8
6.00 1250
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.30 1000
6.85 300

50 1300 12 2
7.10 0
7.00 600
*/
