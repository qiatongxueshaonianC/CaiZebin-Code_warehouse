#include<bits/stdc++.h>
using namespace std; 
const int inf=0x3fffffff;
int main() {
	int n;
	scanf("%d",&n);
	int max_left[n]={0},min_right[n]={0},A[n];
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
		max_left[i]=i==0?0:max(max_left[i-1],A[i]);
	}
	min_right[n-1]=inf;
	for(int i=n-2;i>=0;i--)
		min_right[i]=min(A[i],min_right[i+1]);
	vector<int> ans;
	for(int i=0;i<n;i++){
		if(max_left[i]<=A[i]&&min_right[i]>=A[i])
			ans.push_back(A[i]);
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
		printf("%d%s",ans[i],i==ans.size()-1?"":" ");
	puts("");   //2019/11/27/21:45发现错误，没有元素时要输出一个空行 
	return 0;
}
/*
5
1 3 2 4 5
*/
