#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
using namespace std;
struct Node {
	int data,height;
	Node* left, *right;
	Node(int a) {
		data = a;
		height = 1;
		left = right = NULL;
	}
	Node() {};
};
int N;
int max(int a, int b) {
	return a > b ? a : b;
}
int get_Height(Node* root) {
	if (root == NULL)
		return 0;
	return root->height;
}
void update_Height(Node*& root) {
	root->height=max(get_Height(root->left), get_Height(root->right)) + 1;
}
int get_balance_factor(Node* root) {
	return get_Height(root->left) - get_Height(root->right);
}
void L(Node*& root) {	//左边长
	Node* temp = root->left;
	root->left = temp->right;
	temp->right = root;
	update_Height(root);
	update_Height(temp);
	root = temp;
}
void R(Node*& root) {	//右边长
	Node* temp = root->right;
	root->right = temp->left;
	temp->left = root;
	update_Height(root);
	update_Height(temp);
	root = temp;
}
void adjust(Node*& root) {
	update_Height(root);
	int fac = get_balance_factor(root);
	if (fac == -2) {
		if (get_balance_factor(root->right) == -1) {	//RR型		这里指的是右边长
			R(root);
		}
		else {	//RL型
			L(root->right);
			R(root);
		}
	}
	else if (fac == 2) {
		if (get_balance_factor(root->left) == 1) {		//LL
			L(root);
		}
		else {		//LR
			R(root->left);
			L(root);
		}
	}
}
void Insert(Node*& root, int u) {
	if (root == NULL) {
		root = new Node(u);
		return;
	}
	if (root->data < u) {
		Insert(root->right, u);
		adjust(root);
	}
	else {
		Insert(root->left, u);
		adjust(root);
	}
}
int main() {
	scanf("%d", &N);
	Node* root = NULL;
	for (int i = 0; i < N; i++) {
		int u; scanf("%d", &u);
		Insert(root, u);
	}
	printf("%d\n", root->data);
	return 0;
}
/*5
88 70 61 96 120

7
88 70 61 96 120 90 65
*/