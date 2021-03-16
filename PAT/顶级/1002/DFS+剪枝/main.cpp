#include<bits/stdc++.h>
using namespace std; 
struct Node{
	int profit,need,dl;
	Node(int a,int b,int c):profit(a),need(b),dl(c){}
	bool operator <(const Node& a){
		return dl!=a.dl?dl<a.dl:need<a.need;
	}
};
vector<Node> A;
int N,ans;
void DFS(int idx,int nowtime,int Profit){
    if(idx>=N) return;
	if(nowtime+A[idx].need>A[idx].dl)
		DFS(idx+1,nowtime,Profit);  //��ѡ 
    else{
        if(ans<Profit+A[idx].profit)  //ѡ 
		ans=Profit+A[idx].profit;
	    DFS(idx+1,nowtime+A[idx].need,Profit+A[idx].profit); //��һ������
	    DFS(idx+1,nowtime,Profit);  //��ѡ
    }
}
int main() {
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		A.push_back(Node(a,b,c));
	}
	sort(A.begin(),A.end());
	DFS(0,0,0);
	printf("%d",ans); 
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

