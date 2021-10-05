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

void solve(vector<vector<int>> a)  {
	int n = a.size();
	for(int i = 0 ; i < n/2 + (n%2) ; i++)
		for(int j = 0 ; j < n/2 ; j++) {
			int tmp = a[n-j-1][i];
			a[n-j-1][i] = a[n-i-1][n-j-1];
			a[n-i-1][n-j-1] = a[j][n-i-1];
			a[j][n-i-1] = a[i][j];
			a[i][j] = tmp;
		}
	for(int i= 0 ; i < n ; i++) {
		for(int j = 0 ; j < n ; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
	return;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int> > a(n, vector<int>(n));
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			cin >> a[i][j];
	solve(a);
	return 0;
}

