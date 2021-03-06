#include<bits/stdc++.h>
using namespace std; 
const int maxn=105;
const int maxc=63; 
string s,bd[maxn]; 
int n,cnt[maxc],mp[maxn][maxc],remain=INT_MAX;
int f(char& c){
	if(c>='0'&&c<='9') return c-'0';
	if(isupper(c)) return c-'A'+10;
	if(c>='a'&&c<='z') return c-'a'+36;
}
void init(){
	for(auto i:s) cnt[f(i)]++;
	for(int i=0;i<n;i++){
		for(auto j:bd[i])
			mp[i][f(j)]++;
	}
}
void test(){
	int need=0;
	for(int i=0;i<maxc;i++){
		int valid=0;
		for(int j=0;j<n;j++)
			valid+=mp[j][i];
		if(valid<cnt[i])
			need+=cnt[i]-valid;
	}
	if(need>0){
		printf("%s %d","No",need);
		exit(0);
	}
}
void DFS(int idx,int rm){
	if(idx==n||rm>=remain) return;
	int exert=0,flag=1,temp[maxc];memcpy(temp,cnt,sizeof(cnt));
	for(int i=0;i<maxc;i++){
		if(mp[idx][i]<cnt[i]){
			flag=0;
			cnt[i]-=mp[idx][i];
		}else{
			exert+=mp[idx][i]-cnt[i],
			cnt[i]=0;	
		}
	}
	if(flag==1)
		remain=min(remain,rm+exert);
	else
		DFS(idx+1,rm+exert);
	memcpy(cnt,temp,sizeof(temp));
	DFS(idx+1,rm);  //不选第idx这一序列 
}
int main() {
	cin>>s>>n;
	for(int i=0;i<n;i++)
		cin>>bd[i];
	init(),test(),DFS(0,0);
	printf("%s %d","Yes",remain);
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
