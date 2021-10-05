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

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		int a,b;
		cin>>a>>b;
		cin>>s;
		int n = s.size();
		for(int i = 0 ; i < n/2 ; i++)
			if((s[i] == '0' && s[n-i-1] == '?') || (s[i] == '?' && s[n-i-1] == '0') || (s[i] == '0' && s[n-i-1] == '0')) {
				if(s[i] == '0' && s[n-i-1] == '0') {
					a-=2;
					continue;
				}
				s[i] = s[n-i-1] = '0';
				a-=2;
				continue;
			}
			else if((s[i] == '1' && s[n-i-1] == '?') || (s[i] == '?' && s[n-i-1] == '1') || (s[i] == '1' && s[n-i-1] == '1')) {
				if(s[i] == '1' && s[n-i-1] == '1') {
					b-=2;
					continue;
				}
				s[i] = s[n-i-1] = '1';
				b-=2;
				continue;
			}
		if(n%2 == 1) {
			if(s[n/2] != '?') {
				a -= s[n/2] == '0';
				b -= s[n/2] == '1';
				goto x;
			}
			if(a%2 == 1)
				s[n/2] = '0', a--;
			else
				s[n/2] = '1', b--;
		}
x:		for(int i = 0 ; i < n/2 ; i++) {
			if(a > 0 && ((s[i] == '0' && s[n-i-1] == '?') || (s[i] == '?' && s[n-i-1] == '0') || (s[i] == '?' && s[n-i-1] == '?')))
				s[i] = s[n-i-1] = '0', a-=2;
			else if(b > 0 && ((s[i] == '1' && s[n-i-1] == '?') || (s[i] == '?' && s[n-i-1] == '1') || (s[i] == '?' && s[n-i-1] == '?')))
				s[i] = s[n-i-1] = '1', b-=2;
		}
		if(a > 0 || b > 0)
			cout << -1;
		else cout << s;
		cout << '\n';
	}
	return 0;
}

