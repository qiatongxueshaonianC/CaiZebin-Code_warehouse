#include<bits/stdc++.h>
using namespace std; 
int main() {
	int N;
	scanf("%d",&N);
	unordered_map<int,int> mp;
	for(int i=1;i<=N;i++){
		double temp=floor(i/2.0)+floor(i/3.0)+floor(i/5.0);
		mp[(int)temp]++;
	} 
	printf("%d",mp.size());
	return 0;
}
/*
2017
*/
