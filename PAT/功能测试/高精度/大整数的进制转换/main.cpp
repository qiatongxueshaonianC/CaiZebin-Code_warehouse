#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<climits>
#include<numeric>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<bitset>
using namespace std; 
struct bigInteger{
	static const int Base=10000;
	static const int maxDigit=1010;
	int digit[maxDigit];
	int size;
	void init(){
		memset(digit,0,sizeof(digit));
		size=0;
	}
	void set(int x){
		init();
		do{
			digit[size++]=x%Base;
			x/=Base;
		}while(x!=0);
	}
	void output(){
		for(int i=size-1;i>=0;i--){
			if(i!=size-1)
				printf("%04d",digit[i]);
			else
				printf("%d",digit[i]);
		}
		puts("");
	}
	bigInteger operator * (const bigInteger& b) const{
		bigInteger ret;
		ret.init();
		int up=max(size,b.size);
		for(int t=0;t<up;t++){
			for(int i=0;i<up;i++){
				ret.digit[t+i]+=digit[t]*b.digit[i];
				ret.digit[t+i+1]+=ret.digit[t+i]/Base;
				ret.digit[t+i]=ret.digit[t+i]%Base;
			}
		}
		ret.size=up+up;
		while(ret.size>1&&ret.digit[ret.size-1]==0)
			ret.size--;
		return ret;
	}
	bigInteger operator + (const bigInteger& b)const{
		bigInteger ret;
		ret.init();
		int carry=0;
		for(int i=0;i<size||i<b.size;i++){
			int num=digit[i]+b.digit[i]+carry;
			ret.digit[ret.size++]=num%Base;
			carry=num/Base;
		}
		if(carry!=0)
			ret.digit[ret.size++]=carry;
		return ret;
	}
	bigInteger operator / (int x)const{
		bigInteger ret;
		ret.init();
		ret.size=size;
		int remain=0;
		for(int i=size-1;i>=0;i--){
			remain=(remain*Base+digit[i]);
			if(remain<x)
				ret.digit[i]=0;
			else{
				ret.digit[i]=remain/x;
				remain=remain%x;
			}
		}
		while(ret.size>1&&ret.digit[ret.size-1]==0)
			ret.size--;
		return ret;
	}
	int operator % (const int& x)const{
		int remain=0;
		for(int i=size-1;i>=0;i--){
			remain=remain*Base+digit[i];
			remain=remain%x;
		}
		return remain;
	}
}a,b,c,d;
int n,m;
string s;
int main() {
	while(scanf("%d%d%*c",&m,&n)!=EOF){
		getline(cin,s);
		a.set(0);
		b.set(1);
		for(int i=s.size()-1;i>=0;i--){
			int num=isdigit(s[i])?s[i]-'0':s[i]-'A'+10;
			d.set(num);
			a=a+b*d;
			d.set(m);
			b=b*d;
		//	b.output();
		}
		string ans;
		do{
			int num=a%n;
			char c;
			if(num>=10)
				c=num-10+'a';
			else
				c=num+'0';
			ans.push_back(c);
			a=a/n;
		}while(a.digit[0]!=0||a.size!=1);
		reverse(ans.begin(),ans.end());
		puts(ans.c_str());
	}
	return 0;
}
/*
16 2
FFFF

2 16
1111111111111111
16 10
F
*/
