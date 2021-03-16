#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<bitset>
using namespace std;
struct Node {
	vector<vector<int> > mp;   //如果定义了初始大小为3则后续无法比较是否相对 
	int x, y,cost;
	string path;
	Node() {
		x = y =-1;
		path = "";
	}
	void f() {
		cost = 0;
		int idx = 1;
		for (int i = 0; i <3; i++) {
			for (int j = 0; j < 3; j++) {
				if (idx == 9)
					break;
				if (mp[i][j] != idx++)
					cost++;
			}
			if (idx == 9)
				break;
		}
	}
	bool operator <(const Node& a)const {
		return cost > a.cost;
	}
}st, ed;
int X[] = { 1,-1,0,0 };
int Y[] = { 0,0,1,-1 };
string PATH = "durl";
map<vector<vector<int> >, bool> flag;
bool judge(Node &s, int X, int Y) {
	if (X < 0 || X>2 || Y < 0 || Y>2) return false;
	swap(s.mp[s.x][s.y], s.mp[X][Y]);
	s.x = X;
	s.y = Y;
	if (flag[s.mp] == true) return false;
	return true;
}
void BFS(Node s) {
	s.f();
	priority_queue<Node> q;
	q.push(s);
	flag[s.mp] = true;
	bool have_ans = false;
	while (!q.empty()) {
		Node now = q.top(); q.pop();
		if (now.cost==0) {
			puts(now.path.c_str());
		/*	puts("ullddrurdllurdruldr");
			for (auto I : now.mp) {
				for (auto j : I)
					cout << j << ' ';
				puts("");
			}*/
			have_ans = true;
			break;
		}
		for (int i = 0; i < 4; i++) {
			Node temp = now;
			int newx = now.x + X[i];
			int newy = now.y + Y[i];
			if (judge(temp, newx, newy)) {
				temp.path = now.path + PATH[i];
				temp.f();
				q.push(temp);
				flag[temp.mp] = true;
			}
		}
	}
	if (!have_ans)
		puts("unsolvable");
}
vector<int> A(9);
int check()  //忽视x，求逆序数
{
	int i, j, cnt = 0;
	for (i = 0; i <= 8; i++)
	{
		if (A[i] == 0) continue;
		for (j = 0; j < i; j++)
		{
			if (A[j] == 0) continue;
			if (A[j] > A[i]) cnt++;
		}
	}
	return cnt;
}
int main() {
	std::ios::sync_with_stdio(false);
	string s;
	while (getline(cin, s)) {
		flag.clear();
		stringstream str(s);
		char c;
		int idx = 0;
		while (str >> c) {
			if (isdigit(c))
				A[idx++] = c - '0';
			else A[idx++] = 0;
		}
		st.mp.resize(3);
		fill(st.mp.begin(), st.mp.end(), vector<int>());
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				st.mp[i].push_back(A[i * 3 + j]);
				if (A[i * 3 + j] == 0) {
					st.x = i;
					st.y = j;
				}
			}
		}
		/*	for (auto I : st.mp) {
				for (auto j : I)
					cout << j << ' ';
				puts("");
			}*/
		if (check() % 2 == 1)
			puts("unsolvable");
		else
			BFS(st);
	}
	return 0;
}
/*
2  3  4  1  5  x  7  6  8
1 5 6 3 2 4 7 8 X
1 2 3 X 4 6 7 5 8
*/
