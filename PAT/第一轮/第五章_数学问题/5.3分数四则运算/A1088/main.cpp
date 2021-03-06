#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
struct Node{
	ll up,down;
	Node():up(0),down(-1){}
}ans,u,v;
Node deduction(Node &a){
	if(a.down==0) return a;  //此时为无穷大 
	if(a.down<0){
		a.up=-a.up;
		a.down=-a.down;
	}
	if(a.up==0)
		a.down=1;
	else{
		int d=__gcd(a.up,a.down);
		a.up/=abs(d);
		a.down/=abs(d);
	}
	return a;
}
Node add(Node a,Node b){
	Node temp;
	temp.up=a.up*b.down+a.down*b.up;
	temp.down=a.down*b.down;
	return deduction(temp);
}
Node minu(Node a,Node b){
	Node temp;
	temp.up=a.up*b.down-a.down*b.up;
	temp.down=a.down*b.down;
	return deduction(temp);
}
Node mul(Node a,Node b){
	Node temp;
	temp.up=a.up*b.up;
	temp.down=a.down*b.down;
	return deduction(temp);
}
Node div(Node a,Node b){
	Node temp;
	temp.up=a.up*b.down;
	temp.down=a.down*b.up;
	return deduction(temp); 
}
void output(Node a){
	deduction(a);   //a加了引用&了 
	if(a.down==0){
		printf("Inf");
		return;
	}
	if(a.up<0) printf("(");
    if(a.down==1)   //包含了0和整数两种情况 
		printf("%d",a.up); 
	else if(abs(a.up)>a.down)
		printf("%d %d/%d",a.up/a.down,abs(a.up)%a.down,a.down);
	else printf("%d/%d",a.up,a.down);
	if(a.up<0) printf(")"); 
}
int main() {
	scanf("%lld/%lld %lld/%lld",&u.up,&u.down,&v.up,&v.down);
	ans=add(u,v); 
	output(u);cout<<" + ";output(v);cout<<" = ";output(ans);cout<<endl;
	ans=minu(u,v); 
	output(u);cout<<" - ";output(v);cout<<" = ";output(ans);cout<<endl;
	ans=mul(u,v); 
	output(u);cout<<" * ";output(v);cout<<" = ";output(ans);cout<<endl;
	ans=div(u,v); 
	output(u);cout<<" / ";output(v);cout<<" = ";output(ans);cout<<endl;
	return 0;
}
/*
2/3 -4/2
*/
