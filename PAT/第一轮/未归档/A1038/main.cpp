#include<bits/stdc++.h>
using namespace std; 
vector<string> A;
bool cmp(int a,int b){
	return A[a]+A[b]<A[b]+A[a]; 
}
int main() {
	int n;
	string s,ans="";
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>s;
		A.push_back(s);
	}
	int visit[n];
	iota(visit,visit+n,0);
	sort(visit,visit+n,cmp);  //对访问顺序排序 
	for(int i=0;i<n;i++)
		ans+=A[visit[i]];
//	while(ans.size()>1&&ans[0]=='0')	//去除前导0
	while(ans.size()>1&&ans[0]=='0')  //但是得至少有一个1  2019/11/22/14：47发现改正 
		ans.erase(ans.begin());
		//ans.erase(0,1);   //0代表的是在字符串中的位置 
	puts(ans.c_str());
	return 0;
}
/*
5 0 00 000 0000 00000 

5 32 321 3214 0229 87

6 32 3210 3211 3214 0229 087
*/ 
