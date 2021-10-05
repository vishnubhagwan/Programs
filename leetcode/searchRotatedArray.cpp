#include <iostream>
#include <algorithm>
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

int bsearch(vector<int> nums, int lo, int hi, int target) {
	if(lo > hi)
		return -1;
	if(lo == hi)
		return nums[lo] == target ? lo : -1;
	int mid = (lo + hi) / 2;
	if(nums[mid] == target)
		return mid;
	else if(nums[mid] < target)
		return bsearch(nums, mid + 1, hi, target);
	else
		return bsearch(nums, lo, mid, target);
}

int search(vector<int> nums, int target) {
	int n = nums.size();
	int lo,hi;
	lo = 0, hi = n-1;
	while(lo < hi) {
		int mid = (lo + hi) / 2;
		if(nums[mid] < nums[0])
			hi = mid;
		else
			lo = mid + 1;
	}
	int ans = bsearch(nums, 0, lo-1, target);
	if(ans != -1)
		return ans;
	else
		return bsearch(nums, lo, n-1, target);
}

void solve() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0 ; i < n ; i++)
		cin >> nums[i];
	int target;
	cin >> target;
	cout << search(nums, target) << '\n';
	return;
}

int main() {
	solve();
	return 0;
}

