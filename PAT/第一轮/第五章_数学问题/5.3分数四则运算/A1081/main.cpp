#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
struct Node{
	ll up,down;
	Node():up(0),down(1){}
}sum,temp;
void reduction(Node &a){
	if(a.down<0){
		a.up=-a.up;
		a.down=-a.down;
	}
	if(a.up==0)
		a.down=1;
	else{
		int d=__gcd(a.up,a.down);
		a.up/=abs(d);   //2019/11/20/0:34改正  
		a.down/=abs(d);
	/*	a.up/=d;
		a.down/=d;
		*/ 
	}
}
Node add(Node a,Node b){
	Node temp;
	temp.up=a.up*b.down+a.down*b.up;
	temp.down=a.down*b.down;
	reduction(temp);
	return temp;
}
void output(Node a){
	reduction(a);
	if(a.down==1)   //此处包含了0和其他整数结果的情况 
		printf("%d\n",a.up); 
	else if(abs(a.up)>a.down)
		printf("%d %d/%d\n",a.up/a.down,abs(a.up)%a.down,a.down);  //2019/11/20/0:34改正 
	//	printf("%d %d/%d\n",a.up/a.down,a.up%a.down,a.down); 
	else printf("%d/%d\n",a.up,a.down);
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld/%lld",&temp.up,&temp.down);
		sum=add(sum,temp);
	}
	output(sum);
	return 0;
}
/*
5
2/5 4/15 1/30 -2/60 8/3

2
4/3 2/3

3
1/3 -1/6 1/8

1
-1/6
*/
