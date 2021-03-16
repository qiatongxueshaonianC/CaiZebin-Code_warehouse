#include<iostream>
#include<cstdio> 
#include<vector>
#include<ctime>
using namespace std;
typedef long long LL;
const int maxn=1e5+10;
int A[maxn],B[maxn],N;
vector<int> temp,ans;
LL bst;
LL F(int idx){
	LL temp=0;
	if(idx>0)
		temp+=(B[idx]-B[idx-1])*(B[idx]-B[idx-1]);
	temp+=abs(A[idx]-B[idx]);
	return temp;
}
void DFS(int idx,LL sum){
	if(sum>=bst)
		return;
	if(idx==N){
		if(sum<bst){
			ans=temp;
			bst=sum;
		}
		return;
	}
	for(int i=0;i<=9;i++){
		B[idx]=i;
		temp.push_back(i);
		DFS(idx+1,sum+F(idx));
		temp.pop_back();
	}
}
int main() {
	clock_t start,finish;
	scanf("%d",&N);
	start=clock();
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
		if(i>0)
			bst+=(A[i]-A[i-1])*(A[i]-A[i-1]);	
	}
	DFS(0,0);
	for(auto i:ans)
		printf("%d ",i);
	printf("\n%d\n",bst);
	finish=clock();
	cout<<finish-start<<"/"<<CLOCKS_PER_SEC<<"(s)"<<endl;
	cout<<(double)(finish-start)/CLOCKS_PER_SEC<<"(s)"<<endl;
	return 0;
}
/*
6
1 4 2 8 5 7
*/
