#include<bits/stdc++.h>
using namespace std;
const int maxn=12;
int n;
bool harsh[maxn];
vector<int> ans;
void DFS(int now){
	if(now==n){
		for(auto i:ans){
			printf("%d",i);
			if(i!=*(ans.end()-1)) printf(" ");
		}
		puts("");
		return;
	}
	for(int i=1;i<=n;i++){
		if(harsh[i]==false){
			ans.push_back(i);
			harsh[i]=true;
			DFS(now+1);
			ans.pop_back();
			harsh[i]=false;
		}
	}
}
int main() {
	scanf("%d",&n);
	DFS(0);
	return 0;
}
