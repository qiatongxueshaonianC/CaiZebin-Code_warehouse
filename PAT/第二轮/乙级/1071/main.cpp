#include<bits/stdc++.h>
using namespace std; 
int main() {
	int money,n,t1,t2,f,val;
	scanf("%d%d",&money,&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&t1,&f,&val,&t2);
		if(money<val){
			printf("Not enough tokens.  Total = %d.\n",money);
			continue;
		}
		if(t2>t1&&f==1||t2<t1&&f==0){
			money+=val;
			printf("Win %d!  Total = %d.\n",val,money);
		}else{
			money-=val;
			printf("Lose %d.  Total = %d.\n",val,money);
		}
		if(money==0){
			puts("Game Over.");
			break;
		}
	}
	return 0;
}
/*
100 4
8 0 100 2
3 1 50 1
5 1 200 6
7 0 200 8

100 4
8 0 100 2
3 1 200 1
5 1 200 6
7 0 200 8
*/
