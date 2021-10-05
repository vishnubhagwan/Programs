#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <assert.h>

#define pii pair<int, int>
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

bool alpha(char c) {
	return (c >= 'A' && c <= 'Z') ||
		(c >= 'a' && c <= 'z');
}

int prec(char c) {
	if(c == '^')
		return 3;
	if(c == '/' || c == '*')
		return 2;
	if(c == '+' || c == '-')
		return 1;
	return -1;
}

string f(string s) {
	int n = s.size();
	stack<char> t;
	bool found = false;
	string ans;
	for(int i = 0; i < n ; i++) {
		if(alpha(s[i]))
			 ans += s[i];
		else if(s[i] == '(')
			t.push(s[i]);
		else if(s[i] == ')') {
			while(!t.empty() && t.top() != '(') {
				ans += t.top();
				t.pop();
			}
			t.pop();
		}
		else {
			while(!t.empty() && prec(s[i]) <= prec(t.top())) {
				ans += t.top();
				t.pop();
			}
			t.push(s[i]);
		}
	}
	while(!t.empty()) {
		ans += t.top();
		t.pop();
	}
	return ans;
}

int main() {
	string s;
	cin >> s;
	cout << f(s) << '\n';
	return 0;
}

