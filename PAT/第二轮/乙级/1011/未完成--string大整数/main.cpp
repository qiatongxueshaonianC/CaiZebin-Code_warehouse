#include<bits/stdc++.h>
using namespace std; 
void deal(string &a){
	while(a[0]==0)
		a.erase(a[0]);
}
bool cmp(string a,string b){
	if(a[0]=='-'&&b[0]!='-')
		return false;
	if(a[0]!='-'&&b[0]=='-')
		return true;
	if(a[0]=='-'&&b[0]=='-'){
		a.erase(a.begin());
		b.erase(b.begin());
		swap(a,b);
	}
	if(a.size()>b.size())
		return true;
	else if(a.size()<b.size())
		return false;
	for(int i=0;i<a.size();i++){
		if(a[i]<b[i])
			return false;
	}
	if(a==b)return false;
	return true;
}
int main() {
	string a,b,c;
	cin>>a>>b>>c; 
	return 0;
}
/*
4
1 2 3
2 3 4
2147483647 0 2147483646
0 -2147483648 -2147483647
*/
