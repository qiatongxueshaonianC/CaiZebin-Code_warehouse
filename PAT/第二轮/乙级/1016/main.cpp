#include<bits/stdc++.h>
using namespace std;
int deal(string s,int a){
	int k=0,ans=0;
	char c=a+'0';
	int j=s.find(c,k);
	while(j!=string::npos){
		ans=ans*10+a;
		k=j+1;
		j=s.find(c,k);
	}
	return ans;
} 
int main() {
	string A,B;
	int a,b;
	cin>>A>>a>>B>>b;
	int Pa=deal(A,a);
	int Pb=deal(B,b);
	printf("%d\n",Pa+Pb);
}
/*
3862767 6 13530293 3

3862767 1 13530293 8
*/
