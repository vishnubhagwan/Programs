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

typedef struct Interval {
	int start;
	int end;
	Interval() {
		start = end = 0;
	}
	Interval(int s, int e) {
		start = s;
		end = e;
	}
} Interval;


bool operator<(const Interval& a, const Interval& b) {
	if(a.start == b.start)
		return a.end < b.end;
	return a.start < b.start;
}

vector<Interval> maxset(vector<Interval> a) {
	int n = a.size();
	sort(a.begin(), a.end());
	vector<Interval> ans;
	for(int i = 0 ; i < n ; i++) {
		Interval interval = a[i];
		if(ans.size() == 0)
			ans.pb(interval);
		else {
			Interval& pre = ans[ans.size()-1];
			if(pre.end >= interval.start)
				pre.end = max(interval.end, pre.end);
			else
				ans.pb(interval);
		}
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<Interval> intervals;
	for(int i = 0 ; i < n ; i++) {
		int s,e;
		cin >> s >> e;
		intervals.pb(Interval(s,e));
	}
	intervals = maxset(intervals);
	for(auto interval : intervals)
		cout << interval.start << ' ' << interval.end << endl;
	return 0;
}

