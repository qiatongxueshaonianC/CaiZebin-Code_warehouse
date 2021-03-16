#include<bits/stdc++.h>
using namespace std; 
int main() {
	int n,ans=0;
	scanf("%d",&n);
	int pos[n],v,index=0;;
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		pos[v]=i;
	}
	while(1){
		bool flag=false;
		if(pos[0]==0){
			for(index;index<n;index++){
				if(pos[index]!=index){
					swap(pos[index],pos[0]);
					ans++;
					break;
				}
			}
		}
		while(pos[0]!=0){
			swap(pos[0],pos[pos[0]]);
			ans++;
			flag=true;
		}
		if(flag==false)
			break;
	}
	printf("%d\n",ans);
	return 0;
}
/*
10
3 5 7 2 6 4 9 0 8 1

10
0 1 2 3 4 5 6 7 8 9
*/
