#include<bits/stdc++.h>
using namespace std; 
typedef pair<int,pair<string,string>> P;
priority_queue<P,vector<P>,greater<P>> M;
priority_queue<P> F;
int main() {
	int n,grade;
	string s1,s2,s3;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>s1>>s2>>s3>>grade;
		if(s2=="M")
			M.push({grade,{s1,s3}});
		else F.push({grade,{s1,s3}});
	}
	if(F.size()){
		P now=F.top();
		printf("%s %s\n",now.second.first.c_str(),now.second.second.c_str());
	}else puts("Absent");
	if(M.size()){
		printf("%s %s\n",M.top().second.first.c_str(),M.top().second.second.c_str());
	}else puts("Absent");
	if(M.size()&&F.size()){
		printf("%d",F.top().first-M.top().first);
	}else puts("NA");
	return 0;
}
/*
3
Joe M Math990112 89
Mike M CS991301 100
Mary F EE990830 95

1
Jean M AA980920 60
*/
