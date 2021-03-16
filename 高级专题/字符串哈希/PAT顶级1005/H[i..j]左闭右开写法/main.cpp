#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std; 
const int MOD=1e9+7;
const int P=1e7+19;
typedef long long LL;
const int maxn=1048576+5;
LL powP[maxn],H[maxn];
//gp_hash_table<LL,int> mp; 		//内存超限 
unordered_map<LL,int> mp; 
string s;
void init(){
	powP[0]=1;
	for(int i=1;i<=s.size();i++){
		powP[i]=(powP[i-1]*P)%MOD;
		H[i]=(H[i-1]*P+s[i-1])%MOD;	// 左闭右开写法 
	}
}
LL calsubH(LL H[],int i,int j){  //表示求H[i,i+1...j-1]的哈希值  此写法左闭右开 
	return ((H[j]-H[i]*powP[j-i])%MOD+MOD)%MOD;
}
int main() {
	int len;
	cin>>len;cin.ignore();
	getline(cin,s);
	init();
	vector<int> idx;
	int Max=0;
	for(int i=0;i+len<=s.size();i++){
		LL sub=calsubH(H,i,i+len);
		int times=++mp[sub]; 
		if(times>Max){
			Max=times;
			idx.clear();
			idx.push_back(i);
		}else if(times==Max){
			idx.push_back(i);
		}
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
