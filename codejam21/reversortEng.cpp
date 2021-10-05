#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <set>
#include <list>
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

bool isPossible(int n, int c) {
	if(c <= n*(n+1)/2 && c >= 1)
		return true;
	return false;
}

vector<int> maxSellStock(int n, int c, vector<int> a) {
	if(c == 0)
		return a;
	vector<int> tmp;
	for(int i = 1 ; i <= n ; i++) {
		if(isPossible(c-i, n-1)) {
			for(int& j : a)
				j++;
			tmp.pb(1);
			tmp.insert(tmp.end(), a.begin(), a.end());
			reverse(tmp.begin(), tmp.begin() + i - 1);
			tmp = maxSellStock(n-1, c-i, tmp);
		}
	}
	return tmp;
}

void trace(vector<int> a) {
	int n = a.size();
	for(int i = 0 ; i < n ; i++) {
		cout << a[i];
		if(i != n-1)
			cout << ' ';
	}
	return;
}

int main() {
	int n;
	int t;
	cin >> t;
	for(int i = 1 ; i <= t ; i++) {
		int c;
		cin >> n >> c;
		vector<int> a;
		cout << "Case #" << i << ": ";
		if(isPossible(n,c)) {
			a = maxSellStock(n,c,a);
			trace(a);
		}
		else
			cout << "IMPOSSIBLE";
		cout << '\n';
	}
	return 0;
}

