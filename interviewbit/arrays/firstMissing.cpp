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

int maxset(vector<int> a) {
	int n = a.size();
	for(int i = 0 ; i < n ; i++)
		if(a[i] > 0 && a[i] <= n && a[i] != a[a[i]-1])
			swap(a[i], a[a[i]-1]), i--;
	for(int i = 0 ; i < n ; i++)
		if(a[i] != i+1) return i+1;
	return n+1;
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

