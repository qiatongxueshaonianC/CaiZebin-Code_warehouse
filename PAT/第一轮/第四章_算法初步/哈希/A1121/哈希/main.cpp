#include<bits/stdc++.h>
using namespace std; 
int harsh[1000000];
bool Exist[1000000];
int main() {
	int n,u,v,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&u,&v);
		harsh[u]=v;
		harsh[v]=u;
	}
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&u);
		if(Exist[harsh[u]]==true){
			Exist[harsh[u]]=false;
			ans--;
		}else{
			Exist[u]=true;
			ans++;
		}
	}
	printf("%d\n",ans);
	for(int i=0;i<1000000;i++){
		if(Exist[i]==true)
			printf("%05d%s",i,--ans==0?"\n":" ");
		if(ans==0) break;
	}
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
