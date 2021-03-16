#include<bits/stdc++.h>
using namespace std; 
string tab[55];
void make_tab(){
	string s="SHCD";
	for(int i=0;i<4;i++)
		for(int j=1;j<=13;j++){
			string temp="";
			temp+=s[i];
			tab[i*13+j]=temp+to_string(j%13==0?13:j%13);
		}
	tab[53]="J1";
	tab[54]="J2";
}
int main() {
	make_tab();
	vector<int> init(55),temp(55),trans(55);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=54;i++)
		scanf("%d",&trans[i]);
	iota(init.begin()+1,init.begin()+55,1);
	while(n--){
		for(int i=1;i<=54;i++)
			temp[trans[i]]=init[i];
		init=temp;
	}
	for(int i=1;i<=54;i++)
		printf("%s%s",tab[init[i]].c_str(),i==54?"":" ");
	return 0;
}
/*
2
36 52 37 38 3 39 40 53 54 41 11 12 13 42 43 44 2 4 23 24 25 26 27 6 7 8 48 49 
50 51 9 10 14 15 16 5 17 18 19 1 20 21 22 28 29 30 31 32 33 34 35 45 46 47
*/
