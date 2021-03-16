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
bign div(bign a,int b,int &r){
	bign c;
	c.len=a.len;    //被除数的每一位和商的每一位是一一对应的 
	for(int i=a.len-1;i>=0;i--){  //从高位开始 
		r=r*10+a.d[i];
	 	if(r<b) c.d[i]==0;
		else{
			c.d[i]=r/b;
			r=r%b;
		}
	}
	while(c.len-1>=1&&c.d[c.len-1]==0)
		c.len--;
	return c;
}
int main() {
	char a[1000];
	int b,r; 
	scanf("%s%d",&a,&b);
	if(a[0]=='-'||b<0){  //特殊情况处理 
		if(b>0||a[0]!='-') printf("-");
		a[0]=a[0]=='-'?'0':a[0];
		b=abs(b);
	}
	bign u=change(a);
	u=div(u,b,r);
	for(int i=u.len-1;i>=0;i--)
		printf("%d",u.d[i]);
	printf(" %d\n",r);
	return 0;
}
/*
-0011234
001234

10000000000000000000000000 1
*/
