#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
int n,v,ans_num;
vector<int> init,seq; 
set<vector<int>>ans;
stack<int> st;
void output(vector<int> a){
	for(auto i:a)
		printf("%d ",i);
	puts("");
}
void DFS(pair<int,int> &count){
	if(seq.size()==2*n){
		ans_num++;
		int j=0;
		vector<int> temp;
		for(auto i=seq.begin();i!=seq.end();i++){
			if(*i==1) st.push(init[j++]);
			else{
				temp.push_back(st.top());
				st.pop();
			}
		}
		ans.insert(temp);
	}
	if(count.first>=1){
		seq.push_back(1);
		count.first--;
		DFS(count);
		seq.pop_back();
		count.first++; 
	}
	if(count.second>=1&&count.second>count.first){  //剩下了的多 
		seq.push_back(0);
		count.second--;
		output(seq);
		DFS(count);
		seq.pop_back();
		count.second++;
	}
}
int main() {
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		init.push_back(v);
	}
	pair<int,int> count={n-1,n};
	seq.push_back(1);
	DFS(count);
	printf("%d\n",ans_num);
	for(auto i:ans){
		for(auto j=i.begin();j!=i.end();j++)
			printf("%d%s",*j,j!=--i.end()?" ":"\n");
	}
	return 0;
}
/*
4
1 2 3 4

2
1 2
*/
