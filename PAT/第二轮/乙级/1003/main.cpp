#include<bits/stdc++.h>
using namespace std; 
int main() {
	int N;
	string s;
	scanf("%d%*c",&N);
	while(N--){
		getline(cin,s);
		if(s.find_first_not_of("PAT")!=string::npos||s.find('A')==string::npos){
			puts("NO");
			continue;	
		}
		int l=s.find('P');
		int R=s.find('T');
		if(l==string::npos||R==string::npos||l>R)
			puts("NO");
		else if(s.find('P',l+1)!=string::npos||s.find('T',R+1)!=string::npos)
			puts("NO");
		else{
			s[l]=s[R]=' ';
			stringstream str(s);
			string s1,s2,s3;
			str>>s1;str>>s2;str>>s3;
			if(s1.size()*s2.size()==s3.size())
				puts("YES");
			else
				puts("NO");
		}
	} 
	return 0;
}
/*
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA
*/
