#include<bits/stdc++.h>
using namespace std; 
int Rank[10010];
bool Harsh[10010];
bool isPrime(int s){
	if(s<=1) return false;
	int sqr=(int)sqrt(1.0*s);
	for(int i=2;i<=sqr;i++)
		if(s%i==0)
			return false;  //������
	return true; 
}
int main() {
	int n,k,id;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&id);
		Rank[id]=i;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d",&id);
		if(Rank[id]==0){
			printf("%04d: Are you kidding?\n",id);
			continue;
		}
		if(Harsh[id]==1)
			printf("%04d: Checked\n",id);
		else{
			Harsh[id]=1;
			if(Rank[id]==1)
				printf("%04d: Mystery Award\n",id);
			else if(isPrime(Rank[id]))
				printf("%04d: Minion\n",id);
			else
				printf("%04d: Chocolate\n",id);
		}		
	}
	return 0;
}
/*
6
1111
6666
8888
1234
5555
0001
6
8888
0001
1111
2222
8888
2222
*/
