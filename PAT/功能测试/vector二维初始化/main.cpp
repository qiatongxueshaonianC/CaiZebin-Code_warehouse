#include<bits/stdc++.h>
using namespace std;
vector<set<pair<int,int>>> vect;
unordered_map<int,set<pair<int,int>>::iterator> mp; 
int main() {
	int n;
	cin>>n; 
	vector<vector<int>> v(n);
	fill(v.begin(),v.end(),vector<int>(10)); 
	cout<<v.size()<<endl;
	for(int i=0;i<7;i++){
		for(int j=0;j<7;j++)
			v[i].push_back(j);
	}
	cout<<endl<<endl;
	cout<<v.size()<<','<<v[1].size()<<endl;
	for(auto i:v){
		for(auto j:i)
			printf("%d ",j);
		puts("");
	}
	return 0;
}
