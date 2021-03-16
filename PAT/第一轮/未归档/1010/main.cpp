#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
string n1,n2;
int tag,radix;
unordered_map<char,int> trans;
void init(){
	string c="0123456789";
	for(char i:c)
		trans[i]=i-'0';
	c="abcdefghijklmnopqrstuvwxyz";
	for(auto i:c)
		trans[i]=i-'a'+10;
}
ll calcu(string s,int r){
	ll ans=0;
	for(auto i:s)
		ans=ans*r+trans[i];
	return ans;
}
int main() {
	init();
//	scanf("%s%s%d%d",&n1,&n2,&tag,&radix);  //string类型不能用scanf()!!!!!
	cin>>n1>>n2>>tag>>radix; 
	if(tag==2) swap(n1,n2);
	ll ori=calcu(n1,radix);
	ll min=0,right;
	for(auto i:n2)
		if(trans[i]>min) min=trans[i];
	right=max(min,ori)+1;
	for(int i=(min+1+right)/2;;i=(min+right)/2){
		ll now=calcu(n2,i);
		if(now==ori) {
			puts(to_string(i).c_str());
			break;
		}
		if(now>ori||now<0){
	/*		puts("Impossible");
			break;*/
			right=i;
		}else min=i;
		if(min>right){
			puts("Impossible");
			break;
		}
	}
	return 0;
}
/*
6 110 1 10

16 f 1 10

110 6 1 2

1 ab 1 2

16 10 1 16
*/
