#include<bits/stdc++.h>
using namespace std;
const int maxn=22;
const int inf=100000010;
typedef long long ll;
vector<pair<ll,int> > ans;
bool harsh[maxn];
int n,k,a[maxn],ans_num=0;
bool isPrime(int s){
	if(s<=1) return false;
	int sqr=(int)sqrt(1.0*s);
	for(int i=2;i<=sqr;i++){
		if(s%i==0) return false;
	}
	return true;
}
void DFS(int now){
	if(now==k){
		ll temp=0;
		for(auto i:ans)
			temp+=i.first;
		if(isPrime(temp)) ans_num++; 
		return;
	}
	for(int i=0;i<n;i++){
		if(harsh[i]==false&&i>(!ans.empty()?ans.back().second:-1)){
			ans.push_back({a[i],i});
			harsh[i]=true;
			DFS(now+1);
			ans.pop_back();
			harsh[i]=false;
		}
	}
}
int main() {
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	DFS(0);
	printf("%d\n",ans_num);
	return 0;
}
/*
4 3
3 7 12 19
*/
