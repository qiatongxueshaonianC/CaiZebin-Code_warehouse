#include<bits/stdc++.h>
using namespace std;
unordered_map<string,vector<int>>mp;
int main() {
	int query,n;
	string name;
	scanf("%d%d",&query,&n);
	while(n--){
		int course_id,num;
		scanf("%d%d",&course_id,&num);
		while(num--){
			cin>>name;
			if(mp.find(name)==mp.end()){
				vector<int> temp;
				temp.push_back(course_id);
				mp[name]=temp;
			}else{
				mp[name].push_back(course_id);
			}
		}
	}
	for(int i=0;i<query;i++){
		cin>>name;
		printf("%s %d",name.c_str(),mp[name].size());
		sort(mp[name].begin(),mp[name].end());
		for(auto i:mp[name])
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
