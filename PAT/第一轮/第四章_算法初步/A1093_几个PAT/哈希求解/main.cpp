#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
string s1;
int num[maxn][2];
long long ans;
int main() {
	cin>>s1;
	transform(s1.begin(),s1.end(),s1.begin(),::toupper);
	for(int i=0;i<s1.size();i++){
		if(s1[i]=='P') i==0?num[i][0]=1:num[i][0]=num[i-1][0]+1;
		else num[i][0]=num[i-1][0]; 
	}
	for(int i=s1.size()-1;i>=0;i--){
		if(s1[i]=='T') i==s1.size()-1?num[i][1]=1:num[i][1]=num[i+1][1]+1;
		else num[i][1]=num[i+1][1];
	}
	for(int i=0;i<s1.size();i++){
		if(s1[i]=='A') ans+=num[i][0]*num[i][1];
	}
	printf("%d\n",ans%1000000007);
	return 0;
}
/*
APPAPT
*/
