#include<bits/stdc++.h>
using namespace std;
const int maxn=10010; 
int n,heap[maxn];
void downAdjust(int low,int high){
	int i=low,j=2*i;  //low为待调整的节点的下标，j为该节点的左儿子
	while(j<=high){  //保证待调整的节点不是叶子节点 
		if(j+1<=high&&heap[j+1]>heap[j]){  //检查是否有右儿子，取两个儿子中的较大者 
			swap(heap[j],heap[j+1]);  //交换heap中的两个左右儿子，保证左儿子要大于右儿子 
		} 
		if(heap[j]>heap[i]){
			swap(heap[j],heap[i]);  //调整
			i=j;
			j=2*i;  //设置下一轮需要调整的结点 
		} else break;  //没有结点需要调整，即调整结束 
	} 
}
void deleteTop(){
	heap[1]=heap[n--];  //把最后一个结点放到根节点，然后向下调整 
	downAdjust(1,n);
} 
void upAdjust(int low,int high){
	int i=high,j=i/2;  //low设为堆结构的根结点，通常设为1，i插入的新节点的下标
//	while(i>low){  //当前需要调整的节点不是根节点 
	while(j>=low){  //待调整的结点存在父节点 
		if(heap[j]<heap[i]){
			swap(heap[j],heap[i]);  //交换两个结点
			i=j;
			j=i/2;  //设置下一轮待调整的结点 
		} else break;  //没有结点需要调整，即调整结束 
	} 
} 
void insert(int s){
	heap[++n]=s;
	upAdjust(1,n);
} 
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&heap[i]);
	for(int i=n/2;i>=1;i--)  //建堆 
		downAdjust(i,n);
	return 0;
}
