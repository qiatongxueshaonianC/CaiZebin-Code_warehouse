#include<bits/stdc++.h>
using namespace std; 
struct Node{
	string id;
	int score,Rank[2],loc;
	Node(string a,int b,int c):id(a),score(b),loc(c){}
	bool friend operator <(Node u,Node v){
		return u.score!=v.score?u.score>v.score:u.id<v.id;
	}
}; 
vector<Node> ans;
//set<Node> ans;  //刚开始用set，发现无法修改set中的元素，于是改用vector 
void calRank(vector<Node> &st,int flag){
	int rank=1,num_person=1;
	auto pre=st.begin();
	pre->Rank[flag]=rank;
	for(auto i=++st.begin();i!=st.end();i++){
		if(i->score==pre->score){
			i->Rank[flag]=rank;
			num_person++;
		} 
		else{
			i->Rank[flag]=++num_person;
			rank=num_person;
			pre=i;
		}	
	}
}
int main() {
	int n,k,score;
	string id;
	scanf("%d",&n);
	for(int l=1;l<=n;l++){
		scanf("%d",&k);
		vector<Node> temp;
		for(int i=0;i<k;i++){
			cin>>id>>score;
			temp.push_back(Node(id,score,l));
		}
		sort(temp.begin(),temp.end());
		calRank(temp,0);
		for(auto i:temp)   //合并集合 
			ans.push_back(i);
	}
	sort(ans.begin(),ans.end());
	calRank(ans,1);
	printf("%d\n",ans.size());
	for(auto i:ans)
		printf("%s %d %d %d\n",i.id.c_str(),i.Rank[1],i.loc,i.Rank[0]);
	return 0;
}
/*
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
*/
