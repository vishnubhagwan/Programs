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

int main() {
	int t;
	cin >> t;
	set<int> commonDiff;
	vector<int> input;
	while(t--) {
		int n,m,mx,mn,c;
		cin >> n;
		input.resize(n);
		for(int i = 0 ; i < n ; i++)
			cin >> input[i];
		for(int i = 1 ; i < n ; i++)
			commonDiff.insert(input[i]-input[i-1]);
		if(commonDiff.size() < 2) {
			cout << 0 << '\n';
			goto endStep;
		}
		else if(commonDiff.size() > 2) {
			cout << -1 << '\n';
			goto endStep;
		}
		mn = *commonDiff.begin();
		mx = *(--commonDiff.end());
		m = mx-mn;
		c = mn + m;
		if(input[0] > m) {
			cout << -1 << '\n';
			goto endStep;
		}
		for(int i = 1 ; i < n ; i++)
			if((input[i-1] + c) % m != input[i] || input[i] > m)
			{
				cout << -1 << '\n';
				goto endStep;
			}
		cout << m << ' ' << c << '\n';
endStep:
		input.clear();
		commonDiff.clear();
	}
	return 0;
}
