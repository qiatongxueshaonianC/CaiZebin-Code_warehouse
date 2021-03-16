#include<bits/stdc++.h>
using namespace std;
const int maxn=2010;
struct Node {
	string name;
	int weight;
	int flag;
	Node(){
		flag=0;
		weight=0;
	}
};
unordered_map<int,Node> iput;
unordered_map<string,int>mp;
int numperson=0;
int trans(string& str){
	if(mp.find(str)==mp.end()){
		numperson++;
		mp[str]=numperson;
	}
	return mp[str];
}
int main() {
	int n,k,w,group=0;
	string s1,s2;
	scanf("%d%d%*c",&n,&k);
	for(int i=0;i<n;i++){
		cin>>s1>>s2>>w;
		int id1=trans(s1);
		int id2=trans(s2);
		iput[id1].name=s1;
		iput[id1].weight+=w;
		iput[id2].name=s2;
		iput[id2].weight+=w;
		if(iput[id1].flag==0&&iput[id2].flag==0)
			iput[id1].flag=iput[id2].flag=++group;
		else {
			bool fg=true;
			iput[id1].flag==0?iput[id1].flag=iput[id2].flag:iput[id2].flag==0?iput[id2].flag=iput[id1].flag:fg=false;
			if(fg==false){//两队做调整 
				int tp=iput[id2].flag;
				int tq=iput[id1].flag;
				if(iput[id1].flag<iput[id2].flag){
					for(auto& i:iput){
						if(i.second.flag==tp)
							i.second.flag=iput[id1].flag;
					}
				}else{
					for(auto& i:iput){
						if(i.second.flag==tp)
							i.second.flag=tq;
					}
				}
			}
		}
	}
/*	for(auto i:iput){  //用于检查状态 
		printf("%s %d %d\n",i.second.name.c_str(),i.second.weight,i.second.flag);
	}*/ 
	int np=0,ng=0,tolvalue,maxweight;
	string nam;
	map<string,int> ans;
	for(int i=1;i<=group;i++){
		tolvalue=0;np=0;maxweight=0;
		for(auto k:iput){
			if(k.second.flag!=i) continue;
			tolvalue+=k.second.weight;
			np++;
			if(k.second.weight>maxweight) {
				maxweight=k.second.weight;
				nam=k.second.name;
			}
		}
		if(np>2&&tolvalue>k){
			ans[nam]=np;
		}
	}
	printf("%d\n",ans.size());
	for(auto i:ans)
		printf("%s %d\n",i.first.c_str(),i.second);
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
