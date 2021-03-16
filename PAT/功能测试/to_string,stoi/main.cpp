#include<bits/stdc++.h>
using namespace std; 
string To_string(int a){
	string ans="";
	int temp;
	while(a!=0){
		temp=a%10;
		char c=temp+'0';
		ans=c+ans;
		a/=10;
	}
	return ans;
} 
int Stoi(string s){
	int ans;
	for(int i=0;i<s.size();i++){
		ans=ans*10+s[i]-'0';
	}
	return ans;
}
int main() {
	int n;
	scanf("%d",&n);
	string line=To_string(n);
	puts(line.c_str());
	printf("%d\n",Stoi(line));
	return 0;
}
