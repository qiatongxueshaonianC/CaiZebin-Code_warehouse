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
#include<bitset>
using namespace std;
struct bigInteger {
	static const int Base = 10000000;
	static const int maxdigit = 1010;
	long long digit[maxdigit];
	long long size;
	void init() {
		memset(digit, 0, sizeof(digit));
		size = 0;
	}
	void set(int x) {
		init();
		do {
			digit[size++] = x % Base;
			x /= Base;
		} while (x != 0);
	}
	void output() {
		for (int i = size - 1; i >= 0; i--) {
			if (i == size - 1)
				printf("%d", digit[i]);
			else
				printf("%07d", digit[i]);
		}
		puts("");
	}
	/*	bigInteger operator * (const bigInteger& b)const {
			bigInteger ret;
			ret.init();
			int up = max(size, b.size);
			for (int t = 0; t < up; t++) {
				for (int i = 0; i < up; i++) {
					ret.digit[t + i] += digit[t] * b.digit[i];
					ret.digit[t + i + 1] += ret.digit[t + i] / Base;
					ret.digit[t + i] = ret.digit[t + i] % Base;
				}
			}
			ret.size = up + up;
			while (ret.size > 1 && ret.digit[ret.size - 1] == 0)
				ret.size--;
			return ret;
		}*/
	bigInteger operator * (const int& b)const {
		bigInteger ret;
		ret.init();
		int carry = 0;
		for (int i = 0; i < size; i++) {
			carry = digit[i]*b + carry;
			ret.digit[ret.size++] = carry % Base;
			carry = carry / Base;
		}
		while (carry != 0) {
			ret.digit[ret.size++] = carry % Base;
			carry = carry / Base;
		}
		return ret;
	}
	bigInteger operator + (const bigInteger& b)const {
		bigInteger ret;
		ret.init();
		int carry = 0;
		for (int i = 0; i < size || i < b.size; i++) {
			carry = digit[i] + b.digit[i] + carry;
			ret.digit[ret.size++] = carry % Base;
			carry = carry / Base;
		}
		if (carry != 0)
			ret.digit[ret.size++] = carry;
		return ret;
	}
	bigInteger operator /(const int& x)const {
		bigInteger ret;
		ret.init();
		ret.size = size;
		int remain = 0;
		for (int i = size - 1; i >= 0; i--) {
			remain = remain * Base + digit[i];
			ret.digit[i] = remain / x;
			remain = remain % x;
		}
		while (ret.size > 1 && ret.digit[ret.size - 1] == 0)
			ret.size--;
		return ret;
	}
	int operator % (const int&x)const {
		int remain = 0;
		for (int i = size - 1; i >= 0; i--) {
			remain = remain * Base + digit[i];
			remain = remain % x;
		}
		return remain;
	}
}a,b,c,d;
int n, m,T;
string s;
int main() {
	scanf("%d%*c", &T);
	while (T--) {
		m = 16; n = 8;
		getline(cin, s);
		a.set(0);
		b.set(1);
		for (int i = s.size() - 1; i >= 0; i--) {
			int num = isdigit(s[i]) ? s[i] - '0' : s[i] - 'A' + 10;
			a = a + b * num;
			b = b * m;
		}
		char ans[1010];
		int size = 0;
		do {
			int num = a % n;
			char c = num >= 10 ? num - 10 + 'a' : num + '0';
			ans[size++] = c;
			a = a / n;
		} while (!(a.digit[0] == 0 && a.size == 1));
		for (int i = size - 1; i >= 0; i--)
			printf("%c", ans[i]);
		puts("");
	}
	return 0;
}
/*
2
39
123ABC
  */