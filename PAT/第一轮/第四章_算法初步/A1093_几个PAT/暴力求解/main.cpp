#include<bits/stdc++.h>
using namespace std;
string s1;
int num,i,j,k,t=0;
int main() {
	cin>>s1;
	while(1){
		i=s1.find('P',t);
		if(i==string::npos) {
			break;
		}
		int temp1=i;
		while(1){
			j=s1.find('A',temp1);
			if(j==string::npos) {
				break;
			}
			int temp2=j;
			while(1){
				k=s1.find('T',temp2);
				if(k==string::npos){
					break;
				}
				num++;
				temp2=k+1;
			}
			temp1=j+1;
		}
		t=i+1;
	}
	printf("%d\n",num);
	return 0;
}
/*
APPAPT
*/
