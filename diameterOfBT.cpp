// Diameter of binary tree using postorder traversal - O(n)
#include<iostream>
#include<vector>
#include<set>
#include<list>
#include<unordered_set>
#include<algorithm>
#include<queue>
#define f first
#define s second
using namespace std;
typedef long long ll;

#define pb push_back
#define MAX ll(1e18+1)
#define N int(1e6+1)

struct node {
	node* left;
	node* right;
	int value;
};

node* newNode(int val) {
	node* c = (node*) malloc(sizeof(node));
	c->value = val;
	c->left = c->right = NULL;
	return c;
}

int ans;

int diameter(node* root) {
	if(!root) return 0;
	int level_left = diameter(root->left);
	int level_right = diameter(root->right);
	ans = max(ans, level_left + level_right + 1);
	return max(level_left, level_right) + 1;
}

int main() {
	node* root = NULL;
	root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->right = newNode(8);
	root->right->right->left = newNode(6);
	root->right->right->right = newNode(7);
	diameter(root);
	cout << ans << '\n';
	return 0;
}
