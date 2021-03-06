#include<bits/stdc++.h>
using namespace std; 
int n,Sum,value;
vector<int> ori,ans;
bool flag;
void DFS(int index,int sumc){
	if(flag) return;
	if(sumc==Sum){
		for(int i=0;i<ans.size();i++)
			printf("%d%s",ans[i],i==ans.size()-1?"\n":" ");
		flag=true;
		return;
	}
	if(sumc+ori[index]<=Sum){  //因为ori是从小到大有序排列的 
		ans.push_back(ori[index]);  //放 
		DFS(index+1,sumc+ans.back());
		ans.pop_back(); //不放
		DFS(index+1,sumc); 
	}	
}
int main() {
	scanf("%d%d",&n,&Sum);
	ori.resize(n);
	for(int i=0;i<n;i++)
		scanf("%d",&ori[i]);
	sort(ori.begin(),ori.end());
	DFS(0,0);
	if(!flag)
		puts("No Solution");
	return 0;
}
/*
8 9
5 9 8 7 2 3 4 1

4 8
7 2 4 3
*/
