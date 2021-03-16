#include<bits/stdc++.h>
using namespace std; 
struct Node{
	string id;
	int score;
	Node(string a,int b):id(a),score(b){}
};
int Room[1010][2];
map<string,unordered_map<int,int>> mp;
int main() {
	int N,M,score;
	scanf("%d%d",&N,&M);
	string id,command;
	vector<vector<Node>> A(3);
	map<char,int> trans={{'B',0},{'A',1},{'T',2}};
	unordered_set<string> st;
	for(int i=0;i<N;i++){
		cin>>id>>score;
		A[trans[id[0]]].push_back(Node(id,score));
		command=id.substr(0,1);
		st.insert(command);
		command=id.substr(1,3);
		st.insert(command);
		int room=stoi(command);
		Room[room][0]++;
		Room[room][1]+=score;
		command=id.substr(4,6);
		st.insert(command);
		mp[command][room]++;
	}
	for(auto& i:A)
		sort(i.begin(),i.end(),[](const Node& u,const Node& v){
			return u.score!=v.score?u.score>v.score:u.id<v.id;
		});
	int c_id;
	for(int k=1;k<=M;k++){
		cin>>c_id>>command;
		printf("Case %d: %d %s\n",k,c_id,command.c_str());
		if(st.find(command)==st.end()){
			puts("NA");
			continue;
		}
		if(c_id==1){
			for(auto i:A[trans[command[0]]])
				printf("%s %d\n",i.id.c_str(),i.score);
		}else if(c_id==2){
			int t=stoi(command);
			printf("%d %d\n",Room[t][0],Room[t][1]);
		}else if(c_id==3){
			vector<pair<int,int>> T;
			for(auto i:mp[command])
				T.push_back(i);
			sort(T.begin(),T.end(),[](pair<int,int> a,pair<int,int> b){
				return a.second!=b.second?a.second>b.second:a.first<b.first;
			});
			for(auto i:T)
				printf("%d %d\n",i.first,i.second);
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
