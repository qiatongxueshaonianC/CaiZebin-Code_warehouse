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
struct cmp {
	bool friend operator <(const set<string>& a, const set<string>& b) {
		return a.size() > b.size();
	}
};
map<string, int> mp;
set<set<string>,cmp> st;
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
		for (auto& I : st) {
			if (I.find(a) != I.end() || I.find(b) != I.end()) {
				set<string> temp=I; 
				st.erase(I);
				temp.insert(a);
				temp.insert(b);
				flag = true;
				break;
			}
		}
		if (flag == false) {
			set<string> temp;
			temp.insert(a); temp.insert(b);
			st.insert(temp);
		}
	}
	return 0;
}
