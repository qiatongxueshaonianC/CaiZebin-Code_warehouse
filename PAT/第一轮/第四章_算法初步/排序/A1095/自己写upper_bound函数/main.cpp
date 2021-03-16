#include<bits/stdc++.h>
using namespace std; 
struct Recorder{
	string id;
	int time;
	char state;
	Recorder(string a,int b,char c):id(a),time(b),state(c){}
	bool friend operator <(Recorder a,Recorder b){
		return a.id!=b.id?a.id<b.id:a.time<b.time;
	}
};
set<Recorder> st;
vector<Recorder> valid;  //存储有效记录 
unordered_map<string,int> mp;
vector<pair<int,int>> A;  //记录各个时间点内的汽车数量 
bool cmp(Recorder a,Recorder b){
	return a.time<b.time;
}
int upper_bound(int low,int high,int v){
	int mid;
	while(low<high){
	    mid=(low+high)/2;
		if(v<A[mid].first)
			high=mid;
		else low=mid+1;
	}
	return low;
}
int main() {
	int N,K,max_time=0;
	scanf("%d%d",&N,&K);
	string id;
	int hh,mm,ss;
	char state[4];
	for(int i=0;i<N;i++){
		cin>>id;
		scanf("%d:%d:%d%s",&hh,&mm,&ss,&state);
		st.insert(Recorder(id,hh*3600+mm*60+ss,state[0]));
	} 
	set<string> ans;
	auto it=++st.begin();
	for(auto pre=st.begin();it!=st.end();it++){  //得到有效记录 
		if(pre->state=='i'&&it->state=='o'&&pre->id==it->id){
			valid.push_back(*pre);
			valid.push_back(*it);
			mp[pre->id]=mp[pre->id]+it->time-pre->time;
		}
		pre=it;			
	}
	sort(valid.begin(),valid.end(),cmp);
	for(auto i:mp){  //求停留最大值 
		if(i.second>max_time){
			max_time=i.second;
			ans.clear();
			ans.insert(i.first);
		}else if(i.second==max_time)
			ans.insert(i.first);
	}
	for(auto i:valid){  //所有的记录都是合法的 
		pair<int,int> now;
		now.first=i.time;
		if(i.state=='i'){
			if(A.size()){
				now.second=A.back().second;
				now.second++;
			}
			else now=make_pair(i.time,1);
			A.push_back(now);
		}else{
			now.second=A.back().second;
			now.second--;
			A.push_back(now);		
		}
	} 
	while(K--){
		scanf("%d:%d:%d",&hh,&mm,&ss);
		hh=hh*3600+mm*60+ss;
		int it=upper_bound(0,A.size(),hh);
		printf("%d\n",A[(--it)].second);
	}
	for(auto i:ans)
		printf("%s ",i.c_str());
	printf("%02d:%02d:%02d",max_time/3600,(max_time%3600)/60,max_time%60);
	return 0;
}
/*
16 7
JH007BD 18:00:01 in
ZD00001 11:30:08 out
DB8888A 13:00:00 out
ZA3Q625 23:59:50 out
ZA133CH 10:23:00 in
ZD00001 04:09:59 in
JH007BD 05:09:59 in
ZA3Q625 11:42:01 out
JH007BD 05:10:33 in
ZA3Q625 06:30:50 in
JH007BD 12:23:42 out
ZA3Q625 23:55:00 in
JH007BD 12:24:23 out
ZA133CH 17:11:22 out
JH007BD 18:07:01 out
DB8888A 06:30:50 in
05:10:00
06:30:50
11:00:00
12:23:42
14:00:00
18:00:00
23:59:00
*/



