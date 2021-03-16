#include<bits/stdc++.h>
using namespace std;
unordered_map<int,unordered_map<string,set<string>> >mp;
int main() {
	int n,m;
	scanf("%d%*c",&n);
	string id,title,name,keyword,publish,year,query;
	for(int i=0;i<n;i++){
		getline(cin,id);
		getline(cin,title);
		mp[1][title].insert(id);
		getline(cin,name);
		mp[2][name].insert(id);
		getline(cin,keyword);
		stringstream val(keyword);
		while(val>>keyword)
			mp[3][keyword].insert(id);
		getline(cin,publish);
		mp[4][publish].insert(id);
		getline(cin,year);
		mp[5][year].insert(id);
	}
	scanf("%d",&m);
	while(m--){
		scanf("%d: ",&n);
		getline(cin,query);
		printf("%d: %s\n",n,query.c_str());
		if(mp[n].find(query)==mp[n].end()) puts("Not Found");
		for(auto i:mp[n][query])
			puts(i.c_str());
	}
	return 0;
}
/*
3
1111111
The Testing Book
Yue Chen
test code debug sort keywords
ZUCS Print
2011
3333333
Another Testing Book
Yue Chen
test code sort keywords
ZUCS Print2
2012
2222222
The Testing Book
CYLL
keywords debug book
ZUCS Print2
2011
6
1: The Testing Book
2: Yue Chen
3: keywords
4: ZUCS Print
5: 2011
3: blablabla
*/
