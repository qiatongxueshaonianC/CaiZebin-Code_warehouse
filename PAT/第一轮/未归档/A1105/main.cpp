#include<bits/stdc++.h>
using namespace std; 
bool cmp(int a,int b){
	return a>b;
}
int main() {
	int N,sqr,n,m;
	scanf("%d",&N);
	vector<int> A(N);
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
	sort(A.begin(),A.end(),cmp);
	sqr=(int)sqrt(1.0*N);
	for(int i=sqr;i>0;i--){
		if(N%i==0){
			n=i;
			m=N/n;
			break;
		}
	}
	int show[m][n],i=0,j=0,st=0;
	fill(show[0],show[0]+N,0);
	while(st<N){
		while(j>=0&&j<n&&show[i][j]==0) 
			show[i][j++]=A[st++];
		i++;j--;
		while(i>=0&&i<m&&show[i][j]==0) 
			show[i++][j]=A[st++];
		i--;j--;
		while(j>=0&&j<n&&show[i][j]==0) 
			show[i][j--]=A[st++];
		i--;j++;
		while(i>=0&&i<m&&show[i][j]==0) 
			show[i--][j]=A[st++];
		i++;j++;
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d%s",show[i][j],j==n-1?"\n":" ");
		}	
	}		
	return 0;
}
/*
12
37 76 20 98 76 42 53 95 60 81 58 93
*/
