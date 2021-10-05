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

typedef struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		left = right = NULL;
	}
} TreeNode;

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

void inorder(TreeNode* root) {
	if(!root)
		return;
	inorder(root->left);
	cout << root->val << ' ';
	inorder(root->right);
}

int solve(TreeNode* root, int k) {
	stack<TreeNode*> st;
	TreeNode* tmp = root;
	while(tmp)
		st.push(tmp), tmp = tmp->left;
	k--;
	while(!st.empty() && k-- > 0) {
		tmp = st.top();
		st.pop();
		if(tmp->right) {
			tmp = tmp->right;
			while(tmp)
				st.push(tmp), tmp = tmp->left;
		}
	}
	return st.top()->val;
}

int main() {
	TreeNode* root;
	int k;
	root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->right = new TreeNode(6);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(4);
	root->left->left->left = new TreeNode(1);
	k = 1;
	cout << solve(root, k) << '\n';
	return 0;
}
