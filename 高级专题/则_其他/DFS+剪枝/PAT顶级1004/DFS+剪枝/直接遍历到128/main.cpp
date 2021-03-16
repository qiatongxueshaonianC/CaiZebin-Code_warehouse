#include<bits/stdc++.h>
using namespace std; 
const int maxn=105;
const int maxc=129; 
int cnt[maxc],mp[maxn][maxc],n,remain=INT_MAX;
string s,t;
bool test(){
	int need=0;
	bool flag=true;
	for(int i=0;i<maxc;i++){
		int valid=0;
		for(int j=0;j<maxn;j++)
			valid+=mp[j][i];
		if(valid<cnt[i])
			need+=cnt[i]-valid;
	}
	if(need==0) return true;
	printf("%s %d","No",need);
	return false;
}
void DFS(int idx,int rm){
	if(idx==n||rm>=remain) return;  //2020/2/3/23:20发现，这里一定要取等，否则会超时 
	//选这一序列：
	int temp[maxc];memcpy(temp,cnt,sizeof(cnt));
	bool f=true;
	int ext=0;
	for(int i=0;i<maxc;i++){
		if(mp[idx][i]<cnt[i]){
			f=false;
			cnt[i]-=mp[idx][i];
		}else{
			ext+=mp[idx][i]-cnt[i];
			cnt[i]=0;
		} 
	}
	if(f)
		remain=min(remain,rm+ext); //成功，接下来只需要和不选这一序列的比 
	else
		DFS(idx+1,rm+ext);
	//不选 
	memcpy(cnt,temp,sizeof(temp));
	DFS(idx+1,rm);
}
int main() {
	getline(cin,s);
	for(auto i:s)
		cnt[i]++;
	scanf("%d%*c",&n);
	for(int i=0;i<n;i++){
		getline(cin,t);
		for(auto j:t)
			mp[i][j]++;
	}
	if(test()){
		DFS(0,0);
		printf("%s %d","Yes",remain);
	}
	return 0; 
}
/*
RYg5
8
gY5Ybf
8R5
12346789
gRg8h
5Y37
pRgYgbR52
8Y
8g

YrRR8RRrY
3
ppRGrrYB225
8ppGrrB25
Zd6KrY
*/
