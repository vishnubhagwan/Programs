// Sort a stack using recursion
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<list>
#include<set>
#include<stack>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<queue>
#include<pthread.h>
#define f first
#define s second
using namespace std;
typedef long long ll;

#define pb push_back
#define MAX ll(1e9+1)
#define N int(1e6+1)

vector<vector<int> > final_ans;

void trace(vector<int> a) {
	for(auto i : a)
		cout << i << ' ';
	cout << '\n';
}

void f(int x, vector<int> ans, vector<int> a, int n) {
	if(x == 0) {
		trace(ans);
//		final_ans.push_back(ans);
		return;
	}
	for(int i = 0 ; i < n ; i++) {
		ans.push_back(a[i]);
		if(x - a[i] >= 0 && (ans.size() > 0 ? a[i] >= ans[ans.size() - 1] : 1)) {
			cout << a[i] << ' ' << (ans.size() > 0 ? ans[ans.size() - 1] : ' ') << '\n';
			f(x-a[i], ans, a, n);
		}
		ans.pop_back();
	}
	return;
}

void combinationSum(vector<int>& a, int x) {
	vector<int> ans;
	int n = a.size();
	f(x, ans, a, n);
	return;
}

int main() {
	int n,x;
	cin >> n >> x;
	vector<int> a;
	a.resize(n);
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	combinationSum(a,x);
	for(auto i : final_ans) trace(i);
	return 0;
}
