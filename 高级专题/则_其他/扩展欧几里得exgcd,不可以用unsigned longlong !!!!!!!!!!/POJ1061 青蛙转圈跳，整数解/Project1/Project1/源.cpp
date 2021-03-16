#include<iostream>
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
#include<list>
#include<stack>
#include<iomanip>
#include<ctime>
#include<fstream>
using namespace std;
typedef long long LL;
LL x, y, n, m, L;
LL t, k;
LL exgcd(LL a, LL b, LL& x, LL& y) {
	if (b == 0) {
		x = 1; y = 0;
		return a;
	}
	LL d = exgcd(b, a%b, y, x);
	y -= (a / b)*x;
	return d;
}
int main() {
	std::ios::sync_with_stdio(false);
	//	cin.tie(NULL);
	cin >> x >> y >> m >> n >> L;
	LL a = n - m, b = L, c = x - y;	//2020/6/19/15：01注意这里的顺序，m-n~y-x
	LL x0, y0;
	LL d = exgcd(a, b, x0, y0);
	x0 = x0 * (c / d);
	y0 = y0 * (c / d);
	if (c % d)
		puts("Impossible");
	else {
		t = x0 * d / b;
		x0 = x0 - t * b / d;

		if (x0 < 0)
			x0 += b / d;
		cout << x0 << endl;
	}
	return 0;
}
/*
1 2 3 4 5
*/