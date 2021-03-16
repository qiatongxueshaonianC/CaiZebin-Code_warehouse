#include<bits/stdc++.h>
using namespace std;
const int maxn=10010; 
int n,heap[maxn];
void downAdjust(int low,int high){
	int i=low,j=2*i;  //lowΪ�������Ľڵ���±꣬jΪ�ýڵ�������
	while(j<=high){  //��֤�������Ľڵ㲻��Ҷ�ӽڵ� 
		if(j+1<=high&&heap[j+1]>heap[j]){  //����Ƿ����Ҷ��ӣ�ȡ���������еĽϴ��� 
			swap(heap[j],heap[j+1]);  //����heap�е��������Ҷ��ӣ���֤�����Ҫ�����Ҷ��� 
		} 
		if(heap[j]>heap[i]){
			swap(heap[j],heap[i]);  //����
			i=j;
			j=2*i;  //������һ����Ҫ�����Ľ�� 
		} else break;  //û�н����Ҫ���������������� 
	} 
}
void deleteTop(){
	heap[1]=heap[n--];  //�����һ�����ŵ����ڵ㣬Ȼ�����µ��� 
	downAdjust(1,n);
} 
void upAdjust(int low,int high){
	int i=high,j=i/2;  //low��Ϊ�ѽṹ�ĸ���㣬ͨ����Ϊ1��i������½ڵ���±�
//	while(i>low){  //��ǰ��Ҫ�����Ľڵ㲻�Ǹ��ڵ� 
	while(j>=low){  //�������Ľ����ڸ��ڵ� 
		if(heap[j]<heap[i]){
			swap(heap[j],heap[i]);  //�����������
			i=j;
			j=i/2;  //������һ�ִ������Ľ�� 
		} else break;  //û�н����Ҫ���������������� 
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
	for(int i=n/2;i>=1;i--)  //���� 
		downAdjust(i,n);
	return 0;
}
