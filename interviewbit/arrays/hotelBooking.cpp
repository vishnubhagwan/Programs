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

int checkBookings(vector<pii> a, int c) {
	int n = a.size();
	if(n == 1 && c > 0)
		return 1;
	sort(a.begin(), a.end());
	int roomsBooked = 0;
	for(auto i : a) {
		if(i.s)
			roomsBooked++;
		else
			roomsBooked--;
		if(roomsBooked > c)
			return 0;
	}
	return 1;
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, int> > a(n);
	for(int i = 0 ; i < n ; i++) {
		int l,r;
		cin >> l >> r;
		a.pb({l,1});
		a.pb({r,0});
	}
	int c;
	cin >> c;
	cout << checkBookings(a,c) << '\n';
	return 0;
}

