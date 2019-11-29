// Minimum no. of iterations to pass information to all nodes in the tree
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

class Tree {
private:
	vector<vector<int> > tree;
	vector<bool> vis;
	int n;
	vector<int> size;
	void dfs_sizes(int u) {
		size[u] = tree[u].size();
		for(auto v:tree[u]) {
			dfs_sizes(v);
			size[u] += size[v];
		}
		return;
	}

	vector<pair<int, int> > sort_sizes(vector<int> a, vector<int> b) {
		vector<pair<int, int> > ans;
		for(int i = 0 ; i < a.size() ; i++)
			ans.pb({b[a[i]], a[i]});
		sort(ans.begin(), ans.end());
		reverse(ans.begin(), ans.end());
		return ans;
	}

	void dfs(int u, int cnt = 0) {
		vector<pair<int, int> > child;
		vector<pair<int, int> > g = sort_sizes(tree[u], size);
		for(auto v:g)
			dfs(v.s, cnt+1), cnt++;
		ans = max(ans, cnt);
	}

public:
	int ans = 0;
	Tree(int n) {
		this->n = n;
		tree.resize(n);
		vis.resize(n);
		size.resize(n);
	}

	void addChild(int u, int v) {
		tree[u].pb(v);
	}

	void find_ans() {
		dfs_sizes(0);
		dfs(0);
	}
};

int main() {
	// TestCase 1 
    Tree tree1(17); 
    tree1.addChild(0, 1); 
    tree1.addChild(0, 2); 
    tree1.addChild(0, 3); 
    tree1.addChild(0, 4); 
    tree1.addChild(0, 5); 
    tree1.addChild(0, 6); 
   
    tree1.addChild(1, 7); 
    tree1.addChild(1, 8); 
    tree1.addChild(1, 9); 
   
    tree1.addChild(4, 10); 
    tree1.addChild(4, 11); 
   
    tree1.addChild(6, 12); 
   
    tree1.addChild(7, 13); 
    tree1.addChild(7, 14); 
    tree1.addChild(10, 15); 
    tree1.addChild(11, 16); 
   	tree1.find_ans();
    cout << "TestCase 1 - Minimum Iteration: "
         << tree1.ans << endl; 
   
    // TestCase 2 
    Tree tree2(3); 
    tree2.addChild(0, 1); 
    tree2.addChild(0, 2); 
   	tree2.find_ans();
    cout << "TestCase 2 - Minimum Iteration: "
         << tree2.ans << endl; 
   
    // TestCase 3 
    Tree tree3(1); 
   	tree3.find_ans();
    cout << "TestCase 3 - Minimum Iteration: "
         << tree3.ans << endl; 
   
    // TestCase 4 
    Tree tree4(6); 
    tree4.addChild(0, 1); 
    tree4.addChild(1, 2); 
    tree4.addChild(2, 3); 
    tree4.addChild(3, 4); 
    tree4.addChild(4, 5); 
   	tree4.find_ans();
    cout << "TestCase 4 - Minimum Iteration: "
         << tree4.ans << endl; 
   
    // TestCase 5 
    Tree tree5(6); 
    tree5.addChild(0, 1); 
    tree5.addChild(0, 2); 
    tree5.addChild(2, 3); 
    tree5.addChild(2, 4); 
    tree5.addChild(2, 5); 
   	tree5.find_ans();
    cout << "TestCase 5 - Minimum Iteration: "
         << tree5.ans << endl; 
   
    // TestCase 6 
    Tree tree6(6); 
    tree6.addChild(0, 1); 
    tree6.addChild(0, 2); 
    tree6.addChild(2, 3); 
    tree6.addChild(2, 4); 
    tree6.addChild(3, 5); 
   	tree6.find_ans();
    cout << "TestCase 6 - Minimum Iteration: "
         << tree6.ans << endl; 
   
    // TestCase 7 
    Tree tree7(14); 
    tree7.addChild(0, 1); 
    tree7.addChild(0, 2); 
    tree7.addChild(0, 3); 
    tree7.addChild(1, 4); 
    tree7.addChild(2, 5); 
    tree7.addChild(2, 6); 
    tree7.addChild(4, 7); 
    tree7.addChild(5, 8); 
    tree7.addChild(5, 9); 
    tree7.addChild(7, 10); 
    tree7.addChild(8, 11); 
    tree7.addChild(8, 12); 
    tree7.addChild(10, 13); 
   	tree7.find_ans();
    cout << "TestCase 7 - Minimum Iteration: "
         << tree7.ans << endl; 
   
    // TestCase 8 
    Tree tree8(14); 
    tree8.addChild(0, 1); 
    tree8.addChild(0, 2); 
    tree8.addChild(0, 3); 
    tree8.addChild(0, 4); 
    tree8.addChild(0, 5); 
    tree8.addChild(1, 6); 
    tree8.addChild(2, 7); 
    tree8.addChild(3, 8); 
    tree8.addChild(4, 9); 
    tree8.addChild(6, 10); 
    tree8.addChild(7, 11); 
    tree8.addChild(8, 12); 
    tree8.addChild(9, 13); 
   	tree8.find_ans();
    cout << "TestCase 8 - Minimum Iteration: "
         << tree8.ans << endl; 
  
    // TestCase 9 
    Tree tree9(25); 
    tree9.addChild(0, 1); 
    tree9.addChild(0, 2); 
    tree9.addChild(0, 3); 
    tree9.addChild(0, 4); 
    tree9.addChild(0, 5); 
    tree9.addChild(0, 6); 
  
    tree9.addChild(1, 7); 
    tree9.addChild(2, 8); 
    tree9.addChild(3, 9); 
    tree9.addChild(4, 10); 
    tree9.addChild(5, 11); 
    tree9.addChild(6, 12); 
  
    tree9.addChild(7, 13); 
    tree9.addChild(8, 14); 
    tree9.addChild(9, 15); 
    tree9.addChild(10, 16); 
    tree9.addChild(11, 17); 
    tree9.addChild(12, 18); 
      
    tree9.addChild(13, 19); 
    tree9.addChild(14, 20); 
    tree9.addChild(15, 21); 
    tree9.addChild(16, 22); 
    tree9.addChild(17, 23); 
    tree9.addChild(19, 24); 
  
   	tree9.find_ans();
    cout << "TestCase 9 - Minimum Iteration: "
         << tree9.ans << endl; 
   
    return 0;
}
