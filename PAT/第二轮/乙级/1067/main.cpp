#include<bits/stdc++.h>
using namespace std; 
int main() {
	string ans,s;
	int N,flag=0;
	cin>>ans>>N;getchar();
	while(N--&&flag==0){
	//	cin>>s;
		getline(cin,s);//2020/1/26/16:47���֣�����ÿ�б�ʾһ���û������룬���ܰ����ո���Ȼ��ȷ����û�пո� 
		if(s=="#") break; 
		if(s!=ans)
			printf("Wrong password: %s\n",s.c_str());
		else{
			puts("Welcome in");
			flag=1;
		}
	}
	if(N==-1&&flag==0)  //��ʹ�����û����ȷ���룬����û�ﵽN��Ҳ�������� 
		puts("Account locked");
	while(s!="#") cin>>s; //����Ƕ���������ӣ���Ҫ���꣬�����Ӱ����һ�� 
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
