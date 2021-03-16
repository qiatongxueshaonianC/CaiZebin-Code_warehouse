#include<bits/stdc++.h>
using namespace std; 
struct win{
	int endTime;
	queue<int> q;
}W[20];
int change(int h,int m){
	return h*60+m;
}
int main() {
	int stTime=change(8,0);
	int edTime=change(17,0);
	int N,M,K,Q,v;
	scanf("%d%d%d%d",&N,&M,&K,&Q);
	for(int i=0;i<N;i++)
		W[i].endTime=stTime;
	int A[K+1],ans[K+1];
	for(int i=0;i<K;i++)
		scanf("%d",&A[i]);
	int len=min(N*M,K);
	for(int i=0;i<len;i++){
		int idx=i%N;
		W[idx].endTime+=A[i];
		W[idx].q.push(W[idx].endTime);
		ans[i]=W[idx].endTime;
	}
	for(len;len<K;len++){
		int idx,minPopTime=1<<30;
		for(int i=0;i<N;i++){
			if(W[i].q.front()<minPopTime){
				minPopTime=W[i].q.front();  //minPopTime作用只是为了找到最小的 
				idx=i;
			}
		}
		W[idx].q.pop();
		W[idx].endTime+=A[len];
		W[idx].q.push(W[idx].endTime);
		ans[len]=W[idx].endTime;
	}
	while(Q--){
		scanf("%d",&v);
		if(ans[v-1]-A[v-1]>=edTime)
			puts("Sorry");
		else
			printf("%02d:%02d\n",ans[v-1]/60,ans[v-1]%60);
	}
	return 0;
}
/*
2 2 7 5
1 2 6 4 3 534 2
3 4 5 6 7
*/
