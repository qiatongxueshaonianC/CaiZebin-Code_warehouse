#pragma warning(disable:4996)
#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
struct Node {
	int data, color;
	Node *left, *right;
	Node() {
		left = right = NULL;
	}
};
int N,k,RT;
vector<int> Post, In;
int dp[maxn][5][3][3];
map<Node*, int> mp;
Node* create(int Inl, int Inr, int Postl, int Postr) {
	if (Postl > Postr) {
		return NULL;
	}
	Node* now = new Node;
	now->data = Post[Postr];
	mp[now] = mp.size();
	int k=Inl;
	for (; k <= Inr; k++) {
		if (In[k] == now->data)
			break;
	}
	int numleft = k - Inl;
	now->left = create(Inl, k-1, Postl, Postl + numleft - 1);
	now->right = create(k + 1, Inr, Postl + numleft, Postr - 1);
	return now;
}
int judge(Node* root) {
	if (root==NULL)
		return 1;
	int temp = root->color == 1 ? 1 : 0;
	int left = judge(root->left);
	int right = judge(root->right);
	if (left == right&&left!=0)
		return temp + left;
	return 0;
}
void DFS(Node* root) {
	if (root->left==NULL&&root->right==NULL)	//虚拟的根节点
		return;
	if (root->color == 2) {
		if (dp[mp[root]][root->color][1][1] != -1)
			return;
		if (root->left != NULL)
			root->left->color = 1, DFS(root->left);
		if(root->right!=NULL)
			root->right->color = 1, DFS(root->right);
		dp[mp[root]][root->color][1][1] = judge(root);
		return;
	}
	else {
		for (int i = 1; i <= 2; i++) {
			if(root->left!=NULL)	root->left->color = i;
			for (int j = 1; j <= 2; j++) {
				if(root->right!=NULL)	root->right->color = j;
				if (dp[mp[root]][root->color][root->left==NULL?1:i][root->right==NULL?1:j] != -1)
					return;
				if(root->left!=NULL)	DFS(root->left);
				if(root->right!=NULL)	DFS(root->right);
				dp[mp[root]][root->color][root->left == NULL ? 1 : i][root->right == NULL ? 1 : j] = judge(root);
			}
		}
		return;
	}
}
int main() {
	scanf("%d", &k);
	while (k--) {
		memset(dp, -1, sizeof(dp));
		scanf("%d", &N);
		Post.resize(N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &Post[i]);
		}
		In = Post;
		sort(In.begin(), In.end());
		Node* root = create(0, N - 1, 0, N - 1);
		RT = root->data;
		root->color = 1;		//1代表黑，2代表红
		DFS(root);
		if (dp[mp[root]][1][1][1]>0 || dp[mp[root]][1][1][2] >0|| dp[mp[root]][1][2][1]>0 || dp[mp[root]][1][2][2]>0)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
/*
3
9
1 4 5 2 8 15 14 11 7
9
1 4 5 8 7 2 15 14 11
8
6 5 8 7 11 17 15 10
*/