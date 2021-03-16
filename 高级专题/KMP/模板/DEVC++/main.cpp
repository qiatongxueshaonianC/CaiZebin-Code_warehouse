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
#include<fstream>
#include<ctime> 
#define lowbit(x) x&(-x)
using namespace std;
const int maxn = 1e6;
int Next[maxn];
void GetNext(string s) {
	Next[0] = -1;
	int j = -1;
	for (int i = 1; i < s.size(); i++) {
		while (j != -1 && s[i] != s[j + 1]) {
			j = Next[j];
		}
		if (s[i] == s[j + 1])
			j++;
		Next[i] = j;
	}
}
int KMP(string s1, string s2) {
	int j=-1,ans=0;
	GetNext(s2);
	for (int i = 0; i < s1.size(); i++) {
		while (j != -1 && s1[i] != s2[j + 1]) {
			j = Next[j];		//2020/4/13/21:30发现：注意，这里是j=next[j],切忌写成j=next[i]
		}
		if (s1[i] == s2[j + 1])
			j++;
		if (j == s2.size() - 1) {
			ans++;
			j = Next[j];
		}
	}
	return ans;
}
int main() {
	string s1, s2;
	ifstream infile("D:\\Programing\\PAT\\input.txt",ios::in);
	if (!infile.is_open())
	{
		cout << "未成功打开文件" << endl;
	}

	getline(infile, s1); 
//	cin >> s1 ;
	cout << s1<<endl;
	cin >> s2;
	cout << s2 << endl;
	clock_t start,finish;
	start=clock();
	int k = s1.find(s2,0),ans=0;
	while (k != string::npos) { //75ms
		ans++;
		k = s1.find(s2, k + 1);
	}
	if (ans > 0)
		cout << ans<<endl;
	else
		puts("No");
	finish=clock();
	cout<<finish-start<<"/"<<CLOCKS_PER_SEC<<"(s)"<<endl;
	start=clock();
	ans = KMP(s1, s2);
	if (ans> 0)
		cout << ans << endl;
	else
		puts("No");
	finish=clock();
	cout<<finish-start<<"/"<<CLOCKS_PER_SEC<<"(s)"<<endl;
	return 0;
}
/*
ABCDEFGHIJKLMNOPQRSTUVWXYABCDEFGHIJKLMNOPQRSTUVWXYABCDEFGHIJKLMNOPQRSTUVWXYZ
ATUVWXYZ
TUVWXYZ
*/
