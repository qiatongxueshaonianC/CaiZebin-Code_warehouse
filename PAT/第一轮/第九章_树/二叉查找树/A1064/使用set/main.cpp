#include<bits/stdc++.h>
using namespace std; 
const int maxn=1010;
struct Node{
	int data,left,right;
	Node(){
		left=right=-1;
	}
}Tree[maxn]; 
int n;
set<int> st;
void create(int s){
	if(s>n) return;
	create(2*s);
	if(Tree[s].left==Tree[s].right){ //˵��һ����Ҷ�ӽڵ� 
		Tree[s].data=*st.begin();
		st.erase(st.begin()); 
	}
	create(2*s+1);
}
int main() {
	int v;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		st.insert(v);   //����set����ζ������û���ظ����� 
	}
	create(1);
	for(int i=1;i<=n;i++)
		printf("%d%s",Tree[i].data,i<n?" ":"");
	return 0;
}
/*
10
1 2 3 4 5 6 7 8 9 0
*/

