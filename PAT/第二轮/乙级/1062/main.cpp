#include<bits/stdc++.h>
using namespace std; 
int main() {
	int a,b,c,d,down;
	scanf("%d/%d %d/%d%d",&a,&b,&c,&d,&down);
	if(a*d>c*b){  //�ο�ѧ�����룬2020/1/24/21:33���ָ��������������a/b��һ����c/d��Ҫ�����ж� 
		swap(a,c);
		swap(b,d);
	}
	vector<pair<int,int>>ans;
	for(int i=a/b*down-1;i*d<c*down;i++){
		if(a*down<b*i&&__gcd(i,down)==1)
			ans.push_back({i,down});
	}
	for(auto i:ans)
		printf("%d/%d%s",i.first,i.second,i==ans[ans.size()-1]?"":" ");
	return 0;
}
/*
7/18 13/20 12

1/1000 2/1000 100
*/
