#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std; 
int main() {
	int n,min=300;
	scanf("%d%*c",&n);  //注意，后面要用getline这里要吃掉一个换行 
	string s[n],ans="";
	for(int i=0;i<n;i++){
		getline(cin,s[i]);
		reverse(s[i].begin(),s[i].end());
		if(s[i].size()<min)
			min=s[i].size();
	}
	bool flag=false;
	for(int i=0;i<min;i++){
		for(int j=0;j<n;j++){
			if(s[j][i]!=s[0][i]){
				flag=true;
				break;
			}
		}
		if(!flag)
			ans=ans+s[0][i];
		else break;
	}
	reverse(ans.begin(),ans.end());
	printf("%s\n",ans.size()?ans.c_str():"nai");
	return 0;
}
/*
3
Itai nyan~
Ninjin wa iyadanyan~
uhhh nyan~

3
Itai!
Ninjinnwaiyada T_T
T_T
*/
