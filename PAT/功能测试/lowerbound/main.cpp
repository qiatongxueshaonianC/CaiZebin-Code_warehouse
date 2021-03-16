#include<bits/stdc++.h>
using namespace std;
int main() {
	vector<int> vct;
	for(int i=0;i<6;i++){
		vct.push_back(i);
	}
	auto lowpos=lower_bound(vct.begin(),vct.end(),1);  //转变成了下标 
	auto uppos=upper_bound(vct.begin(),vct.end(),1);
	printf("%d\n",lowpos-vct.begin());
	printf("%d",uppos-vct.begin());
	return 0;
}
