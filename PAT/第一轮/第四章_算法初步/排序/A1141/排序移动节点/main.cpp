#include<bits/stdc++.h>
using namespace std; 
const int maxn=1e5+1;
struct Node{
	string name;
	int sa,sb,st,ns,tws;
	Node(){
		sa=sb=st=ns=tws=0;
	}
}A[maxn];
unordered_map<string,int> mp;
bool cmp(Node a,Node b){
	if(a.tws!=b.tws) return a.tws>b.tws;
	else if(a.ns!=b.ns) return a.ns<b.ns;
	else return a.name<b.name;
}
int main() {
	int n,score,index=0;
	char id[10],school[10];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s %d %s",&id,&score,&school);
		string s(school);
		transform(s.begin(),s.end(),s.begin(),::tolower);
		if(mp.find(s)==mp.end()){
			mp[s]=index++;
		}
		int addr=mp[s];
		A[addr].name=s;
		A[addr].ns++;
		if(id[0]=='A') A[addr].sa+=score;
		else if(id[0]=='B') A[addr].sb+=score;
		else A[addr].st+=score;
	}
	for(int i=0;i<index;i++){
		A[i].tws=(A[i].sa+A[i].sb/1.5+A[i].st*1.5);
	}
	sort(A,A+index,cmp);
	printf("%d\n",index);
	printf("1 %s %d %d\n",A[0].name.c_str(),A[0].tws,A[0].ns);
	int rank=1;
	for(int i=1;i<index;i++){
		rank=A[i].tws==A[i-1].tws?rank:i+1;
		printf("%d %s %d %d\n",rank,A[i].name.c_str(),A[i].tws,A[i].ns);
	}
	return 0;
}
/*
10
A57908 85 Au
B57908 54 LanX
A37487 60 au
T28374 67 CMU
T32486 24 hypu
A66734 92 cmu
B76378 71 AU
A47780 45 lanx
A72809 100 pku
A03274 45 hypu
*/
