#include<bits/stdc++.h>
using namespace std;
string s1,s2; 
vector<pair<regex,string>>trans;
bool harsh[256];
int main() {
	getline(cin,s1);
	getline(cin,s2);    //2019年10月20日21：52发现错误，并改正 
//	cin>>s2;
	for(auto i:s2){
		int j=0; 
		if(harsh[i]==false){
			int k=s1.find(i,j);
			while(k!=string::npos){
				string temp=s1.substr(k+1,s1.size()-k-1);
				s1.erase(k,s1.size()-k);
				s1+=temp;
				j=k;  //不是k+1 
				k=s1.find(i,j);
			}
			harsh[i]=true;
		}
	}
	puts(s1.c_str());
	return 0;
}
/*
Theey aare students.
aeiou

Theey aare students.
aeiou c
*/
