#include<bits/stdc++.h>
using namespace std; 
map<char,string> mp={{'A',"MON"},{'B',"TUE"},{'C',"WED"},{'D',"THU"},
{'E',"FRI"},{'F',"SAT"},{'G',"SUN"}};
unordered_map<char,int> harsh;
void init(){
	int index=10;
	for(char i='0';i<='9';i++)
		harsh.insert({i,i-'0'});
	for(char i='A';i<='N';i++,index++)
		harsh.insert({i,index});
}
int main() {
	init();
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int len=min(a.size(),b.size());
	bool flag=false;
	for(int i=0;i<len;i++){
		if(a[i]==b[i]){
			if(flag==false){
				if(mp.find(a[i])!=mp.end()){
					printf("%s ",mp[a[i]].c_str());
					flag=true;
				}
			}else if(harsh.find(a[i])!=harsh.end()){
					printf("%02d:",harsh[a[i]]);
					break;
			}
		}
	}
	len=min(c.size(),d.size());
	for(int i=0;i<len;i++){
		if(c[i]==d[i]&&isalpha(c[i])){
			printf("%02d",i);
			break;
		}
	}
}
/*
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
*/
