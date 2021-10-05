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

int maxset(vector<vector<int>> a, int b) {
	int n = a.size();
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			if(j > 0)
				a[i][j] += a[i][j-1];
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			if(i > 0)
				a[i][j] += a[i-1][j];
	int ans = -100006;
	for(int i = b-1 ; i < n ; i++)
		for(int j = b-1 ; j < n ; j++)
			ans = max(ans, a[i][j] + (i-b < 0 || j-b < 0 ? 0 : a[i-b][j-b]) - (i-b < 0 ? 0 : a[i-b][j]) - (j-b < 0 ? 0 : a[i][j-b]));
	return ans;
}

int main() {
	int n;
	cin >> n >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			cin >> a[i][j];
	int b;
	cin >> b;
	cout << maxset(a,b) << endl;
	return 0;
}

