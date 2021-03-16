#pragma warning(disable:4996)
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
const int maxn = 50000 * 2 + 5;
int nxt[maxn];
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
	string s1, s2,temp1,temp2;
	while (cin >> s1 >> s2) {
		s1 = s1 + s2;
		getNext(s1);
		if (nxt[s1.size() - 1] == -1)
		//	puts("0");  //������scanf��printf��puts�ȷ���
			cout << "0" << '\n';
		else
			cout << s1.substr(0, nxt[s1.size() - 1] + 1) << ' ' << nxt[s1.size() - 1] + 1 << '\n';
	}
	return 0;
}
/*
clinton
homer
riemann
marjorie
AAAAAA
AAAAA
aaabbbaaabbb
aaabbbaaabbb
*/
