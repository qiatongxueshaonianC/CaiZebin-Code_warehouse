#include<bits/stdc++.h>
using namespace std; 
const int maxn=1048576+10;
int harsh[maxn];
int N,Max=0;
string s,temp; 
unordered_map<string,int> mp;
pair<string,int> ans{"",0};
int main() {
	scanf("%d%*c",&N);
	getline(cin,s);
	for(int i=0;(i+N*ans.second)<s.size();i++){
		if(harsh[i]==true)
			continue;
		temp=s.substr(i,N);
		mp[temp]=1;
		int j=i+1;
		int k=s.find(temp,j);
		while(k!=string::npos){
			mp[temp]++;
			harsh[j]=true;
			j=k+1;
			k=s.find(temp,j);
		}
		k=mp[temp];
		if(k>ans.second||(ans.second==k&&temp<ans.first)){
			ans.second=k;
			ans.first=temp;
		}
	}
	cout<<ans.first<<' '<<ans.second;
	return 0;
}
/*
4
//A can can can a can.

3
int a=~~~~~~~~~~~~~~~~~~~~~0;
*/
