#include<bits/stdc++.h>
using namespace std;
set<pair<int,int> > s;
vector<pair<int,int> > v;

struct pair_hash {
    inline size_t operator()(const pair<int,int> & p) const {
        return p.first*10 + p.second;
    }
};
unordered_set<pair<int, int>, pair_hash> pHash;
//unordered_map、unordered_set都不可以直接用pair<>;要自己定义 

int main() {
	for(int i=0;i<10;i++){
		s.insert({i,2*i});
		v.push_back({i,2*i});
	}
	for(auto i:s){
		printf("%d,%d",i.first,i.second);//只是针对set可以这么写，或者是值唯一的时候，
		//否则可能出现值相等的情况 
		if(i!=*(--s.end())) printf(" #");//！！！！！！！！！！！！！！！！！！！！ 
	//	if(i!=*(s.end()-1)) printf(" #");    //会报错 
		else cout<<endl<<endl;
	} 
	
	for(auto i:v){
		printf("%d,%d",i.first,i.second);
		if(i!=*(--v.end())) printf(" ");
		if(i!=*(v.end()-1)) printf("#");    //两个都可以 
		else cout<<endl<<endl;
		
		//原因：因为vector类似是数组，加减1就像是数组向前、后移动一个位置
		//而set并不是这种连续空间的结构，是红黑树，所以不可以 
	}
	return 0;
}
