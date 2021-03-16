#include<bits/stdc++.h>
using namespace std;
const int inf=0x3fffffff;
struct Node{
	int id,grade[6],sum,perfect,rank;
	bool flag;
	Node(){
		fill(grade,grade+6,-1);
		sum=-inf;
		perfect=0;
		flag=0;   //无效点 
		rank=1;
	}
}stu[10005];
bool cmp(Node a,Node b){
	 if(a.sum!=b.sum) return a.sum>b.sum;
	else if(a.perfect!=b.perfect) return a.perfect>b.perfect;
	else return a.id<b.id;
}
int main() {
	int N,K,M,rank_num=0;
	scanf("%d%d%d",&N,&K,&M);
	int problem[K+1];
	for(int i=1;i<=K;i++)
		scanf("%d",&problem[i]);
	int id,p,s;
	for(int i=0;i<M;i++){
		scanf("%d%d%d",&id,&p,&s);
		if(s==-1) {
			if(stu[id].grade[p]==-1) stu[id].grade[p]=0;
			continue; 
		}
		stu[id].id=id;
		stu[id].flag=true;
		if(s>stu[id].grade[p])
			stu[id].grade[p]=s;
	}
	for(int i=1;i<=N;i++){
		if(!stu[i].flag) continue; 
		stu[i].sum=0;
		rank_num++;
		for(int j=1;j<=5;j++){
			if(stu[i].grade[j]!=-1){
				stu[i].sum+=stu[i].grade[j];
				if(stu[i].grade[j]==problem[j])
					stu[i].perfect++;
			}
		}
	}
	sort(stu,stu+N+1,cmp);  //这里应是N+1因为学生标号从1开始   不知道哪些学生不进入排名 
	int rank=1;
	stu[0].rank=1;
	for(int i=1;i<rank_num;i++){
		rank=stu[i].sum==stu[i-1].sum?rank:(i+1);
		stu[i].rank=rank;
	}
	for(int i=0;i<rank_num;i++){
		printf("%d %05d %d",stu[i].rank,stu[i].id,stu[i].sum);
		for(int j=1;j<=K;j++){
			if(stu[i].grade[j]==-1) printf(" -");
			else printf(" %d",stu[i].grade[j]);
		}
		puts("");
	}
	return 0;
}
/*
7 4 20
20 25 25 30
00002 2 12
00007 4 17
00005 1 19
00007 2 25
00005 1 20
00002 2 2
00005 1 15
00001 1 18
00004 3 25
00002 2 25
00005 3 22
00006 4 -1
00001 2 18
00002 1 20
00004 1 15
00002 4 18
00001 3 4
00001 4 2
00005 2 -1
00004 2 0
*/
