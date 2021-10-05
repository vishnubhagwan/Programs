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

vector<int> sum(vector<int> a, vector<int> b) {
	int carry = 0;
	int n = min(a.size(), b.size());
	int i = 0;
	vector<int> ans;
	for(i = 0 ; i < n ; i++) {
		int sum = a[i] + b[i] + carry;
		carry = sum / 10;
		ans.push_back(sum%10);
	}
	while(i < a.size()) {
		int sum = a[i] + carry;
		carry = sum / 10;
		ans.push_back(sum%10);
		i++;
	}
	while(i < b.size()) {
		int sum = b[i] + carry;
		carry = sum / 10;
		ans.push_back(sum%10);
		i++;
	}
	if(carry != 0)
		ans.push_back(carry);
	return ans;
}

vector<int> mul(vector<int> a, int n, int zeros) {
	int m = n;
	if(n/10 == 0) {
		int m = a.size();
		int c = 0;
		vector<int> ans;
		while(zeros--) ans.push_back(0);
		for(int i = 0 ; i < m ; i++) {
			int num = n * a[i] + c;
			ans.push_back(num % 10);
			c = num / 10;
		}
		if(c)
			ans.push_back(c);
		return ans;
	}
	vector<int> b;
	while(n > 0) {
		b.push_back(n%10);
		n /= 10;
	}
	n = b.size();
	vector<int> carry;
	for(int i = 0 ; i < n ; i++)
		carry = sum(mul(a, b[i], i), carry);
	return carry;
}

string fact(int n) {
	vector<int> ans = {1};
	for(int i = 2 ; i <= n ; i++) {
		ans = mul(ans, i, 0);
	}
	string ret = "";
	for(auto i : ans)
		ret = to_string(i) + ret;
	cout << ret.size() << endl;
	return ret;
}

int main() {
	int n;
	cin >> n;
	cout << fact(n) << endl;
	return 0;
}

