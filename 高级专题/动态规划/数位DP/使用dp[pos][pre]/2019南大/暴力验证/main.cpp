#include<bits/stdc++.h>
using namespace std;
bool judge(string s){
	char pre=s[0];
	for(int i=1;i<s.size();i++){
		if(abs(s[i]-pre)!=1)
			return false;
		pre=s[i];
	}
	return true;
}
int Solve(int k){
	int ans=0; 
	string s;
	for(int i=10;i<=k;i++){
		s=to_string(i);
		if(judge(s))
			ans++;
	}
	return ans;
} 
int main(){
    int m,n;
    while(scanf("%d%d",&m,&n)==2&&n>=m){
    	printf("%d\n",Solve(n)-Solve(m-1));  //注意，这里是m-1 
	}
    return 0;
}
