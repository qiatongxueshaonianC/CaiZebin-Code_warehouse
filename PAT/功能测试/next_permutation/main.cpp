#include<bits/stdc++.h>
using namespace std;
int main() {
	vector<int> A={3,1,2};
	do{
		for(auto i:A)
			printf("%d ",i);
		puts("");
	}while(next_permutation(A.begin(),A.end()));
	return 0;
}
/*
1000 1000
*/
