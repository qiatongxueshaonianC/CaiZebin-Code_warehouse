#include<bits/stdc++.h>
using namespace std; 
const int maxn=110;
int N,M,L; 
vector<int> A,temp; 
bitset<maxn> wolf;
bool judge(vector<int> temp){
	int wolflier=0,lier=0;
	for(int i=1;i<=N;i++){
		int beEvalued_id=abs(A[i]);
		if(A[i]>0&&wolf[beEvalued_id]==0)	continue;	//说他是个好人，确实是个好人，没说谎
		if(A[i]<0&&wolf[beEvalued_id]==1)	continue;	//说他是个坏人，确实是个坏人，没说谎
		lier++;		//说谎的人加一 
		if(wolf[i]==true){
			wolflier++;	//说谎的狼人加一 
		} 
		if(lier>L)
			return false;
	//	if(lier>L||wolflier>=L)		//注意！wolflier可以达到L，如果L远小于M的话 
	//		return false;
	}
	if(lier==L&&(1<=wolflier&&wolflier<M)) 	//符合条件 
		return true;
	return false; 
}
void DFS(int idx,int wf_num){
	if(idx==-1||wf_num+idx<M)	//剩下的全部都是狼都没用 
		return;
	if(wf_num==M){
		if(judge(temp)==false)
			return;
		printf("%d",temp[0]);
		for(int i=1;i<temp.size();i++)
			printf(" %d",temp[i]);
		exit(0);
	}
	temp.push_back(idx);
	wolf[idx]=1;
	DFS(idx-1,wf_num+1);		//选 
	temp.pop_back();
	wolf[idx]=0;
	DFS(idx-1,wf_num);		//不选 
}
int main() {
	scanf("%d%d%d",&N,&M,&L);
	A.resize(N+1);
	for(int i=1;i<=N;i++)
		scanf("%d",&A[i]);
	DFS(N,0); 
	puts("No Solution");
	return 0; 
}
/*
5 2 2
-2
+3
-4
+5
+4

6 2 3
-2
+3
-4
+5
+4
-3

6 2 5
-2
+3
-4
+5
+4
+6
*/
