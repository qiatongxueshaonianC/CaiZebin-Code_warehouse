#include<bits/stdc++.h>
using namespace std; 
map<char,string> mp={{'A',"MON"},{'B',"TUE"},{'C',"WED"},{'D',"THU"},
{'E',"FRI"},{'F',"SAT"},{'G',"SUN"}};  
string s1,s2,s3,s4; 
int main() {
	cin>>s1>>s2>>s3>>s4;
	int flag=0;
	for(int i=0;i<s1.size()&&i<s2.size();i++){  //isdigit()??????Сд?? 
		if(s1[i]==s2[i]){
			if(flag==1){
				if(isdigit(s1[i])){
					printf(" %02d:",s1[i]-'0');
					break;
				}
				if('A'<=s1[i]&&s1[i]<='N'){
					printf(" %02d:",s1[i]-'A'+10);
					break;
				}
			}else if(mp.find(s1[i])!=mp.end()){
				cout<<mp[s1[i]];
				flag++;	
			}
		}
	}
	for(int i=0;i<s3.size()&&i<s4.size();i++){
		if(s3[i]==s4[i]&&isalpha(s3[i])){
			printf("%02d",i);
			break;
		}
	}
	return 0;
}
/*
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
*/ 
