#include<bits/stdc++.h>
using namespace std;
bool judge(string s){
	int k=s.find(".");   //找到第一个'.' 
	if(k!=string::npos){
		if(s.find(".",k+1)!=string::npos)  //还有其他'.'返回错误 
			return false;
		int temp=s.find_last_of("0123456789");   //找到最后一个数字 
		if(temp-k>2) return false;
	}
	auto it=s.find_first_not_of("+-.0123456789");
	if(it!=string::npos)
		return false;
	double a,b;
	a=stod(s);
	if(a<-1000||a>1000) return false;
	return true;	
}
int main() {
	int n,valid=0;
	double sum=0;
	string s;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>s;
		if(judge(s)==false)
			printf("ERROR: %s is not a legal number\n",s.c_str());
		else{
			sum+=stod(s);
			valid++;
		}
	}
	if(valid>1) printf("The average of %d numbers is %.2lf\n",valid,sum/valid);
	else if(valid==1) printf("The average of 1 number is %.2lf\n",sum);
	else printf("The average of 0 numbers is Undefined\n");
	return 0;
}
/*
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35

7
2.35 -3.2 7.1200000000000003 5 aaa 9999 2.3.4 

3
2.35 -3.2 7.123 5 aaa 9999 2.3.4

2
aaa -9999
*/
