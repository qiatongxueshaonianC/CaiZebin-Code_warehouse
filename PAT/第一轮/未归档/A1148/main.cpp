#include<bits/stdc++.h>
using namespace std; 
int main() {
	int n;
	scanf("%d",&n);
	vector<int> A(n+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]);
	bool flag=false;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int wolf=0,wolflier=0,lier=0;
			for(int k=1;k<=n;k++){
				if((A[k]==i||A[k]==j)&&A[k]>0||A[k]<0&&(A[k]!=-i&&A[k]!=-j)){//把坏人说成好人或者好人说成坏人 
					lier++;
					if(k==i||k==j)
						wolflier++;
				}
			}	
			if(lier==2&&wolflier==1){
				printf("%d %d",i,j);
				flag=true;
				break;
			}
		}
		if(flag)
			break;
	}
	if(!flag)
		puts("No Solution");
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
