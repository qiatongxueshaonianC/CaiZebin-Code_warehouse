#include<bits/stdc++.h>
using namespace std; 
int main() {
	vector<int> A(5,0); 
	int n,a,a1=1,a3=0;
	bitset<5> st;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		switch (a%5){
			case 0:
				if(a%2==0){
					st.set(0,1);
					A[0]+=a;
				}
				break;
			case 1:
				A[1]+=a1%2==0?-a:a;
				a1++;
				st.set(1,1);
				break;
			case 2:
				A[2]++;
				st[2]=1;
				break;
			case 3:
				A[3]+=a;
				a3++;
				st[3]=1;
				break;
			case 4:
				A[4]=max(A[4],a);
				st[4]=1;
				break;
		}
	}
	for(int i=0;i<5;i++){
		if(st[i]==0)
			printf("N");
		else if(i==3)
			printf("%.1lf",A[i]*1.0/a3);
		else printf("%d",A[i]);
		printf("%s",i==4?"":" ");
	}
	return 0;
}
/*
13 1 2 3 4 5 6 7 8 9 10 20 16 18

8 1 2 4 5 6 7 9 16
*/
