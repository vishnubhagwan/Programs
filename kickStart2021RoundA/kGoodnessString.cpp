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

int testCase() {
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	int cnt = 0;
	for(int i = 0 ; i < n/2 ; i++) {
		if(s[i] != s[n-i-1])
			cnt++;
	}
	return abs(k-cnt);
}

int main() {
	int n;
	int t;
	cin >> t;
	for(int i = 1 ; i <= t ; i++) {
		int ans = testCase();
		cout << "Case #" << i << ": " << ans << endl;
	}
	return 0;
}

