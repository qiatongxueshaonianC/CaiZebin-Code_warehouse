#include<bits/stdc++.h>
using namespace std; 
int main() {
	string ans,s;
	int N,flag=0;
	cin>>ans>>N;getchar();
	while(N--&&flag==0){
	//	cin>>s;
		getline(cin,s);//2020/1/26/16:47发现，这里每行表示一个用户的输入，可能包含空格，虽然正确密码没有空格 
		if(s=="#") break; 
		if(s!=ans)
			printf("Wrong password: %s\n",s.c_str());
		else{
			puts("Welcome in");
			flag=1;
		}
	}
	if(N==-1&&flag==0)  //即使输入的没有正确密码，但是没达到N次也不输出这句 
		puts("Account locked");
	while(s!="#") cin>>s; //如果是多个测试例子，则要读完，否则会影响下一次 
	return 0;
}
/*
Correct%pw 3
correct%pw
Correct@PW
whatisthepassword!
Correct%pw
#

cool@gplt 3
coolman@gplt
coollady@gplt
cool@gplt
try again
#
*/
