#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <assert.h>

#define pii pair<int, int>
#define f first
#define s second
#define vipii vector<int, pair<int, int> >
#define ipii pair<int, pair<int, int> >

using namespace std;
typedef long long int ll;

const int N = int(1e5+1);

ll MOD = ll(1e9+7);

#define vi vector<int>
#define vii vector<vi >
#define pb push_back

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int value) {
		left = right = NULL;
		val = value;
	}
};

void bstToDll(TreeNode* cur, TreeNode** head) {
	if(!cur)
		return;
	static TreeNode* pre = NULL;
	bstToDll(cur->left, head);
	if(!pre)
		*head = cur;
	else {
		cur->left = pre;
		pre->right = cur;
	}
	pre = cur;
	bstToDll(cur->right, head);
}

int main() {
	TreeNode *root, *head, *tmp;
	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	bstToDll(root, &head);
	tmp = head;
	cout << tmp->val << ' ';
	while(tmp->right) {
		tmp = tmp->right;
		cout << tmp->val << ' ';
	}
	cout << '\n';
	cout << tmp->val << ' ';
	while(tmp->left) {
		tmp = tmp->left;
		cout << tmp->val << ' ';
	}
	cout << '\n';
	return 0;
}

