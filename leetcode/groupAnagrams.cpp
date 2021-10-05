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


void solve() {
	string s;
	int n;
	cin >> n;
	vector<string> strs(n);
	for(int i = 0 ; i < n ; i++)
		cin >> strs[i];
	map<long long int, vector<string>> m;
	auto ord = [=] (char c) {
		return c - 'a';
	};
	for(int i = 0 ; i < n ; i++) {
		long long int k = 0;
		for(auto j : strs[i])
			k ^= 1<<ord(j);
		m[k].push_back(strs[i]);
	}
	vector<vector<string>> ans;
	for(auto i : m)
		ans.push_back(i.se);
	for(auto i : ans) {
		for(auto j : i)
			cout << j << ' ';
		cout << '\n';
	}
}

int main() {
	solve();
	return 0;
}

