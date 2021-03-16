#include<bits/stdc++.h>
using namespace std; 
int main() {
	int harsh[128]={0},ans=0;
	string a,b;
	getline(cin,a);
	getline(cin,b);
	for(int i=0;i<a.size();i++)
		harsh[a[i]]++;
	for(int i=0;i<b.size();i++)
		harsh[b[i]]--;
	for(int i='0';i<128;i++)
		if(harsh[i]<0)
			ans+=harsh[i];
	if(ans<0)
		printf("%s %d\n","No",abs(ans));
	else
		printf("%s %d\n","Yes",a.size()-b.size());
	return 0;
}
/*
ppRYYGrrYBR2258
YrR8RrY

ppRYYGrrYB225
YrR8RrY
*/
