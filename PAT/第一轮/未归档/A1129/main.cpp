#include<bits/stdc++.h>
using namespace std; 
const int maxn=50010;
int harsh[maxn];
struct cmp{
	bool operator ()(int a,int b){
		return harsh[a]!=harsh[b]?harsh[a]>harsh[b]:a<b;
	}
};
int main() {
	set<int,cmp> st;
	int n,k,v;
	scanf("%d%d",&n,&k);
	scanf("%d",&v);
	harsh[v]++;
	st.insert(v);
	for(int i=1;i<n;i++){
		int idx=0;
		scanf("%d",&v);
		printf("%d:",v);
	//	harsh[v]++;     //在这里harsh[v]++会出错的！！！卡了一个多小时！！！ 
		for(auto i:st){
			printf(" %d",i);
			if(++idx==k) break;
		}
		puts("");
		st.erase(v);
		harsh[v]++;   //天啊！！！！2019/12/3/19：30发现，要在这里进行harsh[v]++; 
		st.insert(v);  //不知道是否会自动调整 
	}
	return 0;
}
/*
12 3
3 5 7 5 5 3 2 1 8 3 8 12
*/
