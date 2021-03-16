/*����˼·��
���ȣ���Ŀ�Ѿ�������һ�ֿ��еķ�����Ϊ��֪��ÿһ��Ů����Ψһ����һ���ߵ���Ӧ�����ӣ�
���ڿ��ǣ�A���ӱ��������ﱻ��B����ȡ���ˣ���ôA������Ҫһ��������Ϊ�������B���Ӷ�Ӧ��
ԭŮ���������ÿ�ȱ���������Ů���޸���C���ӣ���ôC����ԭ����Ӧ��Ů������Ҳ�ǿ�ȱ�������Դ����ơ� 
��������������ͬһ��ǿ��ͨ������ʱ�����ǿ�������Ҫ��ÿ�����Ӷ�����Ȣ��һ��Ů����*/

//��������˵���ˣ�ǰ���Ǳ���������ϲ����Ů������ 
#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#include<set>
#include<algorithm>
using namespace std; 
const int maxn=4010;
vector<vector<int> >G(maxn),ans(maxn);
int N,components[maxn],idx[maxn],lowidx[maxn],vis_num,_stack[maxn],top,components_cnt; 
stack<int> stk; 
void Tarjan(int s){
	idx[s]=lowidx[s]=++vis_num;
	stk.push(s);
	for(int i=0;i<G[s].size();i++){
		int v=G[s][i];
		if(idx[v]==0){	//�������û���ʹ� 
			Tarjan(v);
			lowidx[s]=min(lowidx[s],lowidx[v]);
		}else if(components[v]==0){	//�õ�֮ǰ���Ѿ����ʹ����������ڵ�ǰ��ǿ��ͨ���� 
			lowidx[s]=min(lowidx[s],idx[v]); 
		} 
	}
	if(idx[s]==lowidx[s]){	//��sΪ����һϵ�е�����һ��ǿ��ͨ���� 
		int t;
		components_cnt++; 
		do{
			t=stk.top();stk.pop();
			components[t]=components_cnt;
		}while(t!=s);
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin>>N;
//	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		int k,v;
		cin>>k;	
	//	scanf("%d",&k);
		while(k--){
			cin>>v;
		//	scanf("%d",&v);
			G[i].push_back(v+N);
		}
	}
	for(int i=1;i<=N;i++){
		int v;
		cin>>v;
	//	scanf("%d",&v);
		G[v+N].push_back(i);
	}
	for(int i=1;i<=N;i++){
		if(idx[i]==0)
			Tarjan(i);
	}
	for(int i=1;i<=N;i++){
		int ans[maxn]={0},k=0;
		for(int j=0;j<G[i].size();j++){
			int v=G[i][j];
			if(components[i]==components[v]){
				ans[k++]=v;
			}
		}
		printf("%d",k);
		sort(ans,ans+k);
		for(int j=0;j<k;j++)
			printf(" %d",ans[j]-N);
		puts("");
	}
	return 0;
}
/*
4
2 1 2
2 1 2
2 2 3
2 3 4
1 2 3 4
*/
