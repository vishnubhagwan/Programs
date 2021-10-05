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

vector<int> maxSet(vector<int> a) {
	reverse(a.begin(), a.end());
	int n = a.size();
	int carry = 1;
	for(int i = 0 ; i < n ; i++) {
		int sum = a[i] + carry;
		carry = sum/10;
		a[i] = sum%10;
	}
	if(carry)
		a.push_back(carry);
	reverse(a.begin(), a.end());
	int i = 0;
	while(i < a.size() && a[i] == 0) i++;
	vector<int> ans;
	while(i < a.size()) ans.push_back(a[i++]);
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	for(auto i : maxSet(a))
		cout << i;
	cout << endl;
	return 0;
}

