#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<climits>
#include<numeric>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<fstream>
#include<ctime>
#define lowbit(x) x&(-x)

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std; 
using namespace __gnu_pbds; 
struct node{
	int v,id;
	node(int a,int b):v(a),id(b){}
	node(int a):v(a){} 
	bool operator < (const node& u)const{
		return v!=u.v?v<u.v:id<u.id;	//不这么写的话会全删了 
	}
	bool friend operator ==(const node&a,const node&b){
		return a.v==b.v&&a.id==b.id;
	}
};
#define hash1 cc_hash_table 
#define hash2 gp_hash_table 
typedef tree<node,null_type,less<node>,rb_tree_tag,tree_order_statistics_node_update> Tree;
typedef __gnu_pbds::priority_queue<node,less<node>,pairing_heap_tag> heap;
hash1<string,int> mp1;
hash2<double,string> mp2;
Tree tre;
heap Q; 
int N,op,v,idx=1;
hash2<int,int> st;
int main() {
	cin>>N;
	while(N--){
		scanf("%d%d",&op,&v);
		if(op==1)
			tre.insert(node(v,st[v]++));
		else if(op==2)
			tre.erase(node(v,--st[v]));
		else if(op==3)
			printf("%d\n",tre.order_of_key(node(v,0))+1);
		else if(op==4)
			printf("%d\n",tre.find_by_order(v-1)->v);
		else if(op==5)
			 printf("%d\n",(--tre.lower_bound(node(v,0)))->v);
		else if(op==6){
		/*	if(tre.find(node(v,0))==tre.end())
				printf("%d\n",tre.lower_bound(node(v,0))->v);
			else*/
				printf("%d\n",tre.lower_bound(node(v+1,0))->v);
		//	printf("%d\n",tre.find_by_order(tre.order_of_key(node(v,st[v]-1))+(tre.find(node(v,0))==tre.end()?0:1))->v);
		}
	}
	return 0;
}
/*
16
1 -10000000
1 -10000000
2 -10000000
1 106465
4 1
3 106465
1 317721
1 460929
1 644985
1 84185
1 89851
6 81968
1 492737
5 493598
1 10000000
6 10000000
*/
