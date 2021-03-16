#include<bits/stdc++.h>
using namespace std;
int cmp(int y,int m,int d,int yy,int mm,int dd){
	if(y!=yy) return y>yy?1:-1;
	if(m!=mm) return m>mm?1:-1;
	if(d!=dd) return d>dd?1:-1;
	return 0;
}
int main() {
	int n,y,m,d,valid=0;
	scanf("%d",&n);
	pair<int,pair<int,int>> old={2014,{9,6}},young=make_pair(1814,make_pair(9,6));
	char a[10],od[10],yo[10];
	for(int i=0;i<n;i++){
		scanf("%s%d/%d/%d",&a,&y,&m,&d);
		if(cmp(y,m,d,2014,9,6)==1||cmp(y,m,d,1814,9,6)==-1)
			continue;
		if(cmp(y,m,d,old.first,old.second.first,old.second.second)!=1){
			strcpy(od,a);
			old.first=y;
			old.second.first=m;
			old.second.second=d;
		}
		if(cmp(y,m,d,young.first,young.second.first,young.second.second)!=-1){
			strcpy(yo,a);
			young.first=y;
			young.second.first=m;
			young.second.second=d;
		}
		valid++;	
	} 
	printf("%d",valid);
	if(valid>0)
		printf(" %s %s",od,yo);
}
/*
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20
*/
