#include<bits/stdc++.h>
using namespace std;
int main() {
	int N,n,first,last;
	char c;
	scanf("%d %c",&N,&c);
	n=(int)sqrt(1.0*(N+1)/2);
	string s(2*n-1,c);
	vector<string> A;
	for(int i=0;i<n;i++){
		puts(s.c_str());
		first=s.find_first_of(c);
		last=s.find_last_of(c);
		if(first==last)
			break;
		A.push_back(s);
		s[first]=' ';
		s.erase(last);
	} 
	for(int i=A.size()-1;i>=0;i--)
		puts(A[i].c_str());
	printf("%d",N-(2*n*n-1));
}
/*
19 *
*/
