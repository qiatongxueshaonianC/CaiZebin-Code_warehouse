#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int harsh[maxn];
int main() {
	int N,M,a,b;
	scanf("%d",&N); 
	for(int i=0;i<N;i++){
		scanf("%d%d",&a,&b);
		harsh[a]=b;
		harsh[b]=a;
	}
	scanf("%d",&M);
	set<int> st;
	for(int i=0;i<M;i++){
		scanf("%d",&a);
		set<int>::iterator it=st.find(harsh[a]);
		if(it==st.end())
			st.insert(a);
		else
			st.erase(it);
	}
	printf("%d\n",st.size());
	for(auto i:st)
		printf("%05d%s",i,i==*(--st.end())?"":" ");
	return 0;
}
/*
3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333
*/
