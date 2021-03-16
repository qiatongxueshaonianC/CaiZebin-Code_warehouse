#include<bits/stdc++.h>
using namespace std; 
int main() {
	int n,sqr;
	scanf("%d",&n);
	vector<int> ans;
    sqr=(int)sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){
		int p=n;
		if(p%i==0){
			vector<int> temp;
			temp.push_back(i);
			p/=i;
			int j=i+1;
			while(p%j==0){
				temp.push_back(j);
				p/=j;
				j++;
			}
			if(temp.size()>ans.size())  //因为是从小到大枚举，所以不用判断长度相等的时候 
				ans=temp;
		}
	}
	if(ans.size()==0)
		printf("1\n%d",n);
	else{
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++)
			printf("%d%s",ans[i],i==ans.size()-1?"":"*");	
	} 
	return 0;
}
/*
630
*/
