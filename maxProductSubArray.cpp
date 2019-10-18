// Maximum product subarray
#include<iostream>
#include<vector>
#include<set>
#include<list>
#include<unordered_set>
#include<algorithm>
#include<queue>
#define f first
#define s second
using namespace std;
typedef long long ll;

#define pb push_back
#define MAX ll(1e18+1)
#define N int(1e6+1)

int maxSubArrayProduct(vector<int> a) {
	int n = a.size();
	int mn, mx, p, ans = 0;
	mn = mx = p = 1;
	if(n > 0)
		ans = a[0];
	else ans = 0;
	for(int i = 0 ; i < n ; i++) {
		p *= a[i];
		if(p < 0) {
			mx = 1;
		}
		else if(p == 0) {
			mx = p = 1;
		}
		else
			mx = p;
		ans = max(ans, mx);
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	cout << maxSubArrayProduct(a) << '\n';
 	return 0;
}
