#include<bits/stdc++.h>
using namespace std; 
int main() {
	int N,D;
	double e,u;
	scanf("%d%lf%d",&N,&e,&D);
	pair<int,int> Ans(0,0);
	for(int i=0;i<N;i++){
		int k,maybe=0;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%lf",&u);
			if(u<e)
				maybe++;
		}
		if(k>D&&maybe*2>k) Ans.second++;  //2020/1/27/15:06���֣�����һ��Ҫ������Ŀ����k>D!! 
		else if(maybe*2>k) Ans.first++;
	}
	printf("%.1lf%% %.1lf%%",100.0*Ans.first/N,100.0*Ans.second/N);
}
/*
5 0.5 10
6 0.3 0.4 0.5 0.2 0.8 0.6
10 0.0 0.1 0.2 0.3 0.0 0.8 0.6 0.7 0.0 0.5
5 0.4 0.3 0.5 0.1 0.7
11 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1
11 2 2 2 1 1 0.1 1 0.1 0.1 0.1 0.1
*/
