#include<bits/stdc++.h>
using namespace std; 
struct School{
	int quota,last_rank;
	vector<int> receive;
	School():quota(0){}
}S[100];
struct Stu{
	int id,GE,GI,sum,rank;
	queue<int> want;
};
vector<Stu> stu;
bool cmp(int a,int b){
	if(stu[a].sum!=stu[b].sum) return stu[a].sum>stu[b].sum;
	else return stu[a].GE>stu[b].GE;
}
int main() {
	int N,M,K,v;
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<M;i++)
		scanf("%d",&S[i].quota);
	stu.resize(N);
	for(int i=0;i<N;i++){
		scanf("%d%d",&stu[i].GE,&stu[i].GI);
		stu[i].sum=stu[i].GE+stu[i].GI;
		stu[i].id=i;
		for(int j=0;j<K;j++){
			scanf("%d",&v);
			stu[i].want.push(v);
		}
	}
	int rank=1,visit[N];
	iota(visit,visit+N,0);
	sort(visit,visit+N,cmp);  //对访问顺序进行排序 
	stu[visit[0]].rank=1;
	for(int i=1;i<stu.size();i++){
		int now=visit[i],pre=visit[i-1];
		rank=stu[now].sum==stu[pre].sum&&stu[now].GE==stu[pre].GE?rank:(i+1);
		stu[now].rank=rank;
	}
	for(int i=0;i<N;i++){
		Stu now=stu[visit[i]];
		while(now.want.size()){   //还有志愿 
			int w=now.want.front();now.want.pop();
			if(S[w].quota>0||S[w].last_rank==now.rank){  //接收条件 
				S[w].quota--;
				S[w].last_rank=now.rank;
				S[w].receive.push_back(now.id);
				break;
			}
		}
	}
	for(int i=0;i<M;i++){
		sort(S[i].receive.begin(),S[i].receive.end());
		for(auto j:S[i].receive)
			printf("%d%s",j,j==*(--S[i].receive.end())?"":" ");
		puts("");
	} 
	return 0;
}
/*
11 6 3
2 1 2 2 2 3
100 100 0 1 2
60 60 2 3 5
100 90 0 3 4
90 100 1 2 0
90 90 5 1 3
80 90 1 0 2
80 80 0 1 2
80 80 0 1 2
80 70 1 3 2
70 80 1 2 3
100 100 0 2 4
*/
