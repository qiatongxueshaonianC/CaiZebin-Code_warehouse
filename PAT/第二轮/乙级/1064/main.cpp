#include<bits/stdc++.h>
using namespace std; 
int main() {
	map<int,int> mp;
	int n,a,ans;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		ans=0;
		scanf("%d",&a);
		do{
			ans+=a%10;
			a/=10;
		}while(a!=0);
		mp[ans]++;
	}
	printf("%d\n",mp.size());
	for(auto i:mp)
		printf("%d%s",i.first,i==*(--mp.end())?"":" ");
	return 0;
}
/*
8
123 899 51 998 27 33 36 12
*/
