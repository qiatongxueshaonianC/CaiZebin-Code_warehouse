#include<bits/stdc++.h>
using namespace std; 
int n,Sum,value;
vector<int> ori,temp;
set<vector<int>> ans; 
void DFS(int index,int sumc){
	if(sumc==Sum){
		ans.insert(temp);
		return;
	}
	if(sumc+ori[index]<=Sum){  //因为ori是从小到大有序排列的 
		temp.push_back(ori[index]);  //放 
		DFS(index+1,sumc+temp.back());
		temp.pop_back(); //不放
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
	if(ans.empty())
		puts("No Solution");
	else{
		for(auto i:(*ans.begin())) 
			printf("%d%s",i,i==*(--(*ans.begin()).end())?"\n":" ");
	} 
	return 0;
}
/*
8 9
5 9 8 7 2 3 4 1

4 8
7 2 4 3
*/
