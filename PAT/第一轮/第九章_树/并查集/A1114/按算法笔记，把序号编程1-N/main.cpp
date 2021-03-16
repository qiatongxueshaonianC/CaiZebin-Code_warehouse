#include<stdio.h>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
const int maxn=10005;
struct Node{
	int member;
	double met,area;
}F[maxn];
int mp[maxn],harsh[maxn]; 
int isRoot[maxn],father[maxn],index=1;
vector<int> ans;
void change(int id){
	if(mp[id]==0) {
		mp[id]=index;
		harsh[index++]=id;
	}
}
int findFather(int a){
	if(father[a]==a) return a;
	int temp=findFather(father[a]);
	father[a]=temp;
	return temp;
}
void Union(int a,int b){
	int fa=findFather(a);
	int fb=findFather(b);
	if(fa!=fb){
		if(harsh[fa]<harsh[fb]) swap(fa,fb);
		father[fa]=fb;
	}
}
bool cmp(int a,int b){
	return F[a].area!=F[b].area?F[a].area>F[b].area:harsh[a]<harsh[b];
}
int main() {
	iota(father,father+maxn,0);
	int n,id,fa,ma,child,k;
	double met,area;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&id,&fa,&ma,&k);
		change(id);
		if(fa!=-1){
			change(fa);
			Union(mp[id],mp[fa]);
		}
		if(ma!=-1){
			change(ma);
			Union(mp[id],mp[ma]);
		}
		while(k--){
			scanf("%d",&child);
			change(child);
			Union(mp[id],mp[child]);
		}
		scanf("%lf%lf",&F[mp[id]].met,&F[mp[id]].area);
	}
	for(int i=1;i<index;i++){
		int fa=findFather(i);
			isRoot[fa]++;
			if(fa!=i){
				F[fa].met+=F[i].met;
				F[fa].area+=F[i].area;
			}
	}
	for(int i=1;i<index;i++){
		if(isRoot[i]!=0){
			F[i].member=isRoot[i];
			F[i].met/=isRoot[i];
			F[i].area/=isRoot[i];
			ans.push_back(i); 
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	printf("%d\n",ans.size());
	for(auto i:ans)
		printf("%04d %d %.3lf %.3lf\n",harsh[i],F[i].member,F[i].met,F[i].area);
	return 0;
}
/*
10
6666 5551 5552 1 7777 1 100
1234 5678 9012 1 0002 2 300
8888 -1 -1 0 1 1000
2468 0001 0004 1 2222 1 500
7777 6666 -1 0 2 300
3721 -1 -1 1 2333 2 150
9012 -1 -1 3 1236 1235 1234 1 100
1235 5678 9012 0 1 50
2222 1236 2468 2 6661 6662 1 300
2333 -1 3721 3 6661 6662 6663 1 100
*/
