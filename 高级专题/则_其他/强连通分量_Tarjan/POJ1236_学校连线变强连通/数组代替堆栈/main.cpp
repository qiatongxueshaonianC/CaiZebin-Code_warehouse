#include<iostream>
#include<cstdio>
#include<vector>
using namespace std; 
const int maxn=105;
vector<vector<int> >G(maxn);
int N,components_cnt,components[maxn],_stack[maxn],top,idx[maxn],lowidx[maxn],vis_num;
int indegree[maxn],outdegree[maxn];
void Tarjan(int s){
	idx[s]=lowidx[s]=++vis_num;
	_stack[top++]=s;
	for(int i=0;i<G[s].size();i++){
		int v=G[s][i];
		if(idx[v]==0){		//�������㻹û���� 
			Tarjan(v);
			lowidx[s]=min(lowidx[s],lowidx[v]);
		}else if(components[v]==0){	//���ڵ�ǰ��ǿ��ͨ���� 
			lowidx[s]=min(lowidx[s],idx[v]); 
		}
	}
	if(lowidx[s]==idx[s]){	//��sΪ����һϵ�е㹹����һ��ǿ��ͨ���� 
		int t;
		components_cnt++;	//ǿ��ͨ��������һ��
		do{
			t=_stack[--top];
			components[t]=components_cnt;
		} while(t!=s);
	}
} 
int main() {
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		int v;
		while(~scanf("%d",&v)&&v!=0){
			G[i].push_back(v);
		}
	}
	for(int i=1;i<=N;i++){
		if(idx[i]==0){	//��i���㻹û���ʹ� 
			Tarjan(i);
		}
	}
	if(components_cnt==1){		//������ͼ����һ��ǿ��ͨ���� 
		printf("%d\n%d",1,0);
		return 0;
	} 
	for(int i=1;i<=N;i++){
		for(int j=0;j<G[i].size();j++){
			int nxt=G[i][j];	//����i���ڽӵ�
			if(components[i]!=components[nxt]){	//�����㲻����ͬһ��ǿ��ͨ���� ����ͨ����ѹ����һ���� 
				indegree[components[nxt]]++;	//nxt���ڵ���ͨ��������ȼ�һ 
				outdegree[components[i]]++;	//i���ڵ���ͨ�����ĳ��ȼ�һ 
			} 
		}
	} 
	int ans1=0,ans2=0; 
	for(int i=1;i<=components_cnt;i++){
		if(indegree[i]==0)		//���Ϊ0��ǿ��ͨ���м�������Ϊ��һ�ʴ� 
			ans1++;
		if(outdegree[i]==0)
			ans2++;
	} 
	printf("%d\n%d",ans1,max(ans1,ans2));
	return 0;
}
/*
5
2 4 3 0
4 5 0
0
0
1 0
*/
