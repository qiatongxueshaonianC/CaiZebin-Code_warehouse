#include<bits/stdc++.h>
using namespace std; 
const int maxn=10010;
int main() {
	string s;
	getline(cin,s);
	int k=s.find_first_of("PATest"),j,hash[129]={0};
	while(k!=string::npos){
		hash[s[k]]++;
		j=k+1;
		k=s.find_first_of("PATest",j);
	}
	int visit[6]={'P','A','T','e','s','t'};
	while(true){
		bool flag=false;
		for(int i=0;i<6;i++){
			if(hash[visit[i]]>0){
				printf("%c",visit[i]);
				hash[visit[i]]--;
				flag=true;				
			}
		}
		if(flag==false)
			break;
	}
	return 0;
}
/*
redlesPayBestPATTopTeePHPereatitAPPT
*/
