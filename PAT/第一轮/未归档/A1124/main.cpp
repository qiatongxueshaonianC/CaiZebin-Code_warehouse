#include<bits/stdc++.h>
using namespace std;
unordered_map<string,bool> mp;
int main() {
	string checked;
	int m,n,s;
	scanf("%d%d%d",&m,&n,&s);
	char name[m+1][22];
	for(int i=1;i<=m;i++)
		scanf("%s",&name[i]);
	if(s>m)
		puts("Keep going...");
	while(s<=m){
		checked.assign(name[s]);
		while(mp.find(checked)!=mp.end()){
			s++;
			if(s>m){
				puts("Keep going...");
				return 0;
			}
			checked.assign(name[s]);
		}
		printf("%s\n",name[s]);
		s+=n;
		mp[checked]=true;
	}
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
