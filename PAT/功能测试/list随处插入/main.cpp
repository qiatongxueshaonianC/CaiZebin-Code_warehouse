#include<bits/stdc++.h>
using namespace std; 
int main() {
	list<int> A;
	A.push_back(1);
	A.push_front(2);
	A.push_back(3);
	list<int>::iterator it=A.begin()++;
	A.insert(++it,8); 
	for(auto i:A)
		printf("%d",i);
	puts("");
	A.pop_front();
	A.pop_back();
	for(list<int>::reverse_iterator it=A.rbegin();it!=A.rend();it++)
		printf("%d ",*it);
	return 0;
}
