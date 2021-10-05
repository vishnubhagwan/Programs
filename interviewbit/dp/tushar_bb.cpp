#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <assert.h>

#define pii pair<int, int>
#define f first
#define s second
#define vipii vector<int, pair<int, int> >
#define ipii pair<int, pair<int, int> >
#define pb push_back

using namespace std;
typedef long long int ll;

const int N = int(1e5+1);

ll MOD = ll(1e9+7);

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

vector<int> f(int k, vector<int> a) {
	int t = int(1e9);
	int p = 0;
	vector<int> ans;
	int n = a.size();
	for(int i = 0 ; i < n ; i++) {
		if(t > a[i])
			t = a[i], p = i;
	}
	if(k/t > p) {
		for(int i = 0 ; i < k/t ; i++)
			ans.pb(t);
		return ans;
	}
	int m = k/t;
	for(int i = 0 ; i < p && m > 0 ; i++)
		if(k-a[i] >= (m-1) * a[p])
			k-=a[i], m--, ans.push_back(i);
	return ans;
}

int main() {
	int k,n;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	vector<int> ans = f(k,a);
	for(auto i : ans) cout << i << ' '; cout << '\n';
	return 0;
}
