#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
char s1[maxn],s2[maxn];
int main(){
	scanf("%s%s",s1+1,s2+1);
//	puts(s1+1);puts(s2+1);
//	cin>>(s1+1)>>(s2+1);
	int len1=strlen(s1+1),len2=strlen(s2+1);
	int m=0;
	for(int i=1;i<=len2;i++){
		int point_left=i,point_right=0;
		for(int j=1;j<=len1;j++){
   			if(s2[point_left]==s1[j]){
   				point_left++;
   				point_right++;
   			}
   		}
   		m=max(m,point_right);
	}
	printf("%d\n",len1-m);
}

/*
iononmrogdg
goodmorning
*/
