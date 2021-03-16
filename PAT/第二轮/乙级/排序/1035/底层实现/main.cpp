#include<bits/stdc++.h>
using namespace std; 
vector<int> ori,fin,temp;
bool InsertMerge(vector<int>& a){
	bool flag=false;
	for(int i=1;i<a.size();i++){
		int j=i-1,temp=a[i];
		while(j>=0&&temp<a[j]){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
		if(flag)
			break;
		flag=a==fin?1:0;
	}
	return flag;
}
void output(vector<int> a){
	for(int i=0;i<a.size();i++)
		printf("%d%s",a[i],i==a.size()-1?"\n":" ");
}
void Merge(vector<int>& a,int l,int r,int rr){
	vector<int> temp;
	int idl=l,idr=r;
	while(idl<r&&idr<rr){
		if(a[idl]<a[idr])
			temp.push_back(a[idl++]);
		else
			temp.push_back(a[idr++]);
	}
	while(idl<r) temp.push_back(a[idl++]);
	while(idr<rr) temp.push_back(a[idr++]); 
	for(int i=0;i<temp.size();i++)
		a[l+i]=temp[i];
}
bool MergeSort(vector<int>& a){
	bool flag=false;
	for(int step=2;step/2<=a.size();step*=2){
		for(int i=0;i<a.size();i+=step){
			Merge(a,i,min(i+step/2,(int)a.size()),min(i+step,(int)a.size()));
		}
		if(flag)
			break;
		flag=a==fin?1:0;
	}
	return flag;
}
int main() {
	int n;
	scanf("%d",&n);
	ori.resize(n);fin.resize(n);
	for(int i=0;i<n;i++)
		scanf("%d",&ori[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&fin[i]);
	temp=ori;
	if(InsertMerge(temp))
		puts("Insertion Sort");
	else{
		puts("Merge Sort");
		temp=ori;
		MergeSort(temp);
	}
	output(temp);
	return 0;
}
/*
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0

10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
*/
