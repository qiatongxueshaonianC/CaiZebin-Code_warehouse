#include<bits/stdc++.h>
using namespace std; 
const int maxn=100010;
struct Node{
	string id;
	int seat;
}A[maxn];
int main() {
	int n,seat,tseat;
	string id;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>id>>tseat>>seat;
		A[tseat].id=id;
		A[tseat].seat=seat;
	}
	scanf("%d",&n);
	while(n--){
		scanf("%d",&tseat);
		printf("%s %d%s",A[tseat].id.c_str(),A[tseat].seat,n==0?"":"\n");
	} 
	return 0;
}
/*
4
3310120150912233 2 4
3310120150912119 4 1
3310120150912126 1 3
3310120150912002 3 2
2
3 4
*/
