#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
#include <queue>
#define INF 0x7f7f7f7f
using namespace std;

struct Edge {
	int u;//������㷨���ڽӱ��в�����Ҫ��������������Ƚ�����
	int v;
	int f;//���� 
	int c;//���� 
	int next;
}e[850];//����������Ŀ��Ҫ�ǵñ�������������Ϊ���з���
int head[170];
int n, m, s, t;
int ecnt = 0;
inline void AddEdge(int _u, int _v, int _f, int _c) {
	e[ecnt].next = head[_u];
	head[_u] = ecnt;
	e[ecnt].u = _u;
	e[ecnt].v = _v;
	e[ecnt].f = _f;
	e[ecnt].c = _c;
	ecnt++;
}
inline void Add(int _u, int _v, int _f, int _c) {
	AddEdge(_u, _v, _f, _c);
	AddEdge(_v, _u, 0, -_c);
}

int dis[170];
bool inq[170];
int pre[170];
bool SPFA() {
	queue <int> q;
	q.push(s);
	memset(dis, 0x7f, sizeof(dis));
	memset(inq, 0, sizeof(inq));
	memset(pre, -1, sizeof(pre));
	inq[s] = true;
	dis[s] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		inq[cur] = false;
		for (int i = head[cur]; i != -1; i = e[i].next) {
			if (e[i].f != 0 && dis[e[i].v] > dis[cur] + e[i].c) {
				dis[e[i].v] = dis[cur] + e[i].c;
				pre[e[i].v] = i;
				if (!inq[e[i].v]) {
					inq[e[i].v] = true;
					q.push(e[i].v);
				}
			}
		}
	}
	return dis[t] != INF;
}

void MICMAF(int &flow, int &cost) {
	flow = 0;
	cost = 0;
	while (SPFA()) {
		int minF = INF;
		for (int i = pre[t]; i != -1; i = pre[e[i].u]) minF = min(minF, e[i].f);
		flow += minF;
		for (int i = pre[t]; i != -1; i = pre[e[i].u]) {
			e[i].f -= minF;
			e[i ^ 1].f += minF;
		}
		cost += dis[t] * minF;
	}
}
/*
�ڵ��Ź���
Դ�㣺0
����ڵ�(��)��n*x+y+1
����ڵ�(��)��n*n+n*x+y+1
��㣺2*n*n+1
*/
int g[10][10];
inline int hashin(int x, int y) {
	return n * x + y + 1;
}
inline int hashout(int x, int y) {
	return n * n + n * x + y + 1;
}
int main() {
	memset(head, -1, sizeof(head));
	scanf("%d", &n);
	int x, y, v;
	while (scanf("%d%d%d", &x, &y, &v) == 3) {
		if (x == 0 && y == 0 && v == 0) break;
		x--;
		y--;
		g[x][y] = v;
	}
	s = 0;
	t = 2 * n * n + 1;
	Add(s, 1, 2, 0);
	Add(2 * n*n, t, 2, 0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int in = hashin(i, j);
			int out = hashout(i, j);
			Add(in, out, 1, 0);//�ڽӱ��к������ȱ�����������f=1����Ϊֻ�����پ���һ��
			Add(in, out, 1, -g[i][j]);
			if (i != n - 1) Add(out, hashin(i + 1, j), 2, 0);
			if (j != n - 1) Add(out, hashin(i, j + 1), 2, 0);
		}
	int f, c;
	MICMAF(f, c);
	printf("%d\n", -c);
	return 0;
}
/*
8
2 3 13
2 6  6
3 5  7
4 4 14
5 2 21
5 6  4
6 3 15
7 2 14
0 0  0
*/