#include<bits/stdc++.h>
using namespace std; 
bool judge(string s){
	int k=s.find_first_not_of("+-.0123456789"),temp;
	if(k!=string::npos) return false;
	k=s.find('.');
	if(k!=string::npos){
		if(s.size()-k-1>2) return false;
		temp=s.find_first_not_of("0123456789",k+1);
		if(temp!=string::npos) return false;
	}
	double a;
	a=stod(s);
	return abs(a)>1000?false:true;
}
int main() {
	int n;
	string s;
	scanf("%d",&n);
	pair<double,int> ans{0,0};
	for(int i=0;i<n;i++){
		cin>>s;
		if(judge(s)){
			ans.first+=stod(s);
			ans.second++;
		}else
			printf("ERROR: %s is not a legal number\n",s.c_str());
	}
	if(ans.second>0)
		printf("The average of %d %s is %.2lf",ans.second,ans.second>1?"numbers":"number",ans.first/ans.second);
	else 
		puts("The average of 0 numbers is Undefined");
	return 0;
}
/*
7
5 -3.2 aaa 9999 2.3.4 7.+2+ 2.35

5
aaa -9999 1.23 0000..2 1000
*/
