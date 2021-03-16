#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int n,init[maxn],dest[maxn],heap[maxn];
bool same(int a[],int b[]){
	for(int i=1;i<=n;i++)
		if(a[i]!=b[i])
			return false;
	return true;
} 
void downAdjust(int low,int high){
	int i=low,j=2*i;
	while(j<=high){  //有儿子 
		if(j+1<=high&&heap[j+1]>heap[j])
		//	swap(heap[j],heap[j+1]);  //2019.10.19.20:50错了不能交换左右儿子 
			j=j+1; 
		if(heap[j]>heap[i]){
			swap(heap[j],heap[i]);  
			i=j;
			j=2*i;
		} else break;
	}
}
void createHeap(){
	for(int i=n/2;i>=1;i--){
		downAdjust(i,n);
	}
}
bool HeapSort(){
	createHeap();
	bool flag=false;
	for(int i=n;i>1;i--){
	/*	if(i!=nsame(heap,dest)){
			flag=true; 
		}*/ 
		swap(heap[i],heap[1]);
		downAdjust(1,i-1);    //2019年10月19日20：53在这里犯错了，是i-1 
	//	if(flag) return true;	
		if(same(heap,dest)){  //这样保证至少执行过一次排序 
			swap(heap[--i],heap[1]);
			downAdjust(1,i-1);    //注意：执行向下调整也会改变heap中元素间的相互关系 
			return true;
		}  
	}
	return false;
} 
void InsertSort(){
	bool flag=false;
	for(int i=2;i<=n;i++){
		if(i!=2&&same(heap,dest)){  //至少要执行一轮排序 
			flag=true;
		}
		int tp=heap[i],j=i;
		while(j>1){
			if(heap[j-1]>tp){
				heap[j]=heap[j-1];
				j--;
			}else break;
		}
		heap[j]=tp;
		if(flag) break;
	}
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&init[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&dest[i]);
	memcpy(heap,init,sizeof(init));  //拷贝初始数组 
	if(HeapSort()){
		puts("Heap Sort");
		for(int i=1;i<=n;i++)
			printf("%d%s",heap[i],i<n?" ":"");
	}else {
		puts("Insertion Sort");
		memcpy(heap,init,sizeof(init));
		InsertSort();
		for(int i=1;i<=n;i++)
			printf("%d%s",heap[i],i<n?" ":"");
	}
	return 0;
}
/*
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0

10
3 1 2 8 7 5 9 4 6 0
6 4 5 1 0 3 2 7 8 9
*/
