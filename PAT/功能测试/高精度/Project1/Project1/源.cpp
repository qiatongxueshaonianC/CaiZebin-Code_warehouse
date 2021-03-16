#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<climits>
#include<ctime>
#include<iomanip>
#include<fstream>
#include<iomanip>
using namespace std;
int max(int a, int b) {
	return a > b ? a : b;
}
struct BigInteger {
	static const int Base = 10;
	static const int width = 1;
	static const int Max_size = 2000;
	int size = 0;
	int d[Max_size] = { 0 };
	void init() {
		size = 0;
		memset(d, 0, sizeof(d));
	}
	void set(int x) {
		init();
		do {
			d[size++] = x % Base;
			x /= Base;
		} while (x != 0);
	}
	void set(string s) {
		init();
		int len = s.size() / width + 1;
		for (int i = 0; i < len; i++) {
			int ed = s.size() - i * width;
			int st = max(0, ed - width);
			sscanf(s.substr(st, ed - st).c_str(), "%d", &d[size++]);
		}
		while (size > 1 && d[size - 1] == 0)
			size--;
	}
	void output() {
		for (int i = size - 1; i >= 0; i--) {
			if (i == size - 1) {
				cout << d[i];
			}
			else {
				cout  << d[i];
			}
		}
		cout << endl;
	}
	BigInteger operator + (const BigInteger& b) {
		BigInteger res; res.init();
		int carry = 0;
		int len = max(b.size, size);
		auto& B = b.d;
		auto& A = d;
		auto& C = res.d;
		int& sz = res.size;
		for (int i = 0; i < len; i++) {
			carry += A[i] + B[i];
			C[sz++] = carry % Base;
			carry /= Base;
		}
		while (carry != 0) {
			C[sz++] = carry % Base;
			carry /= Base;
		}
		return res;
	}
	BigInteger operator *(const int& b) {
		BigInteger res; res.init();
		auto& A = d;
		auto& C = res.d;
		int& sz = res.size;
		int carry = 0;
		for (int i = 0; i < size; i++) {
			carry += A[i] * b;
			C[sz++] = carry % Base;
			carry /= Base;
		}
		while (carry != 0) {
			C[sz++] = carry % Base;
			carry /= Base;
		}
		return res;
	}
	BigInteger operator *(const BigInteger& b) {
		BigInteger res; res.init();
		auto& A = d;
		auto& B = b.d;
		auto& C = res.d;
		int& sz = res.size;
		sz = size + b.size + 1;
		for (int i = 0; i < size; i++) {
			for (int t = 0; t < b.size; t++) {
				C[i + t] += A[i] * B[t];
				C[i + t + 1] += C[i + t] / Base;
				C[i + t] %= Base;
			}
		}
		while (sz > 1 && C[sz-1] == 0)
			sz--;
		return res;
	}
	BigInteger operator / (const int& b) {
		BigInteger res; res.init();
		auto& A = d;
		auto& C = res.d;
		int& sz = res.size;
		sz = size;
		int remain = 0;
		for (int i = size - 1; i >= 0; i--) {
			remain = remain * Base + A[i];
			C[i] = remain / b;
			remain %= b;
		}
		while (sz > 0 && C[sz - 1] == 0) {
			sz--;
		}
		return res;
	}
	int operator % (const int& b) {
		int remain = 0;
		auto& A = d;
		for (int i = size - 1; i >= 0; i--) {
			remain = remain * Base + A[i];
			remain %= b;
		}
		return remain;
	}
	BigInteger operator -(const BigInteger& b) {
		BigInteger res; res.init();
		auto& A = d;
		auto& B = b.d;
		auto& C = res.d;
		int& sz = res.size;
		int carry = 0;
		for (int i = 0; i < size; i++) {
			int numA = carry + A[i] - B[i]; carry = 0;
			if (numA < 0) {
				carry--;
				numA += 10;
			}
			C[sz++] = numA;
		}
		while (sz > 1 && C[sz - 1] == 0)
			sz--;
		return res;
	}
};
int main() {
//	std::ios::sync_with_stdio(false);
	BigInteger A, B, C;
	A.set(100000); A.output();
	B.set("100000000"); B.output();
	C = B - A; C.output();
	A.set(600);
	B.set("8000");
	C = A * B; C.output();

	A.set(123);
	B.set(124);
	C.set(A%124); C.output();

	A.set("123456");
	B.set("111111");
	C = A + B; C.output();

	A.set("1000000");
	B.set("25");
	C = A / 25; C.output();
	return 0;
}