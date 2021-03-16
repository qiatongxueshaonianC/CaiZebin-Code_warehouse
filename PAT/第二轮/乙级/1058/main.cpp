#include<bits/stdc++.h>
using namespace std; 
int main() {
	int N,M,score,temp,Max=0;
	scanf("%d%d",&N,&M);
	vector<pair<string,int>> A(M+1);
	vector<int> False(M,0);
	string s,test;
	char a[20];
	bool simple=true;
	for(int i=0;i<M;i++){
		scanf("%d %d ",&score,&temp);
		getline(cin,s);
	//	puts(s.c_str());
		A[i]={s,score};
	}
	for(int i=0;i<N;i++){
		score=0;
		getline(cin,s);
		int l=0,r=0;
		for(int j=0;j<M;j++){
			l=s.find_first_of('(',l);
			r=s.find_first_of(')',r+1);
			test=s.substr(l+1,r-l-1);
			l=r+1;r=r+1;
		//	puts(test.c_str());
			if(A[j].first==test)
				score+=A[j].second;
			else{
				False[j]++;
				simple=false;
				Max=max(Max,False[j]);
			}	
		}
		printf("%d\n",score);
	}
	if(simple) puts("Too simple");
	else{
		printf("%d",Max);
		for(int i=0;i<M;i++)
			if(False[i]==Max)
				printf(" %d",i+1);	
	}
	return 0;
}
/*
3 4 
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (2 b d) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (2 b c) (4 a b c d)
*/
