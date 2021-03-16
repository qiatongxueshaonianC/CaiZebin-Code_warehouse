#include<bits/stdc++.h>
using namespace std; 
struct Node{
	string id;
	int score;
	Node(string a,int b):id(a),score(b){}
};
struct site_people{
	int site,people;
	site_people(int a,int b):site(a),people(b){}
/*	bool operator <(const site_people &u){  //会出错 
		if(people!=u.people)
			return people<u.people;
		else
			return site>u.site;
	}*/
	bool friend operator <(site_people u,site_people v){
		return u.people!=v.people?u.people<v.people:u.site>v.site;
	}
};
bool cmp(Node a,Node b){
	return a.score!=b.score?a.score>b.score:a.id<b.id;
}
unordered_map<int,pair<int,int>> site_sumscore;
unordered_map<int,unordered_map<int,int>> day_site_people;  //记录某天某个考场的人数 
unordered_map<char,vector<Node>> level_stu;
int main() {
	int n,m,score;
	scanf("%d%d",&n,&m);
	string s;
	for(int i=0;i<n;i++){
		cin>>s>>score;
		int site=stoi(s.substr(1,3));
		int day=stoi(s.substr(4,6));
		level_stu[s[0]].push_back(Node(s,score));
		site_sumscore[site].first++;  //记录人数 
		site_sumscore[site].second+=score;
		day_site_people[day][site]++;
	}
	for(int i=1;i<=m;i++){
		int type;
		string s;
		cin>>type>>s;
		printf("Case %d: %d %s\n",i,type,s.c_str());
		if(type==1){
			char lev=s[0];
			if(level_stu.find(lev)==level_stu.end()){
				puts("NA");
				continue;
			}
			sort(level_stu[s[0]].begin(),level_stu[s[0]].end(),cmp);
			for(auto i:level_stu[s[0]])
				printf("%s %d\n",i.id.c_str(),i.score);
		}else if(type==2){
			int site=stoi(s);
			if(site_sumscore.find(site)==site_sumscore.end()){
				puts("NA");
				continue;
			}
			printf("%d %d\n",site_sumscore[site].first,site_sumscore[site].second);
		}else{
			int day=stoi(s);
			if(day_site_people.find(day)==day_site_people.end()){
				puts("NA");
				continue;
			}
			priority_queue<site_people> q;
			for(auto i:day_site_people[day]){
				q.push(site_people(i.first,i.second));
			}
			while(!q.empty()){
				printf("%d %d\n",q.top().site,q.top().people);
				q.pop();
			}
		}
	}
	return 0;
}
/*
8 4
B123180908127 99
B102180908003 86
A112180318002 98
T107150310127 62
A107180908108 100
T123180908010 78
B112160918035 88
A107180908021 98
1 A
2 107
3 180908
2 999
*/
