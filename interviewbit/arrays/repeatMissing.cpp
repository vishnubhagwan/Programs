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
	int p,q,combined;
	int n = a.size();
	p = q = combined = 0;
	for(int i = 0 ; i < n ; i++)
		combined ^= a[i];
	for(int i = 1 ; i <= n ; i++)
		combined ^= i;
	int lastSetBit = combined & -combined;
	for(int i = 0 ; i < n ; i++)
		if(a[i] & lastSetBit)
			p ^= a[i];
		else
			q ^= a[i];
	for(int i = 1 ; i <= n ; i++)
		if(i & lastSetBit)
			p ^= i;
		else
			q ^= i;
	bool ok = false;
	for(int i = 0 ; i < n ; i++)
		if(a[i] == p)
			ok = true;
	if(!ok)
		swap(p,q);
	vector<int> ans;
	ans.pb(p);
	ans.pb(q);
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	for(auto i : maxset(a))
		cout << i << ' ';
	cout << endl;
	return 0;
}

