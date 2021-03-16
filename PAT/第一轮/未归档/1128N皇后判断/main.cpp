#include<bits/stdc++.h>
using namespace std; 
bool judge(vector<int> a){
	for(int i=1;i<a.size()-1;i++){
		for(int j=i+1;j<a.size();j++){
			if(abs(j-i)==abs(a[j]-a[i])||a[j]==a[i])  //2019/11/30/13:14改正，还要判断是否会在同一行 
				return false;
		}
	}
	return true;
}
int main() {
	int k,n;
	scanf("%d",&k);
	while(k--){
		scanf("%d",&n);
		vector<int> A(n+1);
		for(int i=1;i<=n;i++)
			scanf("%d",&A[i]);
		if(judge(A)) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
4
8 4 6 8 2 7 1 3 5
9 4 6 7 2 8 1 9 5 3
6 1 5 2 6 4 3
5 1 3 5 2 4
*/
