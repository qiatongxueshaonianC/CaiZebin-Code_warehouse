//报错：[Error] invalid types 'int[int]' for array subscript意思是变量重复定义 
//报错：[Error] reference to 'next' is ambiguous意思是用了已经定义的关键字  在c++11中是关键字 
#include<bits/stdc++.h>
using namespace std; 
int data[100005],Next[100005]; 
bool cmp(int a,int b){
	return data[a]<data[b];
}
int main() {
	int st,n,id;
	scanf("%d%d",&n,&st);
	if(st==-1){
		printf("0 -1\n");
		return 0;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&id);
		scanf("%d%d",&data[id],&Next[id]);
	}
	vector<int> listAddr;
	while(st!=-1){
		listAddr.push_back(st);
		st=Next[st];
	}
	sort(listAddr.begin(),listAddr.end(),cmp);  //对下标排序
/*	for(int i=0;i<listAddr.size()-1;i++)
		Next[listAddr[i]]=listAddr[i+1]; */
	printf("%d %05d\n",listAddr.size(),listAddr.front());
	for(int i=0;i<listAddr.size()-1;i++)
		printf("%05d %d %05d\n",listAddr[i],data[listAddr[i]],listAddr[i+1]);
	//	printf("%05d %d %05d\n",listAddr[i],data[listAddr[i]],Next[listAddr[i]]);
	printf("%05d %d -1\n",*(--listAddr.end()),data[*(--listAddr.end())]);
	return 0;
}
/*
5 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345

1 00001
00002 0 -1
*/
