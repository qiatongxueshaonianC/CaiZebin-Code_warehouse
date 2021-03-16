#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<double,double> a,pair<double,double> b){
	return	a.second/a.first>b.second/b.first;
}
int main() {
	int n,need;
	scanf("%d%d",&n,&need); 
	vector<pair<double,double>> A(n);
	for(int i=0;i<n;i++)
		scanf("%lf",&A[i].first);
	for(int i=0;i<n;i++)
		scanf("%lf",&A[i].second);
	sort(A.begin(),A.end(),cmp);
	double ans=0;
	for(int i=0;i<n&&need>0;i++){
		if(need>A[i].first){
			ans+=A[i].second;
			need-=A[i].first;
		}else{
			ans+=(need/A[i].first*A[i].second);
			need=0;
		}
	}
	printf("%.2lf",ans);
}
/*
3 20
18 15 10
75 72 45
*/
