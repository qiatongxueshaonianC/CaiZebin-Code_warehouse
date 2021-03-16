#include<bits/stdc++.h>
using namespace std;
const int maxn=22;
bool harsh[maxn];
int n,r;
vector<int> ans;
void DFS(int num){
	if(num==r){
		for(auto i:ans){
			printf("%d",i);
			if(i!=*(ans.end()-1)) printf(" ");
		}
		puts("");
		return;
	}
	for(int i=1;i<=n;i++){
		if(harsh[i]==false&&i>(!ans.empty()?ans.back():0)){
			ans.push_back(i);
			harsh[i]=true;
			DFS(num+1);
			ans.pop_back();
			harsh[i]=false;
		}
	}
}
int main() {
	scanf("%d%d",&n,&r);
	DFS(0);
	return 0;
}
/*
5 3
6 4
*/
