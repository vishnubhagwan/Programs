// Print Left View of a Binary Tree
#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<queue>
#define f first
#define s second
using namespace std;
typedef long long ll;

#define pb push_back
#define MAX ll(1e9+1)
#define N int(1e6+1)

struct node {
	int value;
	node *left, *right;
	node(int value): value(value), left(NULL), right(NULL) {}
};

node* newNode(int value) {
	return new node(value);
}

void leftView(node* root, int level = 0) {
	static int maxLevel = -1;
	if(root == NULL)
		return;
	if(level > maxLevel) {
		cout << root->value << ' ';
		maxLevel = max(level, maxLevel);
	}
	leftView(root->left, level + 1);
	leftView(root->right, level + 1);
}

int main() {
	node* root = newNode(12); 
    root->left = newNode(10); 
    root->right = newNode(30); 
    root->right->left = newNode(25); 
    root->right->right = newNode(40); 
  
    leftView(root);
    cout << '\n';
    return 0;
}
