#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <set>
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
#define vii vector<vector<int> >
#define pb push_back

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

int maxSellStock(vector<int> a) {
	int n = a.size();
	int mn = 0;
	int idx = -1;
	map<int, int> m, mm;
	set<int> S;
	for(int i = 0 ; i < n ; i++)
		m[a[i]] = i, S.insert(a[i]), mm[i] = a[i];
	int ans = 0;
	for(int i = 0 ; i < n-1 ; i++) {
		auto it = S.begin();
		int idx = m[*it];
		for(auto j : mm)
			if(j.f >= i && j.f <= idx)
				m[j.s] = i + idx - j.f;
		for(auto j : m)
			if(j.s <= idx && j.s >= i)
				mm[j.s] = j.f;
		ans += idx-i+1;
		S.erase(it);
		m.erase(*it);
		mm.erase(i);
	}
	return ans;
}

int main() {
	int n;
	int t;
	cin >> t;
	for(int i = 1 ; i <= t ; i++) {
		cin >> n;
		vector<int> a(n);
		for(int i = 0 ; i < n ; i++)
			cin >> a[i];
		cout << "Case #" << i << ": " <<  maxSellStock(a) << endl;
	}
	return 0;
}

