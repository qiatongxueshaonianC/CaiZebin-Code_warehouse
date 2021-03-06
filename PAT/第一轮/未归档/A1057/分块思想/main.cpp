#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
const int sqr=(int)sqrt(1.0*maxn); 
int blocksize[sqr];
int table[maxn];
stack<int> st;
void Push(int v){
	table[v]++;
	blocksize[v/sqr]++;
	st.push(v);
}
void Pop(){
	if(st.empty())
		puts("Invalid");
	else{
		table[st.top()]--;
		blocksize[st.top()/sqr]--;
		printf("%d\n",st.top());
		st.pop();
	}
}
void PeekMedia(){
	if(st.empty())
		puts("Invalid");
	else{
		int sum=0,i=0,index,len=(st.size()+1)/2;  //这里都用(st.size()+1)/2 
		while(sum+blocksize[i]<len){
			sum+=blocksize[i];
			i++;
		}
		index=sqr*i;  //第i块的起始地址 i从0~316 
		for(;sum+table[index]<len;index++){   //这里不能取等 
			sum+=table[index];
		} 
		printf("%d\n",index);  //注意这里输出的是下标 2019/11/25/18：53发现，改正 
	}
}
int main() {
	int n,v;
	char s[10];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",&s);
		if(s[1]=='o') 
			Pop();
		else if(s[1]=='u'){
			scanf("%d",&v);
			Push(v);
		}else if(s[1]=='e')
			PeekMedia();
	}
	return 0;
}
/*
17
Pop
PeekMedian
Push 3
PeekMedian
Push 2
PeekMedian
Push 1
PeekMedian
Pop
Pop
Push 5
Push 4
PeekMedian
Pop
Pop
Pop
Pop
*/
