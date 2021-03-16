#include<bits/stdc++.h>
using namespace std; 
int main() {
	set<int,greater<int>> set1;
	set<int,less<int>> set2;
	map<int,int,greater<int>> mp1;
	map<int,int,less<int>> mp2;
	priority_queue<int,vector<int>,greater<int>> qg;
	priority_queue<int,vector<int>,less<int>> ql;
	for(int i=1;i<=5;i++){
		set1.insert(i);
		set2.insert(i);
		mp1[i]=2*i;
		mp2[i]=2*i;
		qg.push(i);
		ql.push(i);
	}
	puts("greater<int> Set:");
	for(auto i:set1)
		printf("%d ",i);
	puts("\nless<int> Set");
	for(auto i:set2)
		printf("%d ",i);
	printf("\ngreater<int> Map:\n");
	for(auto i:mp1)
		printf("%d~%d ",i.first,i.second);
	puts("\nless<int> Map");
	for(auto i:mp2)
		printf("%d~%d ",i.first,i.second);
	puts("\ngreater<int> priority_queue");
	while(qg.size()){
		printf("%d ",qg.top());
		qg.pop();
	}
	puts("\nless<int> priority_queue");
	while(ql.size()){
		printf("%d ",ql.top());
		ql.pop();
	}
	return 0;
}
