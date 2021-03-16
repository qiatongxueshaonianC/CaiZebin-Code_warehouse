#include<bits/stdc++.h>
using namespace std; 
int main() {
	int n;
	char c;
	scanf("%d %c",&n,&c);
	string s(n,c),str(n,c),s1(n-2,' ');
	str.replace(1,n-2,s1);
	puts(s.c_str());
	n=round(1.0*n/2);
	for(int i=0;i<n-2;i++)
		puts(str.c_str());
	puts(s.c_str());
	return 0;
}
/*
10 *
*/
