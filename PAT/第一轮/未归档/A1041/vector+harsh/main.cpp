#include<bits/stdc++.h>
using namespace std; 
int main() {
	int harsh[10005],n,v;
	vector<int> st;
//	unordered_set<int> st;  //���У�set�е����ݺͶ����˳��һ�� ��unorder_mapҲ�� 
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		st.push_back(v);
		harsh[v]++;
	}
	bool flag=false;
	for(auto i:st){
		if(harsh[i]==1){
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
