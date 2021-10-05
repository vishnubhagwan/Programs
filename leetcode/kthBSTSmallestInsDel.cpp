#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <assert.h>

#define pii pair<int, int>
#define fi first
#define se second
#define vipii vector<int, pair<int, int> >
#define ipii pair<int, pair<int, int> >

using namespace std;
typedef long long int ll;

const int N = int(1e5+1);

ll MOD = ll(1e9+7);

#define vi vector<int>
#define vii vector<vector<int> >
#define pb push_back

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

typedef struct TreeNode {
	int val;
	TreeNode *left, *right;
	list<int>* ptr;
	TreeNode(int val) {
		this->val = val;
		left = right = NULL;
	}
} TreeNode;

TreeNode* insert(TreeNode* root, int m) {
	if(!root)
		return new TreeNode(m);
	if(root->val >= m)
		root->left = insert(root->left, m);
	else
		root->right = insert(root->right, m);
	return root;
}

list<TreeNode*> order;

void inorder(TreeNode* root) {
	if(!root)
		return;
	inorder(root->left);
	order.push_back(root->val);
	root->ptr = &order.back();
	inorder(root->right);
}

void print(TreeNode* root) {
	if(!root)
		return;
	print(root->left);
	cout << root->val << ' ';
	print(root->right);
}

int main() {
	int n, q;
	cin >> q;
	TreeNode* root = NULL;
	while(q--) {
		int m;
		char c;
		cin >> c;
		if(c == 'I') {
			cin >> m;
			root = insert(root, m);
		}
		else if(c == 'D') {
			cin >> m;
			root = delete(root, m);
		}
		else {
			print(root);
			cout << '\n';
		}
	}
	return 0;
}
