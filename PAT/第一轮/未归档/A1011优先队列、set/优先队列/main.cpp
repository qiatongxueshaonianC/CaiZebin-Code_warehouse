#include<bits/stdc++.h>
using namespace std; 
int main() {
	string s="WTL",ans="";
	double money=1,a;
	for(int i=0;i<3;i++){
		priority_queue<pair<double,char>> q;
		for(int j=0;j<3;j++){
			scanf("%lf",&a);
			q.push(make_pair(a,s[j]));  
		}
		money*=q.top().first;
		ans=ans+q.top().second+' ';
	}
	money=(money*0.65-1)*2;
	printf("%s%.2lf",ans.c_str(),money);
	return 0;
}
/*
1.1 2.5 1.7
1.2 3.1 1.6
4.1 1.2 1.1
*/
