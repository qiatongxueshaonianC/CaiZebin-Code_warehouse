#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
struct Node{
	int member,flag; //不记录id则不要改变F数组原来的顺序；使用id是为了之后排序，依赖下标就会使id错乱 
	double met,area;
	Node():met(0),area(0),member(1),flag(-1){}
}F[maxn];
int father[maxn];
bitset<maxn> harsh; 
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
		if(fa<fb) swap(fa,fb);
		father[fa]=fb;
	}
}
bool cmp(int a,int b){
	return F[a].area!=F[b].area?F[a].area>F[b].area:a<b;
}
int main() {
	iota(father,father+maxn,0);
	int n,id,fa,ma,k,child;
	double met,area;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&id,&fa,&ma,&k);
		if(fa!=-1)	Union(id,fa);
		if(ma!=-1)	Union(id,ma);
		while(k--){
			scanf("%d",&child);
			Union(id,child);
		}
		scanf("%lf%lf",&F[id].met,&F[id].area);
		F[id].flag=1;   //设为有效节点 
	}
	vector<int> ans;
	for(int i=0;i<maxn;i++){  //不记录id则不要改变F数组原来的顺序 
		int fa=findFather(i);
		if(fa!=i){
			F[fa].met+=F[i].met;
			F[fa].area+=F[i].area;
			F[fa].member++;  //成员加一
			F[fa].flag=1;  //将父节点设为有效节点 
		}
		if(F[fa].flag==-1) continue;//无效节点 
		if(harsh[fa]==0){
			ans.push_back(fa);
			harsh[fa]=1;	
		}
	}
//	sort(ans.begin(),ans.end());  //为了让值相同的都凑到一块 
//	auto it=unique(ans.begin(),ans.end());  //去重 
//	ans.erase(it,ans.end());
	for(auto &i:ans){
		F[i].met/=F[i].member;  
		F[i].area/=F[i].member;
	}
	sort(ans.begin(),ans.end(),cmp);
	printf("%d\n",ans.size());
	for(auto i:ans)
		printf("%04d %d %.3lf %.3lf\n",i,F[i].member,F[i].met,F[i].area);
	return 0;
}
/*
2
1 2 3 1 4 1 100
5 6 7 1 8 2 300

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

10
01 02 03 1 04 1 100
05 06 07 1 08 2 300
09 -1 -1 0 1 1000
10 11 12 1 13 1 500
04 01 -1 0 2 300
14 -1 -1 1 15 2 150
07 -1 -1 3 16 17 05 1 100
17 06 07 0 1 50
13 16 10 2 18 19 1 300
15 -1 14 3 18 19 20 1 100
*/
