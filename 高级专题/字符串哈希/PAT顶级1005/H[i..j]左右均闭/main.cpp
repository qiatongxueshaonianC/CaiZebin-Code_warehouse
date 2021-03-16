#include<bits/stdc++.h>
using namespace std; 
const int P=1e7+19;
typedef unsigned long long uLL;
const int maxn=1048576+5;
uLL powP[maxn],H[maxn];
unordered_map<uLL,int> mp;
string s; 
void init(){
	powP[0]=1;
	H[0]=s[0];
	for(int i=1;i<s.size();i++){	//注意，这里i是从1开始 
		powP[i]=powP[i-1]*P;
		H[i]=H[i-1]*P+s[i];
	}
}
uLL calsubH(uLL H[],int i,int j){
	if(i==0)
		return H[j];
	return H[j]-H[i-1]*powP[j-i+1];
}
int main() {
	std::ios::sync_with_stdio(false); 
	int len;
	cin>>len;cin.ignore(1,'\n');
	getline(cin,s);
	init();
	vector<int> idx;
	int Max=0;
	for(int i=0;i+len-1<s.size();i++){
	//	printf("%s\n",s.substr(i,len).c_str());
		uLL sub=calsubH(H,i,i+len-1);
	//	cout<<s.substr(i,len)<<' '<<sub<<endl;
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
