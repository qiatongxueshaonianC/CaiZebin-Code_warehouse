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
#include<iterator>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
#define harsh gp_hash_table 
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> Tree;
harsh<int,string> h1;
Tree tr;
string s,s1;
int main() {
	while(cin>>s&&s!="#"){
		cin>>s1;
		int ans=0,k=0,j=0,len=s1.size();
		k=s.find(s1);
		while(k!=string::npos){
			ans++;
			j=k+len;
			k=s.find(s1,j);
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
abcde a3
aaaaaa  aa
#
*/
