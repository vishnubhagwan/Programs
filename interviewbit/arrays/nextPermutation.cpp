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
	int i;
	for(i = n-2 ; i >= 0 && a[i] > a[i+1] ; i--);
	if(i == -1) {
		reverse(a.begin(), a.end());
		return a;
	}
	int num = a[i];
	int nextMin = 1000000009, minIndex, maxIndex;
	minIndex = i+1, maxIndex = n-1;
	while(minIndex < maxIndex) {
		int mid = (minIndex + maxIndex)/2;
		if(a[mid] <= a[i])
			maxIndex = mid;
		else
			minIndex = mid + 1;
	}
	if(a[minIndex] < a[i])
		minIndex--;
	swap(a[i], a[minIndex]);
	reverse(a.begin() + i + 1, a.end());
	return a;
}

void trace(vector<int> a) {
	for(auto i : a) cout << i << ' ';
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	trace(maxset(a));
	return 0;
}

