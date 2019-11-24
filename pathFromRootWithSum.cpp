// Print all the paths from root, with a specified sum in Binary tree
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
	int val;
	node *left, *right;
	node(): left(NULL), right(NULL) {}
};

node* newNode(int val) {
	node* c = (node*) malloc(sizeof(node));
	c->val = val;
	return c;
}

void preorder(node* root, int sum, vector<int> ans) {
	if(root == NULL || sum < 0) return;
	sum -= root->val;
	ans.push_back(root->val);
	if(sum == 0) {
		for(auto i:ans)
			cout << i << ' ';
		cout << '\n';
		return;
	}
	if(root->left != NULL)
		preorder(root->left, sum, ans);
	if(root->right != NULL)
		preorder(root->right, sum, ans);
	ans.pop_back();
	return;
}

int main() {
	node* root  = newNode(10); 
    root->left  = newNode(28); 
    root->right = newNode(13); 
  
    root->right->left   = newNode(14); 
    root->right->right  = newNode(15); 
  
    root->right->left->left   = newNode(21); 
    root->right->left->right  = newNode(22); 
    root->right->right->left  = newNode(23); 
    root->right->right->right = newNode(24); 
  
    int sum = 38;
  	vector<int> ans;
	preorder(root, sum, ans); 
 	return 0;
}
