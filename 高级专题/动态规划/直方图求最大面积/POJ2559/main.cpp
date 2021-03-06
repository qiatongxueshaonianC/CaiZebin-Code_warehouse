#include<iostream>
#include<cstdio>
#include<cmath>
#include<stack>
using namespace std;
typedef long long LL;
const int maxn=100000+10; 
LL h[maxn],n;
int main() {
	std::ios::sync_with_stdio(false);
    while(cin>>n&&n!=0){
    	for(int i=1;i<=n;i++)
    		cin>>h[i];
    	h[++n]=0;
    	LL ans=0;
    	stack<int> stk;
    	stk.push(0);
    	for(int i=1;i<=n;i++){
			while(h[i]<h[stk.top()]){	//注意，stk中的是下标！ 
				LL height=h[stk.top()];stk.pop();
				LL width=i-stk.top()-1;	//减一的原因是stk.top()这个不算进去 
				LL temp=height*width;
				if(temp>ans)
					ans=temp;
			} 
			stk.push(i);   		//注意，stk里面存的是下标 
		}
		cout<<ans<<endl;
	}
    return 0;
}
/*
7 2 1 4 5 1 3 3
4 1000 1000 1000 1000
0
*/

