#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<climits>
#include<numeric>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<fstream>
#include<ctime>
#include<iomanip>
#include<iterator>
#define lowbit(x) x&(-x)
using namespace std; 
const int maxn=32768+10;
int Euler[maxn];
void init(){
	for(int i=1;i<maxn;i++)
		Euler[i]=i;
	for(int i=2;i<maxn;i++){
		if(Euler[i]==i){	//说明i是个素数 
			for(int j=i;j<maxn;j+=i){
				Euler[j]=(Euler[j]/i)*(i-1);		//j有一个质因数i 
			} 
		}
	}
} 
int main() {
	init();
	int t,Q;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&Q);
		printf("%d\n",Euler[Q]);
	} 
	return 0;
}
/*
2
25608
24027
*/
