// Maximum width of binary tree using Level order traversal (queue)
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

void findWidth(node* root) {
	queue<pair<node*, int> > q;
	q.push({root, 0});
	int ans = 0;
	while(!q.empty()) {
		int cnt = q.size();
		ans = max(ans, cnt);
		while(cnt--) {
			auto t = q.front();
			node* p = t.f;
			q.pop();
			int level = t.s;
			if(p->left)
				q.push({p->left, level+1});
			if(p->right)
				q.push({p->right, level+1});
		}
	}
	cout << ans << '\n';
	return;
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
	findWidth(root);
	return 0;
}
