#include<bits/stdc++.h>
using namespace std;
vector<set<pair<int,int>>> vect(1);
set<pair<int,int>> t;
unordered_map<int,set<pair<int,int>>::iterator> mp; 
int main() {
	for(int i=0;i<3;i++){
		vect[0].insert({i,2*i});
		t.insert({i,2*i});
	}
	set<pair<int,int>>::iterator it=vect[0].begin();
	for(int i=0;i<vect[0].size();i++){
		mp.insert({i,it});
		++it;
	}
	for(int i=0;i<vect[0].size();i++){
		cout<<mp[i]->first<<','<<mp[i]->second<<endl;
	}
	vect[0].erase(vect[0].find({1,2}));
	set<pair<int,int>>::iterator tp=vect[0].begin();
	for(int i=0;i<vect[0].size();i++){
		cout<<tp->first<<','<<tp->second<<endl;
		tp++;
	}
	return 0;
}
