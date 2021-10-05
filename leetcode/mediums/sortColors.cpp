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

void solve(string& s) {
	int n = s.size();
	int r,g,b;
	r = 0, g = n-1, b = 0;
	for(int i = 0 ; i <= g ; )
		if(s[i] == 'R') {
			if(i == r) {
				i++;
				continue;
			}
			swap(s[r++], s[i]);
		}
		else if(s[i] == 'G')
			swap(s[g--], s[i]);
		else
			i++;
	return;
}

int main() {
	string s;
	cin >> s;
	solve(s);
	cout << s << endl;
	return 0;
}

