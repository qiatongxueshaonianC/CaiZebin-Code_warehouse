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
	bign temp;
	temp.len=strlen(a);
	int index=0;
	for(int i=temp.len-1;i>=0;i--)
		temp.d[index++]=a[i]-'0';
	return temp;
}
bign add(bign a,bign b){
	bign temp;
	int c=0;
	for(int i=0;i<a.len||i<b.len;i++){
		temp.d[temp.len++]=(a.d[i]+b.d[i]+c)%10;   //d全部都初始化为0了 
		c=(a.d[i]+b.d[i]+c)/10;
	}
	if(c!=0)
		temp.d[temp.len++]=c; 
	return temp;
}
int main() {
	char a[1000],b[1000];
	scanf("%s%s",&a,&b);
	bign u=change(a);
	bign v=change(b);
	u=add(u,v);
	printf("%s+%s=",a,b);
	for(int i=u.len-1;i>=0;i--)
		printf("%d",u.d[i]);
	return 0;
}
/*
123456789123456789
123456789123456789
*/
