#include<bits/stdc++.h>
using namespace std;
int main() {
	int d,n;
	scanf("%d%d",&d,&n);
	string s1=string(1,d+'0');
	while(--n){
	//	puts(s1.c_str());
		string s2="";
		for(int i=0;i<s1.size();){
			s2+=s1[i];
			int k=i+1;
			while(s1[k]==s1[i]) k++;
			s2+=to_string(k-i);
			i=k;
		}
		s1=s2;
	}
	puts(s1.c_str());
	return 0;
}
/*
1 8
*/
