#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
struct Fraction{
	ll up,down;
};
void reduction(Fraction& u){
	if(u.down<0){
		u.down=-u.down;
		u.up=-u.up;
	}
	if(u.up==0)
		u.down=1;
	else{
		int temp=__gcd(abs(u.up),abs(u.down));
		u.down/=temp;
		u.up/=temp;
	}
}
Fraction add(Fraction u,Fraction v){
	Fraction ans;
	ans.down=u.down*v.down;
	ans.up=u.up*v.down+v.up*u.down;
	reduction(ans);
	return ans;
}
Fraction sub(Fraction u,Fraction v){
	Fraction ans;
	ans.down=u.down*v.down;
	ans.up=u.up*v.down-v.up*u.down;
	reduction(ans);
	return ans;
}
Fraction multi(Fraction u,Fraction v){
	Fraction ans;
	ans.up=u.up*v.up;
	ans.down=u.down*v.down;
	reduction(ans);
	return ans;
}
Fraction divide(Fraction u,Fraction v){
	Fraction ans;
	if(v.up==0){
		ans.down=ans.up=0;
		return ans;
	}
	ans.down=u.down*v.up;
	ans.up=u.up*v.down;	
	reduction(ans);
	return ans;
}
void output(Fraction u){
	if(u.up==u.down)
		printf("Inf");
	else{
		bool f=false;
		if(u.up<0){
			printf("(");
			f=true;
		}
		if(u.down==1)
			printf("%d",u.up);
		else if(abs(u.up)>u.down)
			printf("%d %d/%d",u.up/u.down,abs(u.up)%u.down,u.down);
		else
			printf("%d/%d",u.up%u.down,u.down);
		printf("%s",f?")":"");
	}
}
int main() {
	Fraction u,v;
	scanf("%lld/%lld %lld/%lld",&u.up,&u.down,&v.up,&v.down);
	reduction(u);
	reduction(v);
	output(u);printf(" + ");output(v);printf(" = ");output(add(u,v));puts("");
	output(u);printf(" - ");output(v);printf(" = ");output(sub(u,v));puts("");
	output(u);printf(" * ");output(v);printf(" = ");output(multi(u,v));puts("");
	output(u);printf(" / ");output(v);printf(" = ");output(divide(u,v));puts("");
	return 0;
}
/*
2/3 -4/2

2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)


5/3 0/6

1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
*/
