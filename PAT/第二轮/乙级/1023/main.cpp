#include<bits/stdc++.h>
using namespace std; 
int main() {
	string ans="";
	int a;
	for(int i=0;i<10;i++){
		scanf("%d",&a);
		string s(a,i+'0');
		ans+=s;
	}
	sort(ans.begin(),ans.end());
	int k=ans.find_first_not_of('0');
	ans=ans[k]+ans;
	ans.erase(k+1,1);
	puts(ans.c_str());
	return 0;
}
/*
2 2 0 0 0 3 0 0 1 0
*/
