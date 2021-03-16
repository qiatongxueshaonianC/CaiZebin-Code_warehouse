#include<bits/stdc++.h>
using namespace std; 
map<string,int>L,H;
map<int,string> itosL,itosH;
void init(map<string,int>& a,string s,int f){
	stringstream str(s);
	string temp;
	if(f==0){
		int idx=0;
		while(str>>temp){
		L.insert({temp,idx});
		itosL.insert({idx,temp});
		idx++;
		}
	}else{
		int idx=1;
		while(str>>temp){
			H.insert({temp,idx});
			itosH.insert({idx,temp});
			idx++;
		}
	}
}
int main() {
	string s="tret jan feb mar apr may jun jly aug sep oct nov dec",
			s1="tam hel maa huh tou kes hei elo syy lok mer jou";
	init(L,s,0);
	init(H,s1,1);
	int n,k;
	scanf("%d%*c",&n);
	while(n--){
		getline(cin,s);
		if(isdigit(s[0])){
			k=stoi(s);
			if(k>=13){
				if(k%13!=0)
					printf("%s %s\n",itosH[k/13].c_str(),itosL[k%13].c_str());	
				else
					printf("%s\n",itosH[k/13].c_str());	
			}			
			else
				printf("%s\n",itosL[k].c_str());
		}else{
			int j=s.find(' ');
			if(j!=string::npos){
				s1=s.substr(j+1);
				s=s.substr(0,j);
				printf("%d\n",H[s]*13+L[s1]);
			}else{
				if(H.find(s)!=H.end())
					printf("%d\n",H[s]*13);
				else
					printf("%d\n",L[s]);
			}
		}
	}
	return 0;
}
/*
6
29
5
elo nov
tam
13
0
*/
