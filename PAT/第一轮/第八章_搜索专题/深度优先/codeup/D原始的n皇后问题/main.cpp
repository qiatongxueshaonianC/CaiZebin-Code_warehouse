#include<bits/stdc++.h>
using namespace std;
const int maxn=12;
int n;
vector<int> temp;
bool harsh[maxn],flag;
bool AC(vector<int> a){
	for(int i=0;i<a.size();i++){
		for(int j=i+1;j<n;j++){
			if(abs(j-i)==abs(a[i]-a[j])) return false;
		}
	}
	return true;
}
void DFS(int now){
	if(now==n&&AC(temp)){
		for(auto i:temp){
			printf("%d",i);
			if(i!=*(temp.end()-1)) printf(" ");
		}
		puts("");
		flag=true;
		return;
	}
	for(int i=1;i<=n;i++){
		if(harsh[i]==false){
			temp.push_back(i);
			harsh[i]=true;
			DFS(now+1);
			temp.pop_back();
			harsh[i]=false;
		}
	}
}
int main() {
	scanf("%d",&n);
	DFS(0); 
	if(!flag){
		puts("no solute!");
		return 0;
	}
	return 0;
}
/*
4
*/
