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

using namespace std;
typedef long long int ll;

const int N = int(1e5+1);

#define vi vector<int>
#define pb push_back

ll MOD = ll(1e9+7);

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

int f(vi a) {
	int s = 0;
	int mxx = 0, mx = 0;
	int n = a.size();
	for(int i = 0 ; i <= mx && i < n-1 ; i++) {
		mxx = max(mxx, a[i] + i);
		if(i == mx)
			s++, mx = mxx;
	}
	return mx < n-1 ? -1 : s;
}

int main() {
	int n;
	cin >> n;
	vi a(n);
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	cout << f(a) << '\n';
	return 0;
}

