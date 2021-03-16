#include<bits/stdc++.h>
using namespace std; 
string deal(string s){
	int k=s.find('E');
	char c=s[k+1];
	int num=stoi(s.substr(k+2));
	s.erase(k);
	s.erase(2,1);  //删点
//	puts(s.c_str());
	if(c=='+'){			//注意这里没判断当 num-(k-2-1)<0会抛出“运行时错误” 
		if(num-(k-2-1)>=0) s.insert(s.end(),num-(k-2-1),'0');
		else s.insert(2+num,".");   // 处理这种特殊情况+1.23400E+01
	}else{
		s.insert(1,num,'0');
		s.insert(2,".");		
	}
	if(s[0]=='+')
		s.erase(s.begin());
	return s;
}
int main() {
	string s;
	getline(cin,s);
	s=deal(s);
	puts(s.c_str());
	return 0;
}
/*
+1.23400E-03

+1.23400E+01

-1.23400E+01

-1.2E+10

-1.00E-00
*/
