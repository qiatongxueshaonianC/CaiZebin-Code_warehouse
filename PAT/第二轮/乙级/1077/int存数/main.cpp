#include<bits/stdc++.h>
using namespace std; 
int main() {
	int N,M,a;
	scanf("%d%d",&N,&M); ;
	for(int i=0;i<N;i++){
		int t,sum=0;
		scanf("%d",&t);
		vector<int> A;
		for(int j=0;j<N-1;j++){
			scanf("%d",&a);
			if(0<=a&&a<=M)
				A.push_back(a);
		}
		sort(A.begin(),A.end());
		for(int k=1;k<A.size()-1;k++)
			sum+=A[k];
		printf("%d\n",(int)round((t+(sum*1.0/(A.size()-2)))/2));
	}
	return 0;
}
/*
6 50
42 49 49 35 38 41
36 51 50 28 -1 30
40 36 41 33 47 49
30 250 -25 27 45 31
48 0 0 50 50 1234
43 41 36 29 42 29

6 50
48 0 0 50 50 1234
*/
