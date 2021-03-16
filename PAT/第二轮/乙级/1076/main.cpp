#include<bits/stdc++.h>
using namespace std; 
int main() {
	int N;
	string s;
	scanf("%d%*c",&N);
	unordered_map<char,int> mp={{'A',1},{'B',2},{'C',3},{'D',4}};
	for(int i=0;i<N;i++){
		getline(cin,s);
		int k=s.find('T');
		printf("%d",mp[s[k-2]]);
	} 
	return 0;
}
/*
8
A-T B-F C-F D-F
C-T B-F A-F D-F
A-F D-F C-F B-T
B-T A-F C-F D-F
B-F D-T A-F C-F
A-T C-F B-F D-F
D-T B-F C-F A-F
C-T A-F B-F D-F
*/
