#include<bits/stdc++.h>
using namespace std;
const int maxn=3010;
struct Node{
	string name;
	int weight,id,tolvalue;
	Node(string a,int b,int c){
		name=a;
		weight=b;
		id=c;
		tolvalue=weight;
	}
	Node(){}
};
map<string,Node> mp;
map<int,string> ITOS;
map<string,int> NaToNum;
vector<pair<string,string>> iput;
int isroot[maxn]={false},father[maxn];
int findFather(int x){
	if(father[x]==x)
		return x;
	int temp=findFather(father[x]);
	father[x]=temp;
	return temp;
}
void Union(string a,string b){
	int fa=findFather(mp[a].id);
	int fb=findFather(mp[b].id);
	if(fa!=fb){
		mp[a].weight>mp[b].weight?father[fb]=fa:father[fa]=fb;
		mp[a].weight>mp[b].weight?mp[a].tolvalue+=mp[b].tolvalue:mp[b].tolvalue+=mp[a].tolvalue;
	}
}
void init(){
	for(int i=1;i<=maxn;i++)
		father[i]=i;
}
int main() {
	init();
	int n,k,w,ans,numperson=0;
	string s1,s2;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		cin>>s1>>s2>>w;
		iput.push_back(make_pair(s1,s2));
		if(mp.find(s1)==mp.end()){
			numperson++;
			Node node(s1,w,numperson);
			mp[s1]=node;
			ITOS[numperson]=s1;
		}	
		else {
			mp[s1].weight+=w;
			mp[s1].tolvalue+=w;
		}
		if(mp.find(s2)==mp.end()){
			numperson++;
			Node node(s2,w,numperson);
			mp[s2]=node;
			ITOS[numperson]=s2;
		}
		else {
			mp[s2].weight+=w;
			mp[s2].tolvalue+=w;
		}
	}
	for(auto i:iput){
		Union(i.first,i.second);
	}
	for(int i=1;i<=n;i++){
		isroot[findFather(i)]++;
	}
	for(int i=1;i<=n;i++){
		if(isroot[i]>2&&mp[ITOS[i]].tolvalue>2*k) {
			ans++;
			NaToNum[ITOS[i]]=isroot[i];
		}
	}
	printf("%d\n",ans);
	for(auto i:NaToNum){
		cout<<i.first<<" "<<i.second<<endl;
	}
	return 0;
}
/*
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
*/

/*
3 56
AAA BBB 10
BBB AAA 20
AAA CCC 40
*/
