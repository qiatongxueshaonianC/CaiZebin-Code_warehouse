#include<bits/stdc++.h>
using namespace std;
struct win{
	int endTime;
	queue<int> q;
	win():endTime(8*60){}
	bool friend operator <(win a,win b){
		 	return a.q.front()>b.q.front();	
	}
}W[20]; 
priority_queue<win> Q;
int change(int h,int m){
	return h*60+m;
}
int main() {
	int stTime=change(8,0);
	int edTime=change(17,0);
	int n,m,k,query,v;
	scanf("%d%d%d%d",&n,&m,&k,&query);
	int A[k+1],ans[k+1];
	for(int i=0;i<k;i++)
		scanf("%d",&A[i]);
	int len=min(n*m,k);
	for(int i=0;i<len;i++){
		int idx=i%n;
		W[idx].endTime+=A[i];
		W[idx].q.push(W[idx].endTime);
		ans[i]=W[idx].endTime;
	}
	for(int i=0;i<n;i++)
		Q.push(W[i]);
	for(len;len<k;len++){
		win now=Q.top();Q.pop();
		now.q.pop();
		now.endTime+=A[len];
		now.q.push(now.endTime);
		ans[len]=now.endTime;
		Q.push(now);
	}
	while(query--){
		scanf("%d",&v);
		if(ans[v-1]-A[v-1]>=edTime)
			puts("Sorry");
		else
			printf("%02d:%02d\n",ans[v-1]/60,ans[v-1]%60);  //因为题目数据的下标是从1开始 
	}
	return 0;
}
/*
2 2 7 5
1 2 6 4 3 534 2
3 4 5 6 7
*/
