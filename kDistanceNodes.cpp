// Printing all nodes at distance K from given target node
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

void findKDown(node* root, int k) {
	if(k < 0 || root == NULL)
		return;
	if(k==0) {
		cout << root->value << ' ';
		return;
	}
	findKDown(root->left, k-1);
	findKDown(root->right, k-1);
	return;
}

int findKDistance(node* root, node* target, int k) {
	if(root == NULL)
		return -1;
	if(root == target) {
		findKDown(root, k);
		return 0;
	}
	int dLeft = findKDistance(root->left, target, k);
	if(dLeft != -1) {
		if(dLeft + 1 == k)
			cout << root->value << ' ';
		findKDown(root->right, k - dLeft - 2);
		return dLeft+1;
	}
	int dRight = findKDistance(root->right, target, k);
	if(dRight != -1) {
		if(dRight + 1 == k)
			cout << root->value << ' ';
		findKDown(root->left, k - dRight - 2);
		return dRight+1;
	}
	return -1;
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
	node* target = root->left;
	int k = 1;
	findKDistance(root, target, k);
	cout << '\n';
	return 0;
}
