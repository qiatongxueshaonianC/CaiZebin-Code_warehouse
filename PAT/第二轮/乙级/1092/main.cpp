#include<bits/stdc++.h>
using namespace std; 
int main() {
	int N,M,sel[1010]={0};
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int M[2]={0},u;
		for(int j=1;j<=N;j++){
			scanf("%d",&u);
			sel[j]+=u;
		}
	}
	int Max=max_element(sel+1,sel+1010)-sel;
	printf("%d\n",sel[Max]);
	for(int i=1;i<=N;i++)
		if(sel[i]==sel[Max]) printf("%s%d",i==Max?"":" ",i);
	return 0;
}
/*
5 3
1001 992 0 233 6
8 0 2018 0 2008
36 18 0 1024 4

5 3
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0 
*/
