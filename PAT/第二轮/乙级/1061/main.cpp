#include<bits/stdc++.h>
using namespace std; 
int main() {
	int N,M;
	scanf("%d%d",&N,&M);
	vector<int> score(M),ans(M);
	for(int i=0;i<M;i++)
		scanf("%d",&score[i]);
	for(int i=0;i<M;i++)
		scanf("%d",&ans[i]);
	while(N--){
		int grade=0,a;
		for(int i=0;i<M;i++){
			scanf("%d",&a);
			grade+=a==ans[i]?score[i]:0;
		}
		printf("%d\n",grade);	
	}
	return 0;
}
/*
3 6
2 1 3 3 4 5
0 0 1 0 1 1
0 1 1 0 0 1
1 0 1 0 1 0
1 1 0 0 1 1
*/
