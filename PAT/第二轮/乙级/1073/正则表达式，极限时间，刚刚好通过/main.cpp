#include<bits/stdc++.h>
using namespace std;
void Check(string s1,string s2,map<string,int>& F,int k){
	for(auto i:s1){
		if(s2.find(i)==string::npos){
			string temp=to_string(k);
			temp=temp+'-'+i;
			F[temp]++;
		}
	}
} 
int main() {
	int N,M,u,v;
	scanf("%d%d",&N,&M);
	vector<int> score(M);
	vector<string> ans(M);
	vector<double> Grade(N);
	string s;
	regex r("[^a-z,^A-Z,^\\)]"),r2("\\)");
	for(int i=0;i<M;i++){
		scanf("%d %d %d ",&score[i],&u,&v);
		getline(cin,s);
		s=regex_replace(s,r,"");
		ans[i]=s;
	}
	map<string,int> F;
	for(int i=0;i<N;i++){
		getline(cin,s);
		int k=s.rfind(")");
		s.erase(k);
		s=regex_replace(s,r,"");
		s=regex_replace(s,r2," ");
	//	puts(s.c_str());
		stringstream str(s);
		for(int k=0;str>>s;k++){
			if(s==ans[k])
				Grade[i]+=1.0*score[k];
			else if(s.find_first_not_of(ans[k])==string::npos){
				Grade[i]+=0.5*score[k];
				Check(ans[k],s,F,k+1);
			}else{
				Check(ans[k],s,F,k+1);
				Check(s,ans[k],F,k+1);
			}
		}
	} 
	for(auto i:Grade)
		printf("%.1lf\n",i);
	if(F.empty())
		puts("Too simple");
	else{
		vector<pair<string,int>> A;
		for(auto i:F)
			A.push_back(i);
		sort(A.begin(),A.end(),[](pair<string,int> u,pair<string,int> v){
			return u.second!=v.second?u.second>v.second:u.first<v.first;
		});
		int Max=A[0].second;
		for(auto i:A){
			if(i.second<Max) break;
			printf("%d %s\n",i.second,i.first.c_str());	
		}
	}
	return 0;
}
/*
3 4 
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (3 b d e) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (1 c) (4 a b c d)

2 2 
3 4 2 a c
2 5 1 b
(2 a c) (1 b)
(2 a c) (1 b)
*/
