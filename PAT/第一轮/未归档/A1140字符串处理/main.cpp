#include<bits/stdc++.h>
using namespace std; 
int main() {
	string str;
	int n;
	cin>>str>>n;
	while(--n){
		string s="";
		int k;
		for(int i=0;i<str.size();i=k){
			for(k=i;str[k]==str[i];k++);
			s+=(str[i]+to_string(k-i));
		}
		str=s;	
	}
	printf("%s\n",str.c_str());
	return 0;
}
/*
1 8
*/
