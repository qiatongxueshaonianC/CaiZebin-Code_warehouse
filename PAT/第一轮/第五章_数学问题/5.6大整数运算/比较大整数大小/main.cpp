#include<bits/stdc++.h>
using namespace std; 
struct bign{
	int len,d[1000];
	Node(){
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
bool cmp(bign a,bign b){
	if(a.len>b.len) return true;
	if(a.len<b.len) return false;
	for(int i=0;i<a.len;i++)
		if(a.d[i]>b.d[i])
			return true;
		else if(a.d[i]<b.d[i])
			return false;
	return true;
}
int main() {
	char a[1000],b[1000];
	scanf("%s%s",&a,&b);
	bign u=change(a);
	bign v=change(b);
	if(cmp(u,v)) printf("%s>%s",a,b);
	else printf("%s<%s",a,b);
	return 0;
}
