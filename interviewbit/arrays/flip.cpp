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

vector<int> maxSet(string a) {
	int start, end, maxNum, num, pre;
	start = end = pre = -1;
	maxNum = -1;
	num = 0;
	int n = a.size();
	for(int i = 0 ; i < n ; i++) {
		if(a[i] == '0')
			num++;
		else
			num--;
		if(num < 0)
			pre = i, num = 0;
		if(num > maxNum) {
			maxNum = num;
			start = pre;
			end = i;
		}
	}
	vector<int> ans;
	if(start+1 <= end)
		ans = {start+2, end+1};
	return ans;
}

int main() {
	string a;
	cin >> a;
	for(auto i : maxSet(a))
		cout << i << ' ';
	cout << endl;
	return 0;
}

