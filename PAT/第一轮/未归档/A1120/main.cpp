#include<bits/stdc++.h>
using namespace std; 
int n;
set<int> st;
int cal(string s){
	int num=0;
	for(char i:s)
		num+=i-'0';
	return num;
}
int main() {
	scanf("%d",&n);
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		st.insert(cal(s));
	}
	printf("%d\n",st.size());
	for(auto i:st)
		printf("%d%s",i,i!=*(--st.end())?" ":"");
	return 0;
}
/*
8
123 899 51 998 27 33 36 12
*/
