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
//unordered_map��unordered_set��������ֱ����pair<>;Ҫ�Լ����� 

int main() {
	for(int i=0;i<10;i++){
		s.insert({i,2*i});
		v.push_back({i,2*i});
	}
	for(auto i:s){
		printf("%d,%d",i.first,i.second);//ֻ�����set������ôд��������ֵΨһ��ʱ��
		//������ܳ���ֵ��ȵ���� 
		if(i!=*(--s.end())) printf(" #");//���������������������������������������� 
	//	if(i!=*(s.end()-1)) printf(" #");    //�ᱨ�� 
		else cout<<endl<<endl;
	} 
	
	for(auto i:v){
		printf("%d,%d",i.first,i.second);
		if(i!=*(--v.end())) printf(" ");
		if(i!=*(v.end()-1)) printf("#");    //���������� 
		else cout<<endl<<endl;
		
		//ԭ����Ϊvector���������飬�Ӽ�1������������ǰ�����ƶ�һ��λ��
		//��set���������������ռ�Ľṹ���Ǻ���������Բ����� 
	}
	return 0;
}
