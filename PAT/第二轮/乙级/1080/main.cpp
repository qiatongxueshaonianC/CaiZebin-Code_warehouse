#include<bits/stdc++.h>
using namespace std; 
struct Node{
	string id;
	int p,mid,fin,G;
	Node(){
		p=mid=fin=G=-1;
	}
}A[10010];
bool cmp(Node a,Node b){
	if(a.G!=b.G) return a.G>b.G;
	else return a.id<b.id;
}
int main() {
	int P,N,M,idx=0,score;
	map<string,int> mp;
	scanf("%d%d%d",&P,&N,&M);
	string s; 
	while(P--){
		cin>>s>>score;
		if(score<200) continue;
		mp[s]=idx++;
		A[idx-1].id=s;
		A[idx-1].p=score;
	}
	for(int i=0;i<2;i++){
		N=i==0?N:M;
		while(N--){
			cin>>s>>score;
			if(mp.find(s)==mp.end()) continue;
			if(i==0) A[mp[s]].mid=score;
			else{
				int temp=mp[s];
				A[temp].fin=score;
				A[temp].G=score>=A[temp].mid?score:(int)round(score*0.6+A[temp].mid*0.4);
			}
		}	
	}
	sort(A,A+idx,cmp);
	for(int i=0;i<idx;i++){
		if(A[i].G<60) continue; 
		printf("%s %d %d %d %d\n",A[i].id.c_str(),A[i].p,A[i].mid,A[i].fin,A[i].G);
	}
	return 0;
}
/*
6 6 7
01234 880
a1903 199
ydjh2 200
wehu8 300
dx86w 220
missing 400
ydhfu77 99
wehu8 55
ydjh2 98
dx86w 88
a1903 86
01234 39
ydhfu77 88
a1903 66
01234 58
wehu8 84
ydjh2 82
missing 99
dx86w 81
*/
