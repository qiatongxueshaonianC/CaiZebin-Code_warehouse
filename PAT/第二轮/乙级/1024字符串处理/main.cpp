#include<bits/stdc++.h>
using namespace std; 
int main() {
	string s;
	getline(cin,s);
	if(s[0]=='-'||s[0]=='+'){
		printf("%s",s[0]=='-'?"-":"");
		s.erase(s.begin());
	}
	int k=s.find('E');
	int e=abs(stoi(s.substr(k+1)));
	if(s[k+1]=='-'){
		string s1(e,'0');
		s=s1+s;
		s.erase(s.begin()+s.find('.'));
		s.insert(1,".");
		s.erase(s.begin()+s.find('E'),s.end());
	}else{
		if(k-2<=e){  //2020/1/20/13:35发现，改正，这里要取等 
			string s1(e-(k-2),'0');
			s.erase(s.begin()+k,s.end());
			s+=s1;
			s.erase(1,1);
		}else{
			s.insert(1+e+1,".");
			s.erase(1,1);
			s.erase(s.begin()+s.find('E'),s.end());
		}
	}
	puts(s.c_str());
	return 0;
}
/*
+1.23400E5

+1.23400E-03

-1.2E+10
*/
