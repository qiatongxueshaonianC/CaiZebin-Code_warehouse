#include<bits/stdc++.h>
using namespace std; 
int N;
int main() {
	scanf("%d",&N);
	vector<int> A(N+1),dp_increase(N+1,1),dp_decrease(N+1,1);
	for(int i=1;i<=N;i++)
		scanf("%d",&A[i]);
	for(int i=2;i<=N;i++){
		for(int j=1;j<i;j++){
			if(A[j]<A[i])
				dp_increase[i]=max(dp_increase[j]+1,dp_increase[i]);
		}
	}
	for(int i=N-1;i>=1;i--){
		for(int j=N;j>i;j--){
			if(A[j]<A[i])
				dp_decrease[i]=max(dp_decrease[j]+1,dp_decrease[i]);
		}
	}
	pair<int,int> ans={1,INT_MAX};
	int k=1;
	for(int i=1;i<=N;i++){
		if(dp_increase[i]==1||dp_decrease[i]==1) continue;
		int temp=abs(dp_increase[i]-dp_decrease[i]);
		if(dp_increase[i]+dp_decrease[i]-1>ans.first){
			ans.first=dp_increase[i]+dp_decrease[i]-1;
			k=i;
			ans.second=temp;
		}else if(dp_increase[i]+dp_decrease[i]-1==ans.first&&ans.second>temp){
			ans.second=temp;
			k=i;
		}
	}
	if(dp_increase[k]<=1)
		puts("No peak shape");
	else
		printf("%d %d %d",ans.first,k,A[k]);
	return 0;
}
/*
20
1 3 0 8 5 -2 29 20 20 4 10 4 7 25 18 6 17 16 2 -1

5
-1 3 8 10 20
*/
