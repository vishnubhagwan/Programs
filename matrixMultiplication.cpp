// Printing brackets in Matrix Chain Multiplication Problem
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
#define s second
using namespace std;
typedef long long ll;

#define pb push_back
#define MAX ll(1e9+1)
#define N int(1e3+1)

int n;
int dp[N][N];

int find_ans(vector<int> a, int i = 1, int j = n-1) {
	int& ret = dp[i][j];
	if(ret != -1) return ret;
	if(i == j)
		return ret = 0;
	int ans = MAX;
	for(int k = i ; k < j ; k++)
		ans = min(ans, find_ans(a, i, k) + find_ans(a, k+1, j) + a[i-1] * a[k] * a[j]);
	return ret = ans;
}

void print_matrix(vector<int> a, int i = 1, int j = n-1) {
	static char name = 'A';
	if(i == j) {
		cout << name;
		name++;
		return;
	}
	cout << '(';
	for(int k = i ; k < j ; k++)
		if(dp[i][k] + dp[k+1][j] + a[i-1] * a[k] * a[j] == dp[i][j]) {
			print_matrix(a, i, k);
			print_matrix(a, k+1, j);
		}
	cout << ')';
}

int main() {
	vector<int> a = {40, 20, 30, 10, 30};
	n = a.size();
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			dp[i][j] = -1;
	find_ans(a);
	print_matrix(a);
	cout << '\n';
    return 0;
}
