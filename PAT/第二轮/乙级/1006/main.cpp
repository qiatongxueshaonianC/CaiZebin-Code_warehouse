#include<bits/stdc++.h>
using namespace std; 
map<int,char> mp={{2,'B'},{1,'S'}};
void print(int i,int j){
	if(j!=0){
		for(int k=0;k<i;k++)
			printf("%c",mp[j]);
	}else{
		for(int k=1;k<=i;k++)
			printf("%d",k);
	}
}
int main() {
	string s;
	cin>>s; 
	reverse(s.begin(),s.end());
	for(int i=s.size()-1;i>=0;i--)
		print(s[i]-'0',i);
	return 0;
}
/*
234

23
*/
