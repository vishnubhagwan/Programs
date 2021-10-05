#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
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

ll inf = ll(1e9+7);

#define vi vector<int>
#define vii vector<vector<int> >
#define pb push_back

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

bool f(string s, int x, int y) {
	if(x+1 == y && s[x] == s[y])
		return true;
	if(s[x] == s[y] && f(s, x+1, y-1))
		return true;
	for(int i = x+1 ; i+1 < y ; i++)
		if(f(s, x, i) && f(s, i+1, y))
			return true;
	return false;
}

int main() {
	string s;
	cin >> s;
	int n = s.size();
	cout << f(s,0,n-1) << endl;
	return 0;
}
