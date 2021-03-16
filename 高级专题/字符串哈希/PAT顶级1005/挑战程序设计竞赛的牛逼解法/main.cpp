#include<bits/stdc++.h>
using namespace std; 
typedef unsigned long long uLL;
const int MOD=1e9+7;
const int P=1e8+7;
const int maxn=1048576+5;
//unordered_map<uLL,int> mp;
int mp[10000100];
string s; 
int main() {
	std::ios::sync_with_stdio(false); 
	int len;
	cin>>len;cin.ignore(1,'\n');
	getline(cin,s);
	uLL M=1,sub=0;
	for(int i=0;i<len;i++){
		M*=P;
		sub=sub*P+s[i];
	}
	vector<int> idx;
	int Max=0;
	for(int i=0;i+len<=s.size();i++){
		int times=++mp[sub%10000007];
		if(times>Max){
			Max=times;
			idx.clear();
			idx.push_back(i);
		}else if(times==Max){
			idx.push_back(i);
		}
		if(i+len<s.size())
			sub=sub*P+s[i+len]-s[i]*M;
	}
	string ans=s.substr(idx[0],len);
	for(int i=1;i<idx.size();i++)
		ans=min(ans,s.substr(idx[i],len));
	cout<<ans<<' '<<Max;
	return 0;
}
/*
4
//A can can can a can.

3
int a=~~~~~~~~~~~~~~~~~~~~~0;
*/
