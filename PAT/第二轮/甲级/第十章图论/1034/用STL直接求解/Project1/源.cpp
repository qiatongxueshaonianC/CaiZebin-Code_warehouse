#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<climits>
#include<numeric>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<fstream>
#include<bitset>
#include<iterator>
#define lowbit(x) x&(-x)
using namespace std;
map<string, int> mp;
vector<set<string> > st;
int n, k;
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		string a, b;
		int val;
		cin >> a >> b >> val;
		mp[a] += val;
		mp[b] += val;
		bool flag = false;
		for (vector<set<string> >::iterator it = st.begin(); it != st.end();it++) {
			if ((*it).find(a) != (*it).end() || (*it).find(b) != (*it).end()) {
				(*it).insert(a);
				(*it).insert(b);
				vector<set<string> >::iterator temp = it;
				for (it++; it != st.end(); it++) {
					if ((*it).find(a) != (*it).end() || (*it).find(b) != (*it).end()) {
						for (auto k : (*it))
							(*temp).insert(k);
						(*it).clear();
						break;
					}
				}
				if(it==st.end())
					it--;
				flag = true;
			}
		}
		if (flag == false) {
			set<string> temp;
			temp.insert(a); temp.insert(b);
			st.push_back(temp);
		}
	}
	map<string,int> ans;
	for (auto I : st) {
		int V = 0,Max=0;
		string s;
		if (I.size() < 3)
			continue;
		for (auto i : I) {
			V += mp[i];
			if (mp[i] > Max) {
				Max = mp[i];
				s = i;
			}
		}
		if (V > 2 * k) {
			ans[s]=I.size();
		}
	}
	printf("%d\n", ans.size());
	for (auto i : ans)
		printf("%s %d\n",i.first.c_str(),i.second);
	return 0;
}
/*
10 100
P K 27
O R 46
L N 24
P A 45
Q F 34
K H 50
P K 76
C O 84
H N 54
N K 60

8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10

8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
*/