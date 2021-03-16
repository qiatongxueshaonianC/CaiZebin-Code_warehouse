#include<bits/stdc++.h>
using namespace std; 
struct bign{
	int len,d[1000];
	bign(){
		len=0;
		memset(d,0,sizeof(d));
	}
};
void deduction(bign &c){
	while(c.len>1&&(c.d[c.len-1]==0||c.d[c.len-1]=='-'-0))
		c.len--;
}
bign change(char a[]){
	bign c;
	c.len=strlen(a);
	int index=0;
	for(int i=c.len-1;i>=0;i--)
		c.d[index++]=a[i]-'0';
	deduction(c);
	return c;
}
bign add(bign a,bign b){
	bign c;
	int carry=0;
	for(int i=0;i<a.len||i<b.len;i++){
		int temp=a.d[i]+b.d[i]+carry;
		c.d[c.len++]=temp%10;
		carry=temp/10;
	}
	if(carry!=0)
		c.d[c.len++]=carry;
	return c;
}
bign sub(bign a,bign b){
	bign c;
	for(int i=0;i<a.len||i<b.len;i++){
		if(a.d[i]<b.d[i]){
			a.d[i+1]--;
			a.d[i]+=10;
		}
		c.d[c.len++]=a.d[i]-b.d[i];
	}
	while(c.len>1&&c.d[c.len-1]==0)
		c.len--;
	return c;
}
bool cmp(bign a,bign b){
	if(a.len>b.len) return true;
	else if(a.len<b.len) return false;
	for(int i=a.len-1;i>=0;i--){
		if(a.d[i]>b.d[i]) return true;
		else if(a.d[i]<b.d[i]) return false;
	}
	return false;  //相等也返回false 
}
bign cal(char a[],char b[]){
	bign ad;
		if((a[0]=='-'&&b[0]!='-')||(a[0]!='-'&&b[0]=='-')){  //一正一负，做减法 
			char temp_a=a[0],temp_b=b[0];  //判断符号用 
			a[0]=a[0]=='-'?'0':a[0];
			b[0]=b[0]=='-'?'0':b[0];
			bign u=change(a);
			bign v=change(b);
			if(cmp(u,v)){
				ad=sub(u,v);
				if(temp_a=='-')
					ad.d[ad.len++]='-';
			}else {
				ad=sub(v,u);
				if(temp_b=='-')
					ad.d[ad.len++]='-';
			}
		}else{  //同号，做加法； 
			char temp_a=a[0],temp_b=b[0];
			a[0]=a[0]=='-'?'0':a[0];
			b[0]=b[0]=='-'?'0':b[0];
			bign u=change(a);
			bign v=change(b);
			ad=add(u,v);
			if(temp_a=='-')
				ad.d[ad.len++]='-';
		}
	return ad; 
}
int main() {
	int n;
	scanf("%d",&n);
	char a[1000],b[1000],c[1000];//ad[1000];
	for(int i=1;i<=n;i++){
		scanf("%s%s%s",&a,&b,&c);
		bign ad=cal(a,b);
		bool flag=false;
		char temp_c=c[0];
		c[0]=c[0]=='-'?'0':c[0];
		bign w=change(c);
		if(ad.d[ad.len-1]!='-'&&temp_c=='-') 
			flag=true;
		else if(ad.d[ad.len-1]=='-'&&temp_c!='-') 
			flag=false;
		else if(ad.d[ad.len-1]=='-'&&temp_c=='-'){  //都是负数 
			deduction(ad);
			deduction(w);
			if(cmp(w,ad))   //c-(a+b) 2019/11/24/20:18发现并改正，当都是负数时用 c-(a+b)
				flag=true;
			else flag=false;
		} else{  //都是正数 
			if(cmp(ad,w))
				flag=true;
			else flag=false;
		}
		printf("Case #%d: %s\n",i,flag?"true":"false");
	}
	return 0;
}
/*
4
123698745547896321123698745547896321 -123698745547896321123698745547896321 0
123698745547896321123698745547896321 -123698745547896321123698745547896320 0
123698745547896321123698745547896321 -123698745547896321123698745547896321 -1 
-5 -6 -11 

3
1 2 3
2 3 4
9223372036854775807 -9223372036854775808 0
*/
