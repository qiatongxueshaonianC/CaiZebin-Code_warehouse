#include<bits/stdc++.h>
using namespace std;
int me,X,Y,jia,yi,bin; 
string cmp(double a){
	return a>me?"Cong":a==me?"Ping":"Gai";
}
int main() {
	scanf("%d%d%d",&me,&X,&Y);
	bool solve=false;
	string s;
	for(int i=99;i>9;i--){
		jia=i;
		s=to_string(i);
		reverse(s.begin(),s.end());
		yi=stoi(s);
		if(abs(jia-yi)*Y==yi*X){
			solve=true;
			break;
		}
	}
	if(solve)
		printf("%d %s %s %s",jia,cmp(jia).c_str(),cmp(yi).c_str(),cmp(abs(jia-yi)*1.0/X).c_str());
	else
		puts("No Solution");
//	printf("%d %d %d",jia,yi,bin);
	return 0;
}
/*
48 3 7

48 11 6
*/
