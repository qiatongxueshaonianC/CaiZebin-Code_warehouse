#include<bits/stdc++.h>
using namespace std;
vector<set<pair<int,int>>> vect;
unordered_map<int,set<pair<int,int>>::iterator> mp;
int main() {
	for(int i=0;i<10;i++){
		set<pair<int,int>> temp;
		vect.push_back(temp);
	}
	for(int i=0;i<3;i++){
		vect[i].insert({i,2*i});
	}
	set<pair<int,int>>::iterator it;
	for(int i=0;i<vect.size();i++){
		it=vect[i].begin();
		mp.insert({i,it});
		cout<<it->first<<','<<it->second<<endl;
	}
	cout<<endl<<endl;
	for(int i=0;i<vect.size();i++){
		cout<<mp[i]->first<<','<<mp[i]->second<<endl;
	}
	return 0;
}
