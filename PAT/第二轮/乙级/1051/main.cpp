#include<bits/stdc++.h>
using namespace std; 
int main() {
	double R1,P1,R2,P2;
	scanf("%lf%lf%lf%lf",&R1,&P1,&R2,&P2);
	double a=R1*cos(P1)*R2*cos(P2)-R1*sin(P1)*R2*sin(P2);
	double b=R1*cos(P1)*R2*sin(P2)+R1*sin(P1)*R2*cos(P2);
	printf("%s%.2lf%s%.2lfi",(a>-0.005)||a>=0?"":"-",fabs(a),b>=0||b>-0.005?"+":"-",fabs(b));
//	printf("%.2lf%s%.2lfi",-0.0005,b>=0?"+":"-",fabs(b)); //2020/1/27/23:33???ִ??? 
	return 0;
}
/*
2.3 3.5 5.2 0.4

0.0001 -0.0001 0.0001 -0.0001
*/
