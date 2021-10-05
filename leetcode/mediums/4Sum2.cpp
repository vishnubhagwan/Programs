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

int solve(vector<int> a, vector<int> b, vector<int> c, vector<int> d) {
	int n = a.size();
	map<int, int> m;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			m[a[i]+b[j]]++;
	int ans = 0;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			ans += m.count(-c[i]-d[j]) ? m[-c[i]-d[j]] : 0;
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n), c(n), d(n);
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	for(int i = 0 ; i < n ; i++)
		cin >> b[i];
	for(int i = 0 ; i < n ; i++)
		cin >> c[i];
	for(int i = 0 ; i < n ; i++)
		cin >> d[i];
	cout << solve(a,b,c,d) << '\n';
	return 0;
}

