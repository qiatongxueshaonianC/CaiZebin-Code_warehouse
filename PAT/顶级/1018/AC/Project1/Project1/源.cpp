#pragma warning(disable:4996)
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
#include<fstream>
#include<ctime>
#include<iterator>
using namespace std;
const int MOD = 1000000007;
struct bigInteger {
	static const int Base = 10000;
	static const int width = 4;
	int digit[40000], size;
	void init() {
		memset(digit, 0, sizeof(digit));
		size = 0;
	}
	void set(int x) {
		init();  //一定要记得
		do {
			digit[size++] = x %Base;
			x /= Base;
		} while (x != 0);
	}
	void set(string s) {
		init();
		int len = s.size() / width + 1;
		for (int i = 0; i < len; i ++) {
			int ed = s.size() - i * width;
			int st = max(0, ed - width);
			sscanf(s.substr(st, ed - st).c_str(), "%d", &digit[size++]);
		}
	}
	void output() {
		for (int i = size-1; i >=0; i--) {
			if (i != size-1)
				printf("%04d", digit[i]);
			else
				printf("%d", digit[i]);
		}
	}
	bigInteger operator *(const bigInteger& u) {
		bigInteger ret;
		ret.init();
		int up = max(u.size, size);
		for (int t = 0; t <= up; t++) {
			for (int i = 0; i <= up; i++) {
				ret.digit[t+i] += digit[i] * u.digit[t];
				ret.digit[t + i+1] += ret.digit[t] % Base;
				ret.digit[t+i] /= Base;
			}
		}
		ret.size = up + up;
		while (ret.size > 1 && ret.digit[ret.size - 1] == 0)
			ret.size--;
		return ret;
	}
	bigInteger operator *(const int& u) {
		bigInteger ret;
		ret.init();
		int carry = 0;
		for (int i = 0; i < size; i++) {
			carry = carry + digit[i] * u;
			ret.digit[ret.size++] = carry % Base;
			carry /= Base;
		}
		while (carry != 0) {
			ret.digit[ret.size++] = carry % Base;
			carry /= Base;
		}
		return ret;
	}
	bigInteger operator +(const bigInteger& u) {
		bigInteger ret;
		ret.init();
		int carry = 0;
		int up = max(size, u.size);
		for (int i = 0; i < up; i++) {
			carry = carry + digit[i] + u.digit[i];
			ret.digit[ret.size++] = carry % Base;
			carry /= Base;
		}
		if (carry != 0) {
			ret.digit[ret.size++] = carry;
		}
		return ret;
	}
	bigInteger operator /(const int& u) {
		bigInteger ret;
		ret.init();
		ret.size = size;
		int remain = 0;
		for (int i = size - 1; i >= 0; i--) {
			remain = remain * Base + digit[i];
			if (remain < u)
				ret.digit[i] = 0;
			else{
				ret.digit[i] = remain / u;
				remain %= u;
			}
		}
		while (ret.size > 1 && ret.digit[ret.size - 1] == 0)
			ret.size--;
		return ret;
	}
	int operator %(const int& u) {
		long long remain = 0;
		for (int i = size - 1; i >= 0; i--) {
			remain = remain * Base + digit[i];
			remain %= u;
		}
		return remain;
	}
}A,B,C;
string s;
int main() {
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] =='0')
			continue;
		for (int j = i; j < s.size(); j++) {
			B.set(s.substr(i, j - i + 1));
			A = A + B;
			A.set( A % MOD);
		}
	}
	A.output();
	return 0;
}
/*
1021
1234567890123456789
*/