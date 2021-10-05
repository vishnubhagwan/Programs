#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <stack>
#include <assert.h>

#define pii pair<int, int>
#define f first
//#define s second
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
	int sum = 0;
	for(auto i : a)
		sum += i;
	if(sum % 3)
		return 0;
	unordered_map<int, int> s;
	int n = a.size();
	int first = 0, ans = 0;
	for(int i = 0 ; i < n ; i++) {
		first += a[i];
		if(first%2 == 0 &&  s.count(first/2) && sum - first == first/2 && i != n-1)
			ans += s[first/2];
		s[first]++;
	}
	return ans;
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

