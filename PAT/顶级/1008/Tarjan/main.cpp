#include<bits/stdc++.h>
using namespace std; 
const int maxn=1e4+5;
vector<vector<int> > G(maxn);
int idx[maxn],lowidx[maxn],component[maxn],cpnt_num;	
int N,M,vis_num;	//idx[i]��ʾ��i�����ǵڼ��������ʵģ�component[i]��ʾ���ǵ�i����������ǿ��ͨ�����ı�� 
stack<int> stk;
void Tarjan(int s){					
	idx[s]=lowidx[s]=++vis_num;
	stk.push(s);
	for(int i=0;i<G[s].size();i++){
		int v=G[s][i];
		if(idx[v]==0){	//δ���ʹ����µ� 
			Tarjan(v);
			lowidx[s]=min(lowidx[s],lowidx[v]);	//�����˵ݹ飬lowidx[G[s][i]]�Ͳ���Ϊ0 
		}else if(component[v]==0){	//conponent[v]==0˵����δ����ĳһ����ͨ������������������ڵ�ǰ��ͨ������ 
				//�Ѿ����ʹ��ĵ㣬����Ҫ�ڵ�ǰ����ͨ�����У�����
				//�Ƚϵ�ǰ���lowidxֵ�����ķ���˳���п�����֮ǰ�ĵ㣬˵���л�ͷ· 
			lowidx[s]=min(lowidx[s],idx[v]); 
		} 
	} 
	if(idx[s]==lowidx[s]){	//��sΪ����һϵ�е㹹��һ��ǿ��ͨ���� 
		cpnt_num++;
		int t;
		do{
			t=stk.top();stk.pop();
			component[t]=cpnt_num;
		}while(t!=s);
	}
}
int main() {
	scanf("%d%d",&N,&M);
	int u,v;
	for(int i=0;i<M;i++){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
	}
	int k;
	scanf("%d",&k);
	for(int i=1;i<=N;i++){
		if(idx[i]==0)
			Tarjan(i);
	}
	while(k--){
		scanf("%d%d",&u,&v);
		printf("%s\n",component[u]==component[v]?"Yes":"No");
	}
	return 0;
}
/*
12 19
3 4
1 3
12 11
5 9
6 2
3 2
10 7
9 1
7 12
2 4
9 5
2 6
12 4
11 10
4 8
8 12
11 8
12 7
1 5
20
11 4
12 7
3 6
2 3
5 3
3 9
4 3
8 3
8 10
10 11
7 8
7 1
9 5
1 9
2 6
3 1
3 12
7 3
6 9
6 8
*/
