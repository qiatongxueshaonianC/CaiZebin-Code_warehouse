#include<bits/stdc++.h>
using namespace std;
struct intComp {
	bool operator() (const int& lhs, const int& rhs) const{
		return lhs > rhs;
	}
};
struct strComp
{
	bool operator() (const string& str1, const string& str2) const {
		return str1.length() < str2.length();
	}
};
int main() {
	int a[] = {10, 20, 30, 40, 50};
	set<int, intComp> s1(a, a + 5);
	for (auto it = s1.cbegin(); it != s1.cend(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	string b[] = {"apple", "banana", "pear", "orange", "strawberry"};
	set<string, strComp > s2(b, b + 5);
	cout<<"按照字符串长度："<<endl;
	cout<<"banana和orange的长度一样，会去重:"<<"s2.size()="<<s2.size()<<endl; 
	for (auto it = s2.cbegin(); it != s2.cend(); it++)//交换一下orange和banana的顺序，输出的是在前的那个 
	{
		cout << *it <<endl;
	}
	cout<<"逆的默认顺序:"<<endl; 
	set<string,greater<string>> s4(b,b+5);
	for(auto i:s4)
		puts(i.c_str());
	return 0;
}
