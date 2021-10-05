#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <stack>
#include <assert.h>

#define pii pair<int, int>
#define f first
//#define s second
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

int maxset(vector<int> a) {
	int n = a.size(), xorSum = 0;
	for(int i = 0 ; i < n ; i++)
		xorSum ^= a[i];
	int rightMostBit = xorSum & -xorSum;
	int x, y;
	x = y = 0;
	for(int i = 0 ; i < n ; i++) {
		if(i & rightMostBit)
			x ^= i;
		else
			y ^= i;
		if(a[i] & rightMostBit)
			x ^= a[i];
		else
			y ^= a[i];
	}
	return x;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	cout << maxset(a) << endl;
	return 0;
}

