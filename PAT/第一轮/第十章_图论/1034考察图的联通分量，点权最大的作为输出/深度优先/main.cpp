#include<bits/stdc++.h>
using namespace std;
const int maxn=2010;
map<int,string> ITOS;
map<string,int> STOI;
map<string,int> Gang;
int G[maxn][maxn]={0},weight[maxn]={0};
int numperson=0,n,k,vis[maxn]={false};
int trans(string& str){
	if(STOI.find(str)==STOI.end()){
		STOI[str]=numperson;
		ITOS[numperson]=str;
		numperson++;
	}
	return STOI[str];
}
void DFS(int now,int& head,int& numMerber,int& tolvalue){
	vis[now]=true;
	numMerber++;
	if(weight[now]>weight[head])
		head=now;
	for(int i=0;i<numperson;i++){
		if(G[now][i]>0){
			tolvalue+=G[now][i];
			G[now][i]=G[i][now]=0;
			if(vis[i]==false)
				DFS(i,head,numMerber,tolvalue);
		}
	}
}
void DFSTrave(){
	for(int i=0;i<numperson;i++){
		if(vis[i]==false){
			int head=i,numMerber=0,tolvalue=0;
			DFS(i,head,numMerber,tolvalue);
			if(numMerber>2&&tolvalue>k)
				Gang[ITOS[head]]=numMerber;
		}
	}
}
int main() {
	int w;
	string s1,s2;
	scanf("%d%d%*c",&n,&k);
	while(n--){
		cin>>s1>>s2>>w;
		int id1=trans(s1);
		int id2=trans(s2);
		G[id1][id2]+=w;
		G[id2][id1]+=w;
		weight[id1]+=w;
		weight[id2]+=w;
	}
	DFSTrave();
	cout<<Gang.size()<<endl;
	for(auto i:Gang)
		cout<<i.first<<' '<<i.second<<endl;
	return 0;
}
/*
12 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
III JJJ 10
JJJ KKK 20
KKK LLL 1
AAA III 5
*/

/*
3 56
AAA BBB 10
BBB AAA 20
AAA CCC 40
*/

/*
3 56
AAA BBB 10
BBB AAA 20
AAA CCC 40
*/
