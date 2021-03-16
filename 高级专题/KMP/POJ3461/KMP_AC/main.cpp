#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<climits>
#include<numeric>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<iterator>
using namespace std;
const int maxn=1e4+5;
int Next[maxn];
void getNext(char* s){
	int j=-1,len=strlen(s);
	Next[0]=-1;
	for(int i=1;i<len;i++){
		while(j!=-1&&s[i]!=s[j+1])
			j=Next[j];
		if(s[i]==s[j+1])
			j++;
		Next[i]=j;
	}
}
int KMP(char* s,char* p){
	getNext(p);
	int j=-1,ans=0,len=strlen(s),lenp=strlen(p);
	for(int i=0;i<len;i++){
		while(j!=-1&&s[i]!=p[j+1])
			j=Next[j];
		if(s[i]==p[j+1])
			j++;
		if(j==lenp-1){
			ans++;
			j=Next[j];
		}
	}
	return ans;
}
int main() {
	
 //   std::ios::sync_with_stdio(false);
	int T;
	char s[1000005],p[maxn];
//	cin>>T;
	scanf("%d",&T);
	while(T--){
	//	cin>>p>>s;
		scanf("%s%s",&p,&s);
		printf("%d\n",KMP(s,p));
	}
	return 0;
}
/*
3
BAPC
BAPC
AZA
AZAZAZA
VERDI
AVERDXIVYERDIAN
*/
