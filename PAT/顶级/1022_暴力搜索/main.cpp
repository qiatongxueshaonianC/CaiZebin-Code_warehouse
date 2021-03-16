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
		if(A[i]>0&&wolf[beEvalued_id]==0)	continue;	//˵���Ǹ����ˣ�ȷʵ�Ǹ����ˣ�û˵��
		if(A[i]<0&&wolf[beEvalued_id]==1)	continue;	//˵���Ǹ����ˣ�ȷʵ�Ǹ����ˣ�û˵��
		lier++;		//˵�ѵ��˼�һ 
		if(wolf[i]==true){
			wolflier++;	//˵�ѵ����˼�һ 
		} 
		if(lier>L)
			return false;
	//	if(lier>L||wolflier>=L)		//ע�⣡wolflier���ԴﵽL�����LԶС��M�Ļ� 
	//		return false;
	}
	if(lier==L&&(1<=wolflier&&wolflier<M)) 	//�������� 
		return true;
	return false; 
}
void DFS(int idx,int wf_num){
	if(idx==-1||wf_num+idx<M)	//ʣ�µ�ȫ�������Ƕ�û�� 
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
	DFS(idx-1,wf_num+1);		//ѡ 
	temp.pop_back();
	wolf[idx]=0;
	DFS(idx-1,wf_num);		//��ѡ 
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
