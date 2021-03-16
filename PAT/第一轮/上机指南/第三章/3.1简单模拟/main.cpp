#include<stdio.h> 
int main() {
	int count[5]={0};
	int ans[5]={0};
	int n,tmp;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);   //读入数据
		if(tmp%5==0){  //A1类
			if(tmp%2==0){
				ans[0]+=tmp;
				count[0]++;
			}
		} else if(tmp%5==1){
			if(count[1]%2==0){
				ans[1]+=tmp;
			}else{
				ans[1]-=tmp;
			}
			count[1]++;
		}else if(tmp%5==2){
			count[2]++;
			ans[2]++;
		}else if(tmp%5==3){
			ans[3]+=tmp;
			count[3]++;
		}else if(tmp%5==4){
			if(tmp>ans[4]){
				ans[4]=tmp;
			}
			count[4]++;
		}
	}
	for(int j=0;j<5;j++){
		if(count[j]==0) printf("N");
		else if(j==3) printf("%.1f",(double)ans[3]/count[3]);
		else printf("%d",ans[j]);
		if(j<4) printf(" ");
		else printf("\n");
	}
	return 0;
}
