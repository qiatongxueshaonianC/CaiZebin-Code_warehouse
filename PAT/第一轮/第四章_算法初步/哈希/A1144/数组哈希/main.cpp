#include<bits/stdc++.h>
using namespace std; 
const int maxn=100010;
bool harsh[maxn];
int main() {
	int n,v;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		if(v<0||v>maxn) continue; //2019/15/5/0��27���ָ��� 
		harsh[v]=true;				//ע�⣬����������ܻ����maxn���������ƻ�δ���  
	}
	for(int i=1;i<maxn;i++){
		if(harsh[i]==false){
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}
/*
10
5 -25 9 6 1 3 4 2 5 17
*/
