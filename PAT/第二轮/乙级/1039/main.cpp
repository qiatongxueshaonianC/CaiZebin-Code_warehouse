#include<bits/stdc++.h>
using namespace std; 
int main() {
	string a,b;
	getline(cin,a);
	getline(cin,b); 
	int remain=0,need=0;
	for(int i=0;i<b.size();i++){
		int k=a.find(b[i]);
		if(k!=string::npos)
			a[k]=' ';
		else
			need++;
	} 
	printf("%s %d",need==0?"Yes":"No",need==0?a.size()-b.size():need);
	return 0;
}
/*
ppRYYGrrYBR2258
YrR8RrY

ppRYYGrrYB225
YrR8RrY
*/
