#include<bits/stdc++.h>
using namespace std; 
const int maxn=100010;
int harsh[maxn];
int main() {
	int n,id,score;
	pair<int,int> ans{0,0};
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&id,&score);
		harsh[id]+=score;
		if(harsh[id]>ans.second){
			ans.second=harsh[id];
			ans.first=id;
		}
	}
	printf("%d %d",ans.first,ans.second);
	return 0;
}
/*
6
3 65
2 80
1 100
2 70
3 40
3 0
*/
