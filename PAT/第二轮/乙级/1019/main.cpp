#include<bits/stdc++.h>
using namespace std;
int main() {
	string s1,s2;
	cin>>s1;
	if(s1.size()<4){
		string s(4-s1.size(),'0');
		s1=s+s1;
	}
	sort(s1.begin(),s1.end());
	s2=s1;
	reverse(s1.begin(),s1.end());
	int a=stoi(s1),b=stoi(s2),c;
	if(a==b)
		printf("%04d - %04d = 0000",a,b);
	else{
		c=a-b;
		while(c!=6174){
			printf("%04d - %04d = %04d\n",a,b,c);
			s1=to_string(c);
			while(s1.size()<4)
				s1='0'+s1;
			sort(s1.begin(),s1.end());
			s2=s1;
			reverse(s1.begin(),s1.end());
			a=stoi(s1);b=stoi(s2);
			c=a-b;
		}
		printf("%04d - %04d = %04d",a,b,c);
	}
}
/*
6767

2222
*/
