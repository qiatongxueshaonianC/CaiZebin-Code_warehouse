#include<bits/stdc++.h>
using namespace std; 
int main() {
	string s;
	int c=0,harsh[10]={0};
//	vector<int> harsh(10),A(10);
	getline(cin,s);
	reverse(s.begin(),s.end());
	for(auto& i:s){
		harsh[i-'0']++;
		char t=((2*(i-'0')+c)%10)+'0';
		c=(2*(i-'0')+c)/10;
		i=t;
		harsh[i-'0']--;
	//	A[i-'0']++;
	}
	if(count(harsh,harsh+10,0)!=10) puts("No");
	else puts("Yes");
	if(c!=0) s=s+to_string(c);
	reverse(s.begin(),s.end());
	puts(s.c_str()); 
	return 0; 
}
/*
1234567899
*/
