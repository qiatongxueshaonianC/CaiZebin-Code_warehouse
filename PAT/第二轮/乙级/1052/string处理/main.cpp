#include<bits/stdc++.h>
using namespace std; 
int main() {
	string s; 
	vector<string> A[3];
	for(int i=0;i<3;i++){
		getline(cin,s);
		int k=s.find_last_of(']'),j;
		s.erase(k);
		k=s.find_first_of("[]");
		while(k!=string::npos){
			s[k]=' ';
			j=k+1;
			k=s.find_first_of("[]");
		}
	//	puts(s.c_str());
		stringstream str(s);
		while(str>>s)
			A[i].push_back(s);
	}
	int n,a,b,c,d,e;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
		if(A[0].size()<a||A[1].size()<b||A[2].size()<c||A[1].size()<d||A[0].size()<e||
		a<1||b<1||c<1||d<1){   //2020/1/25/0:24发现，这里还要加上判断是否小于1 
			puts("Are you kidding me? @\\/@");
			continue;
		}
		else
			s=A[0][a-1]+'('+A[1][b-1]+A[2][c-1]+A[1][d-1]+')'+A[0][e-1];
		puts(s.c_str());
	}
	return 0;
}
/*
[╮][╭][o][~\][/~]  [<][>]
 [╯][╰][^][-][=][>][<][@][⊙]
[Д][▽][_][ε][^]  ...
4
1 1 2 2 2
6 8 1 5 5
3 3 4 3 3
2 10 3 9 3
*/
