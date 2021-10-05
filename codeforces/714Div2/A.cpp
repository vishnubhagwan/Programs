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
	int n,k,t;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		set<int> s;
		for(int i = 1;  i <= n ; i++)
			s.insert(i);
		int mx = n;
		vector<int> a;
		int tmp = k;
		for( ; k-- && s.size() > 0 && mx > *s.begin() ; ) {
			a.push_back(*s.begin());
			s.erase(s.begin());
			while(!s.count(mx)) mx--;
			a.push_back(mx);
			s.erase(mx);
			mx--;
		}
		while(!s.empty())
			a.push_back(*s.begin()), s.erase(s.begin());
		if(k > 0)
			cout << -1;
		else {
			int mx = 0;
			for(int i = 1 ; i < n-1 ; i++)
				if(a[i] > a[i-1] && a[i] > a[i+1])
					mx++;
			if(mx != tmp) {
				cout << -1; goto x;
			}
			
			for(int i : a) cout << i << ' ';
		}
x:	cout << '\n';
	}
	return 0;
}

