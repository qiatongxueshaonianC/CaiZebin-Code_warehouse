#include<bits/stdc++.h>
using namespace std; 
int main() {
	int n;
	scanf("%d",&n);
	while(n--){
		string s,x,y;
		cin>>s;
		int k=stoi(s);
		int u=stoi(s.substr(0,s.size()/2));
		int v=stoi(s.substr(s.size()/2));
		if(u*v==0) 
			puts("No");
		else
			printf("%s\n",k%(u*v)==0?"Yes":"No");
	}
	return 0;
}
/*
3
167334
2333
12345678
*/
