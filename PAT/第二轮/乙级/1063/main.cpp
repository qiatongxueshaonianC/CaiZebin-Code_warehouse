#include<bits/stdc++.h>
using namespace std;
int main() {
	int N;
	double a,b,Max=0;
	scanf("%d",&N);
	while(N--){
		scanf("%lf%lf",&a,&b);
		Max=max(Max,sqrt(a*a+b*b));
	} 
	printf("%.2lf",round(Max*100)/100);
	return 0;
}
/*
5
0 1
2 0
-1 0
3 3
0 -3
*/
