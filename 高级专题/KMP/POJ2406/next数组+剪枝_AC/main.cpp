#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<climits>
#include<numeric>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<iterator>
using namespace std;
const int maxn = 1e6 + 10;
int T, nxt[maxn];
string s;
void getNext(string s) {
	int j = -1;
	nxt[0] = -1;
	for (int i = 1; i < s.size(); i++) {
		while (j != -1 && s[i] != s[j + 1])
			j = nxt[j];
		if (s[i] == s[j + 1])
			j++;
		nxt[i] = j;
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	while (getline(cin, s) && s != ".") {
		getNext(s);
		string s1 = "";
		bool flag = false;
		for (int i = 0; i < nxt[s.size() - 1] + 1; i++) {
			int ans = 0, pos=0;
			s1 += s[i];
			int len = s1.size();
			if (s.size() % len != 0)	//ÕâÀï¼ôÖ¦ 
				continue;
			while (s.substr(pos, len) == s1) {
				ans++;
				pos += len;
			}
			if (pos == s.size()) {
				cout << ans << '\n';
				flag = true;
				break;
			}
		}
		if (!flag)
			cout << '1' << '\n';
	}
	return 0;
}
/*
aabaabaa
abcd
aaaa
ababab
aabaabaabaab
.
*/
