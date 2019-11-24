// Valid numbers - Google interview questions
#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<queue>
#define f first
// #define s second
using namespace std;
typedef long long ll;

#define pb push_back
#define MAX ll(1e18+1)
#define N int(1e6+1)

map<char, char> m;
int n;

bool isValid(string s) {
	n = s.size();
	if(s[n-1] == '0')
		return false;
	for(int i = n-1 ; i >= n/2 ; i--)
		if(m.count(s[i]) && s[n-i-1] != m[s[i]])
			return true;
	return false;
}

void findValidity(string s) {
	cout << s << ' ';
	if(isValid(s)) {
		string t = "";
		for(int i = n-1 ; i >= 0 ;i--)
			t += m[s[i]];
		if(stoi(t) >= 1 && stoi(t) <= stoi(s))
			cout << "YES\n";
		else
			cout << "NO\n";
		return;
	}
	cout << "NO\n";
	return;
}

int main() {
	m['0'] = '0', m['1'] = '1', m['6'] = '9', m['8'] = '8', m['9'] = '6';
	for(char i = '1' ; i <= '9' ; i++) {
		string s = ""; s += char(i);
		findValidity(s);
	}
 	return 0;
}
