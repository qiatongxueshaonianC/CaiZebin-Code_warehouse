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
	for(int i=1;i<=len2;i++){	//连续序列 
		int point_left=i,length_of_common_subsequences=0;
		for(int j=1;j<=len1;j++){	//j指针就是作为子序列的指针（子序列） 
   			if(s2[point_left]==s1[j]){
   				point_left++;
   				length_of_common_subsequences++;
   			}
   		}
   		m=max(m,length_of_common_subsequences);
	}
	printf("%d\n",len1-m);
}

/*
iononmrogdg
goodmorning		//枚举该序列从i位开始的最长公共序列长度 
*/
