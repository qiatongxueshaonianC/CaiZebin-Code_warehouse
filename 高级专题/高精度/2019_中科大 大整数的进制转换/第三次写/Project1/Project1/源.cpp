#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<climits>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<bitset>
using namespace std;
int n, m;
string s;
struct bigInteger {
	static const int Base = 10000;
	static const int width = 4;
	int digit[1010];
	int size;
	void init() {
		memset(digit, 0, sizeof(digit));
		size = 0;
	}
	void set(int x) {
		init();				//2020/3/16/1:00发现，这里要初始化
		do {
			digit[size++] = x % Base;
			x /= Base;
		} while (x != 0);
	}
	void set(string s) {
		init();
		int len = s.size() / width + 1;
		for (int i = 0; i < len; i++) {
			int ed = s.size() - i * width;
			int st =max(0, ed - width);
			sscanf(s.substr(st, ed - st).c_str(), "%d", &digit[size++]);
		}
	}
	void output() {
		for (int i = size - 1; i >= 0; i--) {
			if (i == size - 1)
				printf("%d", digit[i]);
			else
				printf("%04d", digit[i]);
		}
		puts("");
	}
	bigInteger operator * (const bigInteger& b) {
		bigInteger ret;
		ret.init();  
		int up = max(size, b.size);
		for (int t = 0; t < up; t++) {
			for (int i = 0; i < up; i++) {
				ret.digit[t + i] += digit[t] * b.digit[i];
				ret.digit[t + i + 1] += ret.digit[t + i] / Base;  //高位是用除的
				ret.digit[t + i] = ret.digit[t + i] % Base;
			}
		}
		ret.size = up + up;
		while (ret.size > 1 && ret.digit[ret.size - 1] == 0)
			ret.size--;
		return ret;
	}
	bigInteger operator *(const int& b) {
		bigInteger ret;
		ret.init();
		int carry = 0;
		for (int i = 0; i < size; i++) {
			carry = carry + b * digit[i];
			ret.digit[ret.size++] = carry % Base;
			carry /= Base;
		}
		while (carry != 0) {
			ret.digit[ret.size++] = carry % Base;
			carry /= Base;
		}
		return ret;
	}
	bigInteger operator + (const bigInteger& b) {
		bigInteger ret;
		ret.init();
		int carry = 0;
		for (int i = 0; i < size || i < b.size; i++) {
			carry = carry + digit[i] + b.digit[i];
			ret.digit[ret.size++] = carry %Base;
			carry = carry / Base;
		}
		if (carry != 0)
			ret.digit[ret.size++] = carry;
		return ret;
	}
	bigInteger operator / (const int& x){
		bigInteger ret;
		ret.init();
		ret.size = size;
		int remain = 0;
		for (int i = size - 1; i >= 0; i--) {
			remain = remain * Base + digit[i];
			if (remain < x)
				ret.digit[i] = 0;
			else {
				ret.digit[i] = remain / x;  //2020/3/16/00:50发现，这里是x不是Base!!!!
				remain = remain % x;
			}
		}
		while (ret.size > 1 && ret.digit[ret.size - 1] == 0)
			ret.size--;
		return ret;
	}
	int operator % (const int& x) {
		int remain = 0;
		for (int i = size - 1; i >= 0; i--) {
			remain = remain * Base + digit[i];
			remain = remain % x;  //2020/3/16/1:10发现，这里是x不是Base!!!!
		}
		return remain;
	}
}a,b,c,d;
int main() {
	a.set("1234567890123456789");
	a.output();
	while (scanf("%d%d%*c", &m, &n) != EOF) {
		getline(cin, s);
		puts(s.c_str());
		a.set(0);
		b.set(1);
		for (int i = s.size() - 1; i >= 0; i--) {
			int num = isdigit(s[i]) ? s[i] - '0' : s[i] - 'A' + 10;
			d.set(num);
			a = a + b * d;
			d.set(m);
			b = b * d;
		//	b.output();
		}
		char ans[1010];
		int size = 0;
		do {
			int num = a % n;
			if (num >= 10)
				ans[size++] = num - 10 + 'a';
			else
				ans[size++] = num + '0';
			a = a / n;
		} while (a.digit[0] != 0 || a.size != 1);
		for (int i = size - 1; i >= 0; i--)
			printf("%c", ans[i]);
		puts("");
	}
	return 0;
}
/*
16 2
FFFF
*/