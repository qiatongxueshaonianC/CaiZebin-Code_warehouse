#include<bits/stdc++.h>
using namespace std; 
int main() {
	string s1,s2;
	getline(cin,s1);
	transform(s1.begin(),s1.end(),s1.begin(),::toupper);
	getline(cin,s2);
	transform(s2.begin(),s2.end(),s2.begin(),::toupper);
	bool harsh[256]={false};
	for(char i:s1){
		if(harsh[i]==false){  //若该字符还未输出过 
			for(char j:s2){
				if(j==i){
					harsh[i]=true;   //这个字符在输出中出现了 
					break;					
				}
			}
			if(harsh[i]==false){
				printf("%c",i);
				harsh[i]=true;				
			}
		}
	}
	return 0;
}
/*
7_This_is_a_test
_hs_s_a_es
*/
