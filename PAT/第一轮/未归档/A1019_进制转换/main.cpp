#include<bits/stdc++.h>
using namespace std; 
void change(int a,int b,vector<int> &ans){
	while(a>=b){
		ans.push_back(a%b);
		a=a/b;
	}
	ans.push_back(a);
}
int main() {
	int a,b;
	scanf("%d%d",&a,&b);
	vector<int> ans,rev;
	change(a,b,ans);
	rev=ans;
	reverse(ans.begin(),ans.end());
	printf("%s\n",rev==ans?"Yes":"No");
	for(auto i=ans.begin();i!=ans.end();i++)
		printf("%d%s",*i,i==--ans.end()?"\n":" ");
	return 0;
}
/*
27 2

100000000 2

121 5
*/
