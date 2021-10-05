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

int f(int n) {
	if(n == 0)
		return 1;
	ll a[n], b[n];
	for(int i = 0 ; i < n ; i++)
		a[i] = b[i] = 0;
	a[0] = 1, a[1] = 0;
	b[0] = 0, b[1] = 1;
	// a[n] = a[n-2] + 2*b[n-1]
	// b[n] = a[n-1] + b[n-2];
	for(int i = 2 ; i <= n ; i++) {
		(a[i] = a[i-2] + 2*b[i-1])%=MOD;
		(b[i] = a[i-1] + b[i-2])%=MOD;
	}
	return a[n];
}

int main() {
	int n;
	cin >> n;
	cout << f(n) << '\n';
	return 0;
}

