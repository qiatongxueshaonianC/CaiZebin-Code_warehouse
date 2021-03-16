#include<bits/stdc++.h>
using namespace std; 
int main() {
	int n,ans=0;
	string s;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		s=to_string(i);
		int k=0,j=0;
		while(k!=string::npos){
			k=s.find('1',j);
			if(k!=string::npos){
				ans++;
				j=k+1;
			}else break;
		}
	}
	printf("%d\n",ans);
	return 0;
}

