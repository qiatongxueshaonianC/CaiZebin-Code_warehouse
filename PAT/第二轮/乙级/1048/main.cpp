#include<bits/stdc++.h>
using namespace std; 
int main() {
	string a,b,ans="",trans="0123456789JQK";  //2020/1/24/19:32���֣�����k�Ĵ�Сд������� 
	cin>>a>>b;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	int len=max(a.size(),b.size()); 
	for(int i=0;i<len;i++){
		int numA=i<a.size()?a[i]-'0':0;
		int numB=i<b.size()?b[i]-'0':0; //�п���A�ĳ��ȱ�B������Ŀû˵��� 
		if(i%2==0)
			ans+=trans[(numA+numB)%13];
		else{
			int t=numB-numA;
			if(t<0) 
				t+=10;
			ans+=t+'0';
		}
	} 
	reverse(ans.begin(),ans.end());
	puts(ans.c_str());
	return 0;
}
/*
1234567 368782971
*/
