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
#define lowbit(x) x&(-x)
using namespace std;
const int maxn = 2020;
map<string, int>st;
map<int, string> ItoS;
map<int, int> Cost;
vector<pair<string, string> > edges;
int n, V, father[maxn];
int findFather(int a) {
	if (father[a] < 0)
		return a;
	int temp = findFather(father[a]);
	father[a] = temp;
	return temp;
}
void Union(int a, int b) {
	if (Cost[a] < Cost[b])  //ÒÔaÎª¸ù
		swap(a, b);
	Cost[a] += Cost[b];
	father[a] += father[b];
	father[b] = a;
}
bool cmp(const pair<string, string>& a, const pair<string, string>& b) {
	return max(Cost[st[a.first]], Cost[st[a.second]]) > max(Cost[st[b.first]], Cost[st[b.second]]);
}
int main() {
	memset(father, -1, sizeof(father));
	scanf("%d%d", &n, &V);
	for (int i = 0; i < n; i++) {
		string a, b;
		int val;
		cin >> a >> b >> val;
		if (st.find(a) == st.end())
			st.insert(make_pair(a, st.size()));
		if (st.find(b) == st.end())
			st.insert(make_pair(b, st.size()));
		Cost[st[a]] += val;
		Cost[st[b]] += val;
		ItoS[st[a]] = a;
		ItoS[st[b]] = b;
		edges.push_back(make_pair(a, b));
	}
	sort(edges.begin(), edges.end(), cmp);
	for (int i = 0; i < edges.size(); i++) {
		int fa = findFather(st[edges[i].first]);
		int fb = findFather(st[edges[i].second]);
		if (fa != fb) {
			Union(fa, fb);
		}
	}
	bool vis[maxn] = { false };
	map<string, int> ans;
	for (int i = 0; i < st.size(); i++) {
		int now = findFather(i);
		if (vis[now] == false) {
			vis[now] = true;
			if (abs(father[now]) < 3)
				continue;
			if (Cost[now] > 2 * V) {
				ans.insert(make_pair(ItoS[now], abs(father[now])));
			}
		}
	}
	printf("%d\n", ans.size());
	for (auto i : ans)
		printf("%s %d\n", i.first.c_str(), i.second);
	return 0;
}
/*
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