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
#define vipii vector<int, pair<int, int> >
#define ipii pair<int, pair<int, int> >

using namespace std;
typedef long long int ll;

const int N = int(1e5+1);

ll MOD = ll(1e9+7);

#define vi vector<int>
#define vii vector<vi >
#define pb push_back

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

void f(string s) {
	int n = s.size();
	stack<string> t;
	for(int i = 0 ; i < n ; i++) {
		string cal = "";
		if(s[i] >= 'a' && s[i] <= 'z' ||
				(s[i] >= 'A' && s[i] <= 'Z')) {
			cal += s[i];
			t.push(cal);
		}
		else {
			string p,q;
			if(!t.empty()) {
				p = t.top();
				t.pop();
			}
			else {
				cout << "Invalid Expression\n";
				return;
			}
			if(!t.empty()) {
				q = t.top();
				t.pop();
			}
			else {
				cout << "Invalid Expression\n";
				return;
			}
			cal += "(";
			cal += q;
			cal += s[i];
			cal += p;
			cal += ")";
			t.push(cal);
		}
	}
	string ans = t.top();
	t.pop();
	if(!t.empty())
		cout << "Invalid Expression\n";
	else cout << ans << '\n';
}

int main() {
	string s;
	cin >> s;
	f(s);
	return 0;
}

