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

ll MOD = ll(1e9+7);

#define vi vector<int>
#define vii vector<vector<int> >
#define pb push_back

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

vector<int> maxset(vector<int> a) {
	int n = a.size(), l, r;
	l = r = -1;
	int minRight, maxLeft;
	minRight = a[n-1];
	maxLeft = a[0];
	for(int i = n-2 ; i >= 0 ; i--) {
		minRight = min(minRight, a[i]);
		if(minRight < a[i])
			l = i;
	}
	for(int i = 1 ; i < n ; i++) {
		maxLeft = max(maxLeft, a[i]);
		if(maxLeft > a[i])
			r = i;
	}
	if(l == -1)
		return {-1};
	return {l,r};
}

void trace(vector<int> a) {
	for(auto i : a) cout << i << ' ';
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	trace(maxset(a));
	return 0;
}

