#include<bits/stdc++.h>
using namespace std; 
const int maxn=100010;
int n,m;
//vector<int> w;
int main() {
	scanf("%d%d",&n,&m);
	int v,w[n];
	for(int i=0;i<n;i++){
		scanf("%d",&w[i]);
	}
	sort(w,w+n);
	bool flag=false;
	for(int i=0;i<n-1;i++){
		int val=m-w[i];
		auto lowpos=lower_bound(w+i+1,w+n,val);
	//����д if(lowpos-w!=n)��Ϊ��һ�����ڵ��ڣ���һ���ص���� 
		if(w[lowpos-w]==val){
			printf("%d %d",w[i],w[lowpos-w]);
			flag=true;
			break;
		}
	}
	if(!flag) puts("No Solution");
	return 0;
}
/*
8 15
1 2 8 7 2 4 11 15

7 14
1 8 7 2 4 11 15
*/
