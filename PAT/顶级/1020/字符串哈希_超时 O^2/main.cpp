//#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long uLL; 
const int maxn=1e6+5;
const int P=1e7+19;
const int MOD=1e9+7;
uLL H[maxn],powP[maxn];
unordered_set<uLL> st; 
string s;
void init(){
	powP[0]=1;
	H[0]=s[0]; 
	for(int i=1;i<s.size();i++){
		powP[i]=powP[i-1]*P;
		H[i]=H[i-1]*P+s[i];	
	}
}
uLL calsubH(uLL H[],int i,int j){
	if(i>j)
		return 0;
	if(i==0)
		return H[j];
	return (H[j]-H[i-1]*powP[j-i+1]);
}
int main(){
	std::ios::sync_with_stdio(false);
	getline(cin,s);
	init();
	uLL ans=2;
	for(int i=1;i<s.size();i++){
		if(s[i]!=s[i-1])
			ans++;
	}
	for(int i=0;i<s.size();i++){		//0~i-1一共有i个数，后面还要扣掉两个 
		uLL L=calsubH(H,0,i-1)*powP[s.size()-(i)-2]; 
		for(int j=i+1;j<s.size();j++){
			uLL Mid=calsubH(H,i+1,j-1)*powP[s.size()-(j+1)];	//0~j一共有j+1个数，后面 
			uLL R=calsubH(H,j+1,s.size()-1);
			uLL A=L+Mid+R;
			st.insert(A);
		//	string temp=s.substr(0,i)+s.substr(i+1,j-i-1)+s.substr(j+1);
		//	cout<<temp<<' '<<A<<endl;
		} 
	}
	cout<<ans+st.size();
	return 0;
}
/*
ababcc
*/
