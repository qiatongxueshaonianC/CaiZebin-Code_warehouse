#include<bits/stdc++.h>
using namespace std; 
int main() {
	string s;
	cin>>s;
	int n1,n2,n3;
	n1=n2=(s.size()+2)/3;
	n3=s.size()-n1-n2;
	string space="";
	for(int i=0;i<n3;i++)
		space+=' ';
	for(int i=0;i<n1-1;i++){
		printf("%c%s%c\n",s[0],space.c_str(),*--s.end());
		s.erase(s.begin());s.erase(--s.end());
	}
	puts(s.c_str());
	return 0;
}
/*
helloworld!
*/
