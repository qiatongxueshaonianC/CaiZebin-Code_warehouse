#include<bits/stdc++.h>
using namespace std;
int main() {
	unordered_map<int,unordered_map<int,int>> mp;
	for(int i=0;i<5;i++){
		for(int j=0;j<i;j++){
			mp[i].insert(make_pair(j,2*j));
		}
	//	cout<<mp[i].first<<' '<<mp[i].second;
	} 
	for(auto i:mp){
		for(auto j:i.second){
			cout<<i.first<<','<<j.first<<','<<j.second<<endl;
		}
	}
	cout<<endl<<endl;
	for(int i=0;i<mp.size();i++){
		for(auto j:mp[i]){
			cout<<i<<','<<j.first<<','<<j.second<<endl;
		}
	}
	return 0;
}
