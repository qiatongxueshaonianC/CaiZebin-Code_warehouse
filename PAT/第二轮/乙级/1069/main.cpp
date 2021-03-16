#include<bits/stdc++.h>
using namespace std;
int main() {
	int M,N,pre,output=0;
	scanf("%d%d%d%*c",&M,&N,&pre);
	vector<string> A(M+1);
	set<string> st;
	string s;
	for(int i=1;i<=M;i++){
		getline(cin,s);
		if(i>=pre&&(i-pre)%N==0){
			if(st.find(s)==st.end()){
				st.insert(s);
				output=1;
				puts(s.c_str());
			}
			else
				pre++;
		}
	}
	if(output==0)
		puts("Keep going...");
	return 0;
}
/*
9 3 2
Imgonnawin!
PickMe
PickMeMeMeee
LookHere
Imgonnawin!
TryAgainAgain
TryAgainAgain
Imgonnawin!
TryAgainAgain

2 3 5
Imgonnawin!
PickMe
*/
