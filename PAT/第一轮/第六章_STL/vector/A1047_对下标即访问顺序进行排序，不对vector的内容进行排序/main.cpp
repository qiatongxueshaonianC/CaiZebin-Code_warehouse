#include<bits/stdc++.h>
using namespace std; 
const int maxn=40010;
char stu[maxn][5],name[5];
vector<int> course[2505];
bool cmp(int a,int b){  //对下标进行排序 
	return strcmp(stu[a],stu[b])<0;
}
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		int num,course_id;
		scanf("%s%d",&stu[i],&num);
		while(num--){
			scanf("%d",&course_id);
			course[course_id].push_back(i);
		}
	}
	for(int i=1;i<=k;i++){
		printf("%d %d\n",i,course[i].size());
		sort(course[i].begin(),course[i].end(),cmp);
		for(auto j:course[i])
			puts(stu[j]);
	}
	return 0;
}
/*
10 5
ZOE1 2 4 5
ANN0 3 5 2 1
BOB5 5 3 4 2 1 5
JOE4 1 2
JAY9 4 1 2 5 4
FRA8 3 4 2 5
DON2 2 4 5
AMY7 1 5
KAT3 3 5 4 2
LOR6 4 2 4 1 5
*/
