#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
int n,x,y,ans,heap[maxn]; 
void downAdjust(int low,int high){
	int i=low,j=2*i;
	while(j<=high){
		if(j+1<=high&&heap[j+1]<heap[j])
			j=j+1;
		if(heap[j]<heap[i]){
			swap(heap[j],heap[i]);
			i=j;
			j=2*i;
		}else break;
	}
}
void createHeap(){
	for(int i=n/2;i>=1;i--)
		downAdjust(i,n);
}
void upAdjust(int low,int high){
	int i=high,j=i/2;
	while(j>=low){
		if(heap[i]<heap[j]){  //待调整结点值小于父节点，小顶堆所以交换 
			swap(heap[i],heap[j]);
			i=j;
			j=i/2;
		}else break;
	}
}
int main() {
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&heap[i]);
	createHeap();
	int k=n;
	while(k>=2){
		x=heap[1];
		swap(heap[1],heap[k]);
		downAdjust(1,--k);     //不是downAdjust(heap[1],heap[--k])!!!!!,是对下标操作 
		y=heap[1];
		swap(heap[1],heap[k]);
		downAdjust(1,k-1);      
		heap[k]=x+y;
		upAdjust(1,k);
		ans+=x+y;
	}
	printf("%d\n",ans); 
	return 0;
}
/*
3
1 2 9
*/
