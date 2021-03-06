#include<bits/stdc++.h>
using namespace std; 
struct bign{
	int len,d[1000];
	bign(){
		len=0;
		memset(d,0,sizeof(d));
	}
};
bign change(char a[]){
	bign c;
	c.len=strlen(a);
	int index=0;
	for(int i=c.len-1;i>=0;i--)
		c.d[index++]=a[i]-'0';  //注意，这里一定要减去‘0’
	return c; 
}
bign mul(bign a,int b){
	bign c;
	int carry=0;
	for(int i=0;i<a.len;i++){
		int temp=a.d[i]*b+carry;
		c.d[c.len++]=temp%10;
		carry=temp/10;
	}
	while(carry!=0){
		c.d[c.len++]=carry%10;
		carry/=10;
	}
	while(c.len-1>=1&&c.d[c.len-1]==0)  //2019/11/22/01:03改正，注意这里是c.len-1>=1 
		c.len--;
	return c;
}
int main() {
	char a[1000];
	int b; 
	scanf("%s%d",&a,&b);
	if(a[0]=='-'||b<0){  //特殊情况处理 
		if(b>0||a[0]!='-') printf("-");
		a[0]=a[0]=='-'?'0':a[0];
		b=abs(b);
	}
	bign u=change(a);
	u=mul(u,b);
	for(int i=u.len-1;i>=0;i--)
		printf("%d",u.d[i]);
	return 0;
}
/*
-0001234
0011234

10000000000000000000000000 1
*/
