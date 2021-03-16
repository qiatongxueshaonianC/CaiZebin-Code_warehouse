#include<bits/stdc++.h>
using namespace std;
vector<set<int>> harshTable(1000000);
int strharsh(string s){
	int k=0;
	for(int i=0;i<3;i++)
		k=k*26+s[i]-'A';
	k=k*26+s[3]-'0';
	return k;
}
int main() {
	int query,n;
	string name;
	scanf("%d%d",&query,&n);
	for(int i=0;i<n;i++){
		int course_id,num;
		scanf("%d%d",&course_id,&num);
		while(num--){
			cin>>name;
			harshTable[strharsh(name)].insert(course_id);
		}
	}
	for(int i=0;i<query;i++){
		cin>>name;
		int k=strharsh(name);
		printf("%s %d",name.c_str(),harshTable[k].size());
		for(auto i:harshTable[k])
			printf(" %d",i);
		puts("");
	}
	return 0;
}
/*
11 5
4 7
BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
1 4
ANN0 BOB5 JAY9 LOR6
2 7
ANN0 BOB5 FRA8 JAY9 JOE4 KAT3 LOR6
3 1
BOB5
5 9
AMY7 ANN0 BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
ZOE1 ANN0 BOB5 JOE4 JAY9 FRA8 DON2 AMY7 KAT3 LOR6 NON9
*/
