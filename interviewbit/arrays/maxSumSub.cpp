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
	int maxSum, sum, left, right, pre;
	left = right = pre = -1;
	maxSum = -1000000009;
	sum = 0;
	bool ok = false;
	for(auto i : a)
		maxSum = max(maxSum, i);
	if(maxSum < 0)
		return maxSum;
	for(int i = 0 ; i < n ; i++) {
		sum += a[i];
		if(sum > maxSum) {
			maxSum = sum;
			left = pre;
			right = i;
		}
		else if(sum < 0)
			pre = i, sum = 0;
	}
	if(maxSum < sum) {
		left = pre;
		right = n-1;
		maxSum = sum;
	}
//	for(int i = left+1 ; i <= right ; i++)
//		cout << a[i] << ' ';
//	cout << endl;
	return maxSum;
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

