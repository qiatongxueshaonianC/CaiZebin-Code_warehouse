#include<bits/stdc++.h>
using namespace std; 
int main() {
	int n,v;
	vector<int> A;
	unordered_map<int,int> mp;  //���У�set�е����ݺͶ����˳��һ�� ��unorder_mapҲ�� 
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		A.push_back(v);
		if(mp.find(v)!=mp.end()) mp[v]++;
		else mp[v]=1;
	}
	bool flag=false;
	for(auto i:A){
		if(mp[i]==1){
			printf("%d\n",i);
			flag=true;
			break;
		}
	}
	if(!flag) puts("None");
	return 0;
}
/*
7 5 31 5 88 67 88 17

5 888 666 666 888 888
*/
