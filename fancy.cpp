// Check if a given number is Fancy
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

bool checkFancy(string s) {
	map<char, char> m;
	m['0'] = '0', m['1'] = '1', m['6'] = '9', m['8'] = '8', m['9'] = '6';
	int n = s.size();
	for(int i = n-1 ; i >= n/2 ; i--)
		if(s[n-i-1] != m[s[i]])
			return false;
	return true;
}

int main() {
	string s = "9088806";
	cout << (checkFancy(s) ? "YES\n" : "NO\n");
 	return 0;
}
