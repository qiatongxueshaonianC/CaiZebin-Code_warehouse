#include<bits/stdc++.h>
using namespace std;
int judge(char a,char b){
	if(a==b)
		return 0;
	if((a=='C'&&b=='J')||(a=='J'&&b=='B')||(a=='B'&&b=='C'))
		return 1;
	else 
		return -1;
}
int main() {
	int N,ans[3]={0},win[128]={0},loss[128]={0};
	char a,b;
	scanf("%d%*c",&N);
	for(int i=0;i<N;i++){
		scanf("%c %c%*c",&a,&b);
		if(judge(a,b)==0)
			ans[1]++;
		else if(judge(a,b)==1){
			ans[0]++;
			win[a]++;
		}
		else {
			ans[2]++;
			loss[b]++;
		}	
	} 
	printf("%d %d %d\n",ans[0],ans[1],ans[2]);
	printf("%d %d %d\n",ans[2],ans[1],ans[0]);
	int wi=max(win['B'],max(win['C'],win['J']));
	int lo=max(loss['B'],max(loss['C'],loss['J']));
	printf("%c ",win['B']==wi?'B':win['C']==wi?'C':'J');
	printf("%c",loss['B']==lo?'B':loss['C']==lo?'C':'J');
}
/*
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
*/
