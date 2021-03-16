#include<bits/stdc++.h>
using namespace std; 
int main() {
	int n;
	scanf("%d",&n);
	int ori[n],fin[n],temp[n];
	for(int i=0;i<n;i++)
		scanf("%d",&ori[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&fin[i]);
	bool flag=false;
	memcpy(temp,ori,sizeof(ori));
	for(int i=2;i<=n;i++){
		sort(temp,temp+i);
		if(flag){
			puts("Insertion Sort");
			break;
		}
		flag=equal(temp,temp+n,fin)?1:0;
	}
	if(flag==false){
		memcpy(temp,ori,sizeof(ori));
		puts("Merge Sort");
		for(int step=2;step<=n;step*=2){
			for(int i=0;i<n;i+=step)
				sort(temp+i,temp+min(i+step,n));
			if(flag)
				break;
			flag=equal(temp,temp+n,fin)?1:0;
		}
	}
	for(int i=0;i<n;i++)
		printf("%d%s",temp[i],i==n-1?"\n":" ");
	return 0;
}
/*
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0

10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
*/
