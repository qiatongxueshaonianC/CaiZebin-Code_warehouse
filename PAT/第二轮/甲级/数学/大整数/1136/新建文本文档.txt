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
#include<bitset>
#include<list>
using namespace std;
struct bigInteger {
	static const int Base = 10;
	static const int width = 1;
	int digit[1010];
	int size;
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
	void set(const string& s) {
		init();
		int x,len = (s.size() - 1) / width + 1;
		for (int i = 0; i < len; i++) {
			int ed = s.size() - i * width;
			int st = max(0, ed - width);
			sscanf(s.substr(st, ed - st).c_str(), "%d", &x);
			digit[size++] = x;
		}
	}
	void output() {
		for (int i = size - 1; i >= 0; i--) 
			printf("%d", digit[i]);
	}
	bigInteger operator *(const int& b)const {
		bigInteger ret;
		ret.init();
		int carry = 0;
		for (int i = 0; i < size; i++) {
			carry = carry + digit[i]*b;
			ret.digit[ret.size++] = carry % Base;
			carry /= Base;
		}
		while (carry != 0) {
			ret.digit[ret.size++] = carry % Base;
			carry /= Base;
		}
		return ret;
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
	bigInteger operator +(const bigInteger& b)const {
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
		int remain = 0;
		for (int i = size - 1; i >= 0; i--) {
			remain = remain * Base + digit[i];
			ret.digit[i] = remain % x;
			remain = remain / x;
		}
		ret.size = size;
		while (ret.size > 1 && ret.digit[ret.size - 1] == 0)
			ret.size--;
		return ret;
	}
	int operator % (const int& x)const {
		int remain = 0;
		for (int i = size - 1; i >= 0; i--) {
			remain = remain * Base + digit[i];
			remain = remain % Base;
		}
		return remain;
	}
	bool isPalindromic() {
		for (int i = 0, j =size - 1; i < j;) {
			if (digit[i++] != digit[j--])
				return false;
		}
		return true;
	}
	bigInteger reverse() {
		bigInteger ret;
		ret.init();
		for (int i = size - 1; i >= 0; i--)
			ret.digit[ret.size++] = digit[i];
		return ret;
	}
};
string s,s2;
int main() {
	bigInteger A,B;
	getline(cin, s);
	s2 = s; reverse(s2.begin(), s2.end());
	A.set(s); B.set(s2);
	if (A.isPalindromic())
		printf("%s is a palindromic number.", s.c_str());
	else {
		bool flag = false;
		for (int i = 0; i < 10; i++) {
			A.output(); printf(" + "); B.output(); printf(" = ");
			A = A + B;
			A.output(); puts("");
			if (A.isPalindromic()) {
				A.output(), printf(" is a palindromic number.");
				flag = true;
				break;
			}
			B = A.reverse();
		}
		if (!flag) {
			puts("Not found in 10 iterations.");
		}
	}

	return 0;
}
/*
97152
196
*/