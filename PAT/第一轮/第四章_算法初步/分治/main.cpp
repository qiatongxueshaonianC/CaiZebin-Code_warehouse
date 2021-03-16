#include<bits/stdc++.h>
using namespace std; 
void output(vector<int> a){
	for(int i=0;i<a.size();i++)
		printf("%d%s",a[i],i==a.size()-1?"\n":" ");
}
int main() {
	int n;
	scanf("%d",&n);
	vector<int> ori(n),des(n),temp;
	for(int i=0;i<n;i++)
		scanf("%d",&ori[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&des[i]);
	temp=ori;
	bool flag=false;
	for(int i=2;i<=n;i++){
		sort(temp.begin(),temp.begin()+i);   //左闭右开
		if(flag==true) break;
		if(temp==des){
			puts("Insertion Sort");
			flag=true;
		} 
	}
	if(flag==true)
		output(temp);
	else{
		bool f=false;
		temp=ori;
		puts("Merge Sort");
		for(int i=2;i/2<=n;i*=2){
			for(int j=0;j<n;j+=i){
				sort(temp.begin()+j,min(temp.begin()+j+i,temp.end()));
			}   //进行完一轮归并排序    注意对“一轮”的理解 
			if(f==true) break;
			if(temp==des)
				f=true;
		}
		output(temp);
	}
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
