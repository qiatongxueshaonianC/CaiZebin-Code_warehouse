#include<bits/stdc++.h>
using namespace std; 
struct Node{
	int profit,need,dl;
	bool operator <(const Node& a){
		return need<a.need; 
	//	return dl!=a.dl?dl<a.dl:need<a.need;
	}
};
vector<Node> A;
int N;
bool cmp(const Node& a,const Node& b){
		return a.dl>b.dl;  //和优先队列一样反过来用 
}
int main() {
	scanf("%d",&N);
	A.resize(N+1);
	for(int i=1;i<=N;i++)
		scanf("%d%d%d",&A[i].profit,&A[i].need,&A[i].dl);
	Node I=(*min_element(A.begin(),A.end(),cmp));
	T=I.dl;
	printf("%d",T); 
	return 0;
}
/*
4
7 1 3
10 2 3
6 1 2
5 1 1

3
6 3 3
3 2 2
4 1 3
*/

