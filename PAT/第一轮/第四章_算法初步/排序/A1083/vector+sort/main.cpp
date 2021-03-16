#include<bits/stdc++.h>
using namespace std; 
struct Node{
	char name[11],id[11];
	int score;
	bool friend operator <(Node a,Node b){
		return a.score>b.score;
	}
};
vector<Node> A;
int main() {
	int N,score,low,high;
	scanf("%d",&N);
	A.resize(N);
	char name[11],id[11];
	for(int i=0;i<N;i++)
		scanf("%s%s%d",&A[i].name,&A[i].id,&A[i].score);
	sort(A.begin(),A.end());
	scanf("%d%d",&low,&high);
	bool flag=false;
	for(auto i:A)
		if(i.score>=low&&i.score<=high){
			printf("%s %s\n",i.name,i.id,i.score);
			flag=true;
		}
	if(flag==false)
		puts("NONE");	
	return 0;
}
/*
4
Tom CS000001 59
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
60 100

2
Jean AA980920 60
Ann CS01 80
90 95
*/
