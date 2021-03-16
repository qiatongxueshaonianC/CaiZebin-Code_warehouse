#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,wolflier=0,lier=0;
	vector<pair<int,int>> Ans;
	scanf("%d",&n);
	vector<int> A(n+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]);
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			wolflier=lier=0;
			for(int k=1;k<=n;k++){
				int temp=abs(A[k]);
				if(A[k]>0&&temp!=i&&temp!=j) continue;
				if(A[k]<0&&(temp==i||temp==j)) continue;
				lier++;
				if(k==i||k==j) wolflier++;
			}
			if(lier==2&&wolflier==1){
				Ans.push_back({i,j});
				break;				
			}
		}
		if(!Ans.empty()) break;
	}
	if(Ans.empty()) puts("No Solution");
	else printf("%d %d",Ans[0].first,Ans[0].second);
	return 0;
}
/*
5
-2
+3
-4
+5
+4

6
+6
+3
+1
-5
-2
+4

5
-2
-3
-4
-5
-1
*/
