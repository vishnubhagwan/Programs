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

int ord(char c) {
	return c-'a';
}

char chr(int c) {
	return char(c+'a');
}

int n,k;
string s;

int solve() {
	int ans = 0;
	for(int i = 1 ; i <= 26 ; i++) {
		unordered_map<char, int> m;
		int countAtleastK = 0;
		for(int l = 0, r = 0 ; r < n ; ) {
			if(m.size() <= i) {
				m[s[r]]++;
				if(m[s[r]] == k)
					countAtleastK++;
				r++;
			}
			else {
				if(m.count(s[l]) && m[s[l]] == k)
					countAtleastK--;
				m[s[l]]--;
				if(m[s[l]] == 0)
					m.erase(s[l]);
				l++;
			}
			if(countAtleastK == m.size() && i == m.size())
				ans = max(ans, r-l);
		}
	}
	return ans;
}

int main() {
	cin >> s;
	n = s.size();
	cin >> k;
	cout << solve() << '\n';
	return 0;
}

