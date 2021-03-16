#include<bits/stdc++.h>
using namespace std;
int main() {
	string s="2  3  4  1  5  x  7  6  8";
	stringstream S(s);
	while(!S.eof()){
		S>>s;
		puts(s.c_str());
	/*	if(!S.eof())
			puts("YES");
		else
			puts("NO");*/
	}
	return 0;
}
