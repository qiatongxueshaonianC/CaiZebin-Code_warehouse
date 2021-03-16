#include<bits/stdc++.h>
using namespace std;
struct bign{
	int len,d[1000];
	bign(){
		len=0;
		memset(d,sizeof(d),0);
	}
}; 
bign change(string s){
	bign c;
	for(auto it=s.rbegin();it!=s.rend();++it)
		c.d[c.len++]=(*it-'0');
	return c;
}
bign div(bign u,int v,int& r){
	bign c;
	c.len=u.len;
	for(int i=u.len-1;i>=0;i--){
		r=r*10+u.d[i];
		if(r<v)
			c.d[i]=0;
		else{
			c.d[i]=r/v;
			r=r%v;
		}
	}
	while(c.len>1&&c.d[c.len-1]==0)
		c.len--;
	return c;
}
int main() {
	string s;
	int v,r=0;
	cin>>s>>v;
	bign u=change(s);
	u=div(u,v,r);
	for(int i=u.len-1;i>=0;i--)
		printf("%d",u.d[i]);
	printf(" %d",r);
}
/*
123456789050987654321 7
*/
