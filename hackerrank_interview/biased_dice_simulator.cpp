// Compiled with: g++ -Wall -std=c++14 -pthread

#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define pii pair<int, int>
#define f first
#define s second
#define vipii vector<int, pair<int, int> >
#define ipii pair<int, pair<int, int> >
#define pb push_back

typedef long long int ll;
using ll = int64_t;
void chmax(ll& a, ll b){ if(a < b) a = b; }

int f(int n, vector<int> a) {
	int dp[n+1][6][51];
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < 6 ; j++)
			for(int k = 0 ; k < 51 ; k++)
				if(i == 0 && k == 0)
					dp[i][j][k] = 1;
				else
					dp[i][j][k] = 0;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 0 ; j < 6 ; j++)
			for(int k = 0 ; k < 51 ; k++)
				dp[]
}
 
int main(){
	int n;
	cin >> n;
	int t; cin >> t;
	vector<int> a(6);
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	f(n,a);
	return 0;
}
