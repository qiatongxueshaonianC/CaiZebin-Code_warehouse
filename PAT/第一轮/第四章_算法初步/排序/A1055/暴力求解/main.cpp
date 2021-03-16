#include<bits/stdc++.h>
using namespace std;
struct Node{
	char name[9];
	int age,w;
	bool friend operator <(Node a,Node b){
		if(a.w!=b.w) return a.w>b.w;
		else if(a.age!=b.age) return a.age<b.age;
		else return strcmp(a.name,b.name)<0;
	}
}; 
vector<Node> A;
int main() {
	int N,K,age,w;
	char name[9];
	scanf("%d%d",&N,&K);
	A.resize(N);
	for(int i=0;i<N;i++)
		scanf("%s%d%d",&A[i].name,&A[i].age,&A[i].w);
	sort(A.begin(),A.end());
	for(int k=1;k<=K;k++){
		int num,u,v;
		scanf("%d%d%d",&num,&u,&v);
		printf("Case #%d:\n",k);
		bool flag=false;
		for(int i=0;i<A.size()&&num>0;i++){
			if(A[i].age>=u&&A[i].age<=v){
				printf("%s %d %d\n",A[i].name,A[i].age,A[i].w);
				num--;
				flag=true;
			}
		}
		if(flag==false) puts("None");	
	}
	return 0;
}
/*
12 4
Zoe_Bill 35 2333
Bob_Volk 24 5888
Anny_Cin 95 999999
Williams 30 -22
Cindy 76 76000
Alice 18 88888
Joe_Mike 32 3222
Michael 5 300000
Rosemary 40 5888
Dobby 24 5888
Billy 24 5888
Nobody 5 0
4 15 45
4 30 35
4 5 95
1 45 50
*/
