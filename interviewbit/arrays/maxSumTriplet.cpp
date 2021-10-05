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

int maxset(vector<int> a) {
	int n = a.size();
	vector<int> maxSufix(n);
	for(int i = n-1 ; i >= 0 ; i--)
		if(i == n-1)
			maxSufix[i] = a[i];
		else
			maxSufix[i] = max(maxSufix[i+1], a[i]);
	int maxSum = 0, maxElementLeft = 0;
	set<int> S;
	S.insert(a[0]);
	for(int i = 1 ; i < n-1 ; i++) {
		if(a[i] > maxSufix[i+1] || S.lower_bound(a[i]) == S.begin()) {
			S.insert(a[i]);
			continue;
		}
		if(!S.empty())
			maxElementLeft = *(--S.lower_bound(a[i]));
		int sum = maxElementLeft + a[i] + maxSufix[i+1];
		maxSum = max(sum, maxSum);
		S.insert(a[i]);
	}
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

