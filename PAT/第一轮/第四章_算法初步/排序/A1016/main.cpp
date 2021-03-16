#include<bits/stdc++.h>
using namespace std; 
struct Node{
	string name;
	int mon,time;
	char state;
	Node(char a[],int b,int c,int d,int e,char f[]){
		name.append(a);
		mon=b;
		time=c*24*60+d*60+e;
		state=f[1];
	}
};
int price[24];
vector<Node> A,temp;
vector<vector<Node>> valid;
bool cmp(Node a,Node b){
	if(a.name!=b.name) return a.name<b.name;
	else return a.time<b.time;
}
double cal(int pre_d,int pre_h,int pre_m,int d,int h,int m){
	long long temp=0;
	while(pre_d!=d||pre_h!=h||pre_m!=m){
		temp+=price[pre_h];
		pre_m++;
		if(pre_m>=60){
			pre_m=0;
			pre_h++;
		}
		if(pre_h>=24){
			pre_h=0;
			pre_d++;
		}
	}
	return temp/100.0;
}
void deal(vector<Node> a){
	double sum=0;
	for(int i=0;i+1<a.size();i+=2){
		double money=0;
		int pre_d=a[i].time/(24*60),d=a[i+1].time/(24*60);
		int pre_h=(a[i].time%(24*60))/60,h=(a[i+1].time%(24*60))/60;
		int pre_m=a[i].time%60,m=a[i+1].time%60;
		printf("%02d:%02d:%02d ",pre_d,pre_h,pre_m);
		printf("%02d:%02d:%02d ",d,h,m);
		money=cal(pre_d,pre_h,pre_m,d,h,m);
		printf("%d $%.2lf\n",a[i+1].time-a[i].time,money);
		sum+=money;
	}
	printf("Total amount: $%.2lf\n",sum);
}
int main() {
	for(int i=0;i<24;i++)
		scanf("%d",&price[i]);
	int n;
	scanf("%d",&n);
	char name[21],state[20];
	int mon,day,h,m;
	for(int i=0;i<n;i++){
		scanf("%s%d:%d:%d:%d%s",&name,&mon,&day,&h,&m,&state);
		A.push_back(Node(name,mon,day,h,m,state));
	}
	sort(A.begin(),A.end(),cmp);
/*	for(auto i:A){
		printf("%s %02d:%02d:%02d %c\n",i.name.c_str(),i.time/(24*60),(i.time%(24*60))/60,i.time%60,i.state);
	}*/
	auto pre=A.begin();
	valid.push_back(temp);
	for(auto it=++A.begin();it!=A.end();it++){  //�õ���Ч��¼ 
		if(pre->name!=it->name&&valid.back().size()!=0){  //�µ�һ���� ��ǰһ����ӵ����Ч��¼ 
			valid.push_back(temp);
		}
		if(pre->state=='n'&&it->state=='f'&&pre->name==it->name){
			valid.back().push_back(*pre);
			valid.back().push_back(*it);
		}
		pre=it;
	}
	for(auto &i:valid){
		if(i.empty()) continue;  //2019/11/29/15��12���֣��ռ�¼Ҫ���� 
		printf("%s %02d\n",i.begin()->name.c_str(),i.begin()->mon);
		deal(i);
	}
	return 0;
}
/*
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
11
A 01:01:06:00 on-line
A 01:00:06:00 of-line
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line
*/
