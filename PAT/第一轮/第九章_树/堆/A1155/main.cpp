#include<iostream>
#include<vector>
#include<map>
using namespace std; 
const int maxn=1010;
int A[maxn],n,index=0;
vector<vector<int>>ans;
vector<int> temp;
void PostOrder(int s){
	temp.push_back(A[s]);
	if(2*s>n){  //Ҷ�ӽڵ� 
		ans.push_back(temp);
		temp.pop_back();
		return;
	}
	if(2*s+1<=n)	PostOrder(2*s+1);
	if(2*s<=n)	PostOrder(2*s);
	temp.pop_back();
}
bool downAdjust_max(int low,int high){
	int i=low,j=2*low;
	while(j<high){
		if(j+1<high&&A[j+1]>A[j])
			j=j+1;
		if(A[j]>A[i])
			return false;
		else return true;
	}
	return true;
}
bool downAdjust_min(int low,int high){
	int i=low,j=2*low;
	while(j<high){
		if(j+1<high&&A[j+1]<A[j])
			j=j+1;
		if(A[j]<A[i])
			return false;
		else return true;
	}
	return true;
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]);
	PostOrder(1);
	bool f1=true,f2=true;
	for(int i=n/2;i>0;i--){  //2019/11/27/23:41���ִ�������Ĳ����ǣ�i,n)!!! 
		if(downAdjust_max(i,n)==false&&f1==true) f1=false;  //����(1,i) 
		if(downAdjust_min(i,n)==false&&f2==true) f2=false;
		if(f1==false&&f2==false) break;
	}
	for(auto i:ans){
		for(int j=0;j<i.size();j++){
			printf("%d%s",i[j],j==i.size()-1?"\n":" ");
		}
	}
	printf("%s\n",f1?"Max Heap":f2?"Min Heap":"Not Heap");
	return 0;
}
/*
8
98 72 86 60 65 12 23 50

8
8 38 25 58 52 82 70 60

8
10 28 15 12 34 9 8 56
*/
