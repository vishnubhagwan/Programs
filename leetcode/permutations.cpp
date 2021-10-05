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

void trace(vector<int> a) {
	for(auto i : a) cout << i << ' ';
	cout << '\n';
}

void solve(vector<int> nums) {
	int n = nums.size();
	sort(nums.begin(), nums.end());
	trace(nums);
	while(1) {
		bool ok = true;
		int idx = -1, mn = MOD;
		for(int i = n-2 ; i >= 0 ; i--) {
			if(nums[i] < nums[i+1]) {
				idx = i;
				break;
			}
		}
		int idxx = idx;
		if(idx != -1) {
			for(int j = idx+1 ; j < n ; j++) {
				if(nums[j] > nums[idxx] && nums[j] < mn)
					mn = nums[j], idx = j;
			}
			swap(nums[idxx], nums[idx]);
			reverse(nums.begin() + idxx + 1, nums.end());
		}
		else
			break;
		trace(nums);
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& i : a)
		cin >> i;
	solve(a);
	return 0;
}

