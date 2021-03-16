#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef unsigned long long uLL;
const int P = 1e8 + 7;
const int maxn = 1048576 + 1;
cc_hash_table<uLL,int> mp; //AC 
//gp_hash_table<uLL,int>  //ÄÚ´æ³¬ÏÞ 
//unordered_map<uLL,int> mp;
string s;
uLL PowP[maxn], H[maxn];
void init() {
	H[0] = s[0];
	PowP[0] = 1;
	for (int i = 1; i < s.size(); i++) {
		H[i] = H[i - 1] * P + s[i];
		PowP[i] = PowP[i - 1] * P;
	}
}
uLL calsub(uLL H[],int i, int j) {
	if (i == 0)
		return H[j];
	return H[j] - H[i - 1] * PowP[j - i + 1];
}
int main() {
	std::ios::sync_with_stdio(false);
	int len;
	cin >> len; cin.ignore();
	getline(cin, s);
	init();
	vector<int> idx;
	int Max = 0;
	uLL sub;
	for (int i = 0; i + len <= s.size(); i++) {
		sub = calsub(H,i, i + len - 1);
		int times = ++mp[sub];
		if (times > Max) {
			Max = times;
			idx.clear();
			idx.push_back(i);
		}
		else if (times == Max) {
			idx.push_back(i);
		}
	}
	string ans = s.substr(idx[0], len);
	for (int i = 1; i < idx.size(); i++)
		ans = min(ans, s.substr(idx[i], len));
	cout << ans << ' ' << Max;
	return 0;
}
/*
4
//A can can can a can.

3
int a=~~~~~~~~~~~~~~~~~~~~~0;
*/
