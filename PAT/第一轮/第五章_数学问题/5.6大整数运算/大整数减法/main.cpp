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
bign sub(bign a,bign b){
	bign ans;
	for(int i=0;i<a.len||i<b.len;i++){
		if(a.d[i]<b.d[i]){
			a.d[i+1]--;
			a.d[i]+=10;
		}
		ans.d[ans.len++]=a.d[i]-b.d[i];
	}
	while(ans.len-1>=1&&ans.d[ans.len-1]==0)  //只调整len高位为0 
		ans.len--;
	return ans;
}
bool cmp(bign a,bign b){
	if(a.len<b.len) return false;
    if(a.len>b.len) return true;
	for(int i=0;i<a.len;i++)
		if(a.d[i]<b.d[i])
			return false;
	return true;
}
int main() {
	char a[1000],b[1000];
	scanf("%s%s",&a,&b);
	bign u=change(a);
	bign v=change(b);
	if(!cmp(u,v)){
		printf("-");
		swap(u,v);
	}
	u=sub(u,v);
	for(int i=u.len-1;i>=0;i--)
		printf("%d",u.d[i]);
	return 0;
}
/*
1234
11234

10000000000000000000000000 1
*/
