#pragma warning(disable:4996)
#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<climits>
#include<numeric>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<list> 
#define lowbit(x) x&(-x)
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
const int maxn=10000;
int N,A[maxn];
void Solve(){
	tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> T,TE;
	int Sum=0,right_less[maxn],right_more[maxn],temp=INT_MAX;
	for(int i=N-1;i>=0;i--){
		T.insert(A[i]);
		right_less[i]=T.order_of_key(A[i]);
		right_more[i] = (N - 1 - i) - right_less[i];
		Sum+=right_less[i];	//求的是逆序数总数，右边比它小的 
	}
	int left_less,left_more,ans=0,Min=INT_MAX;
	for(int i=0;i<N;i++){
		TE.insert(A[i]);
		left_less=TE.order_of_key(A[i]);
		left_more=i-left_less;
		ans+=(right_more[i]-right_less[i]-left_less+left_more);
		Min=min(Min,Sum+ans);
	//	printf("%d\n",Sum+ans);
	}
	printf("%d\n",Min);
}
int main() {
	while (cin >> N) {
		for (int i = 0; i < N; i++) {
			scanf("%d", &A[i]);
			A[i]++;
		}
		Solve();
	}
	return 0;
}
/*
10
1 3 6 9 0 8 5 7 4 2
*/
