#include<bits/stdc++.h>
using namespace std; 
multiset<int> st;
void output(){
	for(auto i:st)
  		printf("%d ",i);
  	puts("");
}
int main(){
	for(int i=0;i<10;i++)
		st.insert(i);
  	st.insert(1);
  	st.insert(2);
  	st.insert(3);
  	output();
  	
  	st.erase(st.find(1));
  	output();
  	
  	st.erase(2);
  	output();
 	return 0;
}
