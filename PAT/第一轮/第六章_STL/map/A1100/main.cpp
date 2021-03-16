#include<bits/stdc++.h>
using namespace std; 
string s1="tret jan feb mar apr may jun jly aug sep oct nov dec";
string s2="tam hel maa huh tou kes hei elo syy lok mer jou";
unordered_map<string,int> Stoi;
vector<pair<string,string>> itos;
void init(){
	stringstream val(s1),v(s2);
	string temp;
	for(int i=0;val>>temp;i++){
		Stoi.insert({temp,i});
		itos.push_back({"",temp}); 
	}
	auto it=itos.begin();
	for(int i=13;v>>temp;i+=13){
		Stoi.insert({temp,i});
		it++;
		it->first=temp;
	}
}
int main() {
	init();
	int n;
	scanf("%d%*c",&n);   //getline(cin,s)认回车，所以要吃掉一个回车符 
	string s;
	for(int i=0;i<n;i++){
		getline(cin,s);
		if('0'<=s[0]&&s[0]<='9'){
			int v=stoi(s);
			int u,w;
			u=v/13;
			w=v%13;
			//这么写不容易错：
			if(u!=0) printf("%s",itos[u].first.c_str());
			if(u!=0&&w!=0) printf(" ");
			if(!(u!=0&&w==0)) printf("%s",itos[w].second.c_str()); 
			puts("");
		//	printf("%s%s%s\n",itos[u].first.c_str(),u!=0&&w!=0?"":" ",u!=0&&w==0?"":itos[w].second.c_str()); 
		//2019年10月24日18：41发现错误，只有当高、低位均不为0时才输出空格 
		//	cout<<itos[u].first<<' '<<itos[w].second<<endl;
		}else{
			stringstream val(s);
			int ans=0;
			string u;
			while(val>>u){
				ans+=Stoi[u];
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
/*
4
29
5
elo nov
tam
*/
