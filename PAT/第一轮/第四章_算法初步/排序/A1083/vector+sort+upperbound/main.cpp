#include<bits/stdc++.h>
using namespace std; 
struct Node{
	char name[11],id[11];
	int score;
	bool friend operator <(Node a,Node b){
		return a.score<b.score;
	}
};
vector<Node> A;
int lower_bound(int low,int high,int v){
	int mid;
	while(low<high){
		mid=(low+high)/2;
		if(v<=A[mid].score)
			high=mid;
		else low=mid+1;
	}
	return low;
}
int upper_bound(int low,int high,int v){
	int mid;
	while(low<high){
		mid=(low+high)/2;
		if(v<A[mid].score)
			high=mid;
		else low=mid+1;
	}
	return low;
}
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
	int left=lower_bound(0,A.size(),low);   //注意，默认用的是从小到大的排序 
	int right=upper_bound(0,A.size(),high); 
	for(int i=right-1;i>=left;i--)
		printf("%s %s\n",A[i].name,A[i].id);
	if(right-left<=0)
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
