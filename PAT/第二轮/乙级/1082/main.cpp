#include<bits/stdc++.h>
using namespace std; 
int main() {
	int N,id,x,y,loser,winner;
	double Min=INT_MAX,Max=0,temp;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d%d%d",&id,&x,&y);
		double temp=1.0*x*x+1.0*y*y;
		if(temp<Min){
			Min=temp;
			winner=id;
		}
		if(temp>Max){
			Max=temp;
			loser=id;
		}
	}
	printf("%04d %04d",winner,loser);
	return 0;
}
/*
3
0001 5 7
1020 -1 3
0233 0 -1
*/
