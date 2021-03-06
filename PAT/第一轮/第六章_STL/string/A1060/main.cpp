#include<bits/stdc++.h>
using namespace std;
int N;
int deal(string &s){
	string temp="";
	int point=s.find('.');
	if(point==string::npos) 
		point=s.size();
	int index=s.find_first_of("123456789");
/*	if(index==string::npos){  //特殊情况处理 
		while(temp.size()<N)
			temp+='0';
		s=temp;
		return 0;
	}	*/ 
	for(int i=index;i<s.size()&&temp.size()<N;i++)  //index可以看作是-1，也可以是unsigned_int的最大值 
		if(s[i]!='.') 								//即4294967295 
			temp+=s[i];
	while(temp.size()<N)
		temp+='0';
	point=point-index;
	s=temp;
	if(index==string::npos)
		return 0; 
	return point>0?point:point+1;  //2019/11/18/19：23发现，注意这里是加一不是减一 
}
int main() {
	string s1,s2;
	cin>>N>>s1>>s2;
	int e1=deal(s1);
	int e2=deal(s2);
	if(e1==e2&&s1==s2)
		cout<<"YES 0."<<s1<<'*'<<"10^"<<e1<<endl;
	else
		cout<<"NO 0."<<s1<<'*'<<"10^"<<e1<<" 0."<<s2<<'*'<<"10^"<<e2<<endl;
	return 0;
}
/*
3 12300 12358.9

3 120 128

4 0000 0000.00

4 00000.000000123 0.0000001230
*/
