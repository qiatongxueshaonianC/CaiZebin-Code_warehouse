#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int n;
vector<int> init,dest,heap; 
bool InsertSort(){
	for(int i=2;i<=n;i++){
		sort(heap.begin()+1,heap.begin()+i+1);//����ҿ�
		if(heap==dest){
			sort(heap.begin()+1,heap.begin()+i+2);
			return true;
		} 
	}
	return false;
}
void downAdjust(int low,int high){   //������ĺ��Ĵ��� 
	int i=low,j=2*i;
	while(j<=high){
		if(j+1<=high&&heap[j+1]>heap[j])
			j=j+1;
		if(heap[j]>heap[i]){
			swap(heap[i],heap[j]);
			i=j;
			j=i*2;
		}else break;
	}
}
bool heapSort(){
	for(int i=n/2;i>=1;i--){  //���� 
		downAdjust(i,n);
	}
	bool flag=false;
	for(int i=n;i>=1;i--){
		if(i!=n&&heap==dest){
			flag=true;
		}
		swap(heap[i],heap[1]);
		downAdjust(1,i-1);     //ע����i-1 
		if(flag) return true;
	} 
	return false;
}
int main() {
	init.push_back(0);
	dest.push_back(0);
	scanf("%d",&n);
	int v;
	for(int i=1;i<=n;i++){
		scanf("%d",&v);
		init.push_back(v);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&v);
		dest.push_back(v);
	}
	heap=init;
	if(InsertSort()){
		puts("Insertion Sort");
		for(auto i=++heap.begin();i!=heap.end();i++)
			printf("%d%s",*i,i!=--heap.end()?" ":"");
	}else{
		puts("Heap Sort");
		heap=init;
		heapSort();
		for(auto i=++heap.begin();i!=heap.end();i++)
			printf("%d%s",*i,i!=--heap.end()?" ":"");
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
