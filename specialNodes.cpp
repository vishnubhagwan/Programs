// Number of special nodes in an n-ary tree
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

vector<int> g[N];
vector<int> a = {0, 2, 1, 4, 3, 4, 8, 10, 2, 5, 1};

void inorder(int u, unordered_set<int> s, int& ans) {
	if(!s.count(a[u]))
		ans++;
	s.insert(a[u]);
	for(auto v:g[u])
		inorder(v, s, ans);
	s.erase(a[u]);
	return;
}

int main() {
	g[1].push_back(2);
    g[1].push_back(3);
    g[2].push_back(4);
    g[2].push_back(5);
    g[2].push_back(6);
    g[3].push_back(7);
    g[5].push_back(8);
    g[5].push_back(9);
    g[5].push_back(10);

    unordered_set<int> s;
    int ans = 0;
	inorder(1, s, ans);
	cout << ans << '\n';
 	return 0;
}
