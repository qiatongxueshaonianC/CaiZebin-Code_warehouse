#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,ans;
    cin>>a>>b;
    ans=a+b;
    if(ans<0){
    	ans=-ans;
    	cout<<'-';
	} 
    string s=to_string(ans);
    for(int i=s.size()-3;i>0;i-=3){
    	s.insert(i,",");
	}
	puts(s.c_str());
    return 0;
}
/*
-1000000 9
-10000000 9
-1000000 -1000000
1000000 1000000
*/
