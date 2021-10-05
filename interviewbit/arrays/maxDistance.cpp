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
	int maxDist = 0;
//	for(int i = 0 ; i < n ; i++) {
//		for(int j = n-1 ; j >= i ; j--)
//			if(a[j] >= a[i]) {
//				maxDist = max(maxDist, j-i);
//				break;
//			}
//	}
	vector<int> maxArray(n);
	maxArray[n-1] = a[n-1];
	for(int i = n-2 ; i >= 0 ; i--)
		maxArray[i] = max(maxArray[i+1], a[i]);
	for(int i = 0 ; i < n ; i++) {
		int l = 0, r = n-1, k = a[i];
		while(l < r) {
			int mid = (l+r)/2;
			if(maxArray[mid] >= k)
				l = mid+1;
			else
				r = mid;
		}
		if(a[l] < k)
			l--;
		maxDist = max(maxDist, l-i);
	}
	return maxDist;
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

