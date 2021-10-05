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
	int n = a.size();
	ll sum, maxSum, left, start, end;
	sum = maxSum = 0;
	start = 0, left = -1;
	end = -1;
	for(int i = 0 ; i < n ; i++) {
		if(a[i] < 0) {
			if(maxSum < sum) {
				maxSum = sum;
				start = left + 1;
				end = i-1;
			}
			left = i;
			sum = 0;
		}
		else {
			sum += a[i];
		}
	}
	if(maxSum < sum) {
		start = left + 1;
		end = n-1;
	}
	vector<int> ans;
	for(int i = start ; i <= end ; i++)
		ans.push_back(a[i]);
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	a = maxset(a);
	for(auto i:a)
		cout << i << ' ';
	cout << endl;
	return 0;
}

