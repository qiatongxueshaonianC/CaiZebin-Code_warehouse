#include<bits/stdc++.h> 
using namespace std;
const int maxn=110;
struct Point{
	string name;
	double x,y;
	int id;
};
int N;
vector<Point> cur,p;
double sum,dis[maxn][maxn];
clock_t start,finish;
double get_dis(Point A,Point B){
	double res=sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}
double get_sumdis(vector<Point> A){
	double res=0;
	for(int i=1;i<A.size();i++)
		res+=dis[A[i-1].id][A[i].id];
	res+=dis[A[0].id][A[A.size()-1].id];
/*	for(int i=1;i<A.size();i++)
		res+=get_dis(A[i-1],A[i]);
	res+=get_dis(A[A.size()-1],A[0]);*/
	return res;
}
void init(){
	cin>>N;
	p.resize(N);
	for(int i=0;i<N;i++)
		cin>>p[i].name>>p[i].x>>p[i].y,p[i].id=i;
	start=clock();
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			dis[i][j]=dis[j][i]=get_dis(p[i],p[j]);
		}
	}
	sum=get_sumdis(p);
	cur=p;
}
void Monte_carlo(vector<Point>& A){
	for(int i=0;i<10000;i++){
		for(int k=0;k<A.size();k++){
			int j=(rand()*rand())%N;
			swap(A[k],A[j]);
			double new_sum=get_sumdis(A);
			if(new_sum<sum){
				sum=new_sum;
				p=A;
			}
		}
	}
}
void Solve(){
//	srand((unsigned)time(NULL));
	init();
	Monte_carlo(cur);
	double T=100,T_min=1e-1;
	int count=30;
//	srand(time(NULL));	//加上这一句话结果就不对,每次运行的结果都不一样 
	while(T>T_min){
		cur=p;
		vector<Point> new_p;
		double new_sum=INT_MAX;
		for(int k=0;k<count;k++){
		//	int i=rand()%N,j=rand()%N;	//这么写就是错的 
		//	bool hash[maxn][maxn]={false};
			int i=(rand()*rand())%N,j=(rand()*rand())%N;
		//	while(i==j||hash[i][j]==true){
			while(i==j){
				i=(rand()*rand()+rand())%N,j=(rand()*rand()+rand())%N;
			}
		//	hash[i][j]=true;
			swap(cur[i],cur[j]);
			double temp_sum=get_sumdis(cur);
			if(temp_sum<new_sum){
				new_sum=temp_sum;
				new_p=cur;
			}
			swap(cur[i],cur[j]);	//注意！！这里要换回来 
		}
		double dE=sum-new_sum;
		double rd=rand()%10001/10000.0;
		if(dE>0||exp(dE/T)>rd){	//这里要用到T，所以和T的初值、退火程度都有很大关系，但是dE和T没 
			sum=new_sum;		//有直接关系，这样的话可以把T_min适当的设大一点 
			p=new_p;
		}
		T*=0.999;
	}
	cout<<setiosflags(ios::fixed);
	cout<<setprecision(3)<<sum<<endl;
	for(int i=0;i<p.size();i++)
		cout<<p[i].name<<(i==p.size()-1?"\n":" ");
}
int main(){
	std::ios::sync_with_stdio(false);
	Solve();
	finish=clock();
	cout<<finish-start<<"/"<<CLOCKS_PER_SEC<<"(s)"<<endl;
	return 0;
}
/*
16
A 2.5 4.0
B 1.2 -2.4
C 8.7 1.2
D 3.6 12.1
E -5.5 0.94
F -6.6 -12.6
G 0.18 5.219
H 12.5 14.3609
I 22.5 -5.26
J 1.61 4.5
K 2.1 -5.6
L 0 25
M 9.2 -32
N -1 7
O -5 -8
P 21 35

20
A 2.5 4.0
B 1.2 -2.4
C 8.7 1.2
D 3.6 12.1
E -5.5 0.94
F -6.6 -12.6
G 0.18 5.219
H 12.5 14.3609
I 22.5 -5.26
J 1.61 4.5
K 2.1 -5.6
L 0 25
M 9.2 -32
N -1 7
O -5 -8
P 21 35
Q 16 7.5
R -21 5
S -7 -25.5
T 12 17.5
*/ 
