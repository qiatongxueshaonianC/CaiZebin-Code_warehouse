#include<bits/stdc++.h>
using namespace std; 
set<int,greater<int>> st,ans; 
void cal(int a){
	while(a!=1){
		a=a%2==0?a/2:(3*a+1)/2;
	//	ans.erase(ans.end());   ɾ���ĵ��������������һ��ans.end() 
		auto it=ans.find(a);
		if(it!=ans.end())
			ans.erase(it);
	}
}
int main() {
	int n,a; 
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		st.insert(a);
	}
	set_union(ans.begin(),ans.end(),st.begin(),st.end(),inserter(ans,ans.begin()));
	for(auto i:st)
		cal(i);
/*	for(auto i=ans.rbegin();i!=ans.rend();i++)
		printf("%d%s",*i,i==--ans.rend()?"":" ");*/
	for(auto i:ans)
		printf("%d%s",i,i==*(--ans.end())?"":" ");
	return 0;
}
/*
6
3 5 6 7 8 11
*/
