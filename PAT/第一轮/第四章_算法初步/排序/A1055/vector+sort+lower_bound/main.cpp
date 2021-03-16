#include<bits/stdc++.h>
using namespace std;
struct Node{
	char name[9];
	int age,w;
	bool friend operator <(Node a,Node b){
		return a.age<b.age;
	}
}; 
vector<Node> A;
int lower_bound(int low,int high,int v){
	int mid;
	while(low<high){
		mid=(low+high)/2;
		if(v<=A[mid].age)
			high=mid;
		else low=mid+1;
	}
	return low;
}
int upper_bound(int low,int high,int v){
	int mid;
	while(low<high){
		mid=(low+high)/2;
		if(v<A[mid].age)
			high=mid;
		else low=mid+1;
	}
	return low;
}
bool cmp(Node a,Node b){
	if(a.w!=b.w) return a.w>b.w;
	else if(a.age!=b.age) return a.age<b.age;
	else return strcmp(a.name,b.name)<0;
}
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
		int left=lower_bound(0,A.size(),u);
		int right=upper_bound(0,A.size(),v);
		if(right-left<=0){
			puts("None");
			continue;
		}
		vector<Node> B(A.begin()+left,A.begin()+right);
		sort(B.begin(),B.end(),cmp);
		for(int i=0;i<B.size()&&num>0;i++,num--)
			printf("%s %d %d\n",B[i].name,B[i].age,B[i].w);
	/*	sort(B.begin()+left,B.begin()+right,cmp);
		for(int i=left;i<right&&num>0;i++,num--){
			printf("%s %d %d\n",B[i].name,B[i].age,B[i].w);
		}*/
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
