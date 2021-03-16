#include<bits/stdc++.h>
using namespace std; 
const int maxn=100010;
bool harsh[maxn];
int main() {
	int n,v;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		if(v<0||v>maxn) continue; //2019/15/5/0：27发现改正 
		harsh[v]=true;				//注意，输入的数可能会大于maxn，不加限制会段错误  
	}
	for(int i=1;i<maxn;i++){
		if(harsh[i]==false){
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}
/*
10
5 -25 9 6 1 3 4 2 5 17
*/
