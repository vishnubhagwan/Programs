#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
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

int x[] = {0,1,0,-1,1,1,-1,-1};
int y[] = {1,0,-1,0,1,-1,1,-1};

int solve(vector<int>& height) {
	int n = height.size();
	int ans = 0;
//	for(int i = 0 ; i < n ; i++)
//		for(int j = i+1 ; j < n ; j++)
//			ans = max(ans, min(height[j],height[i]) * (j-i));
	for(int i = 0, j = n-1 ; i < j ; ) {
		ans = max((j-i) * min(height[i], height[j]), ans);
		if(height[i] < height[j])
			i++;
		else
			j--;
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> height(n);
	for(int i = 0 ; i < n ; i++) cin >> height[i];
	cout << solve(height) << endl;
	return 0;
}

