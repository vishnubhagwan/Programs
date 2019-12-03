// Find a triplet that sum to a given value
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

bool twoSum(vector<int> a, int l, int sum) {
	int n = a.size();
	int r = n-1;
	while(l < r)
		if(a[l] + a[r] > sum)
			r--;
		else if(a[l] + a[r] == sum) {
			cout << a[l] << ' ' << a[r] << ' ';
			return true;
		}
		else
			l++;
	return false;
}

void find_ans(vector<int> a, int sum) {
	int n = a.size();
	for(int i = 0 ; i < n ; i++)
		if(twoSum(a, i+1, sum-a[i])) {
			cout << a[i] << '\n';
			return;
		}
	return;
}

int main() {
	vector<int> a = { 1, 4, 45, 6, 10, 8 };
	int sum = 22;
	sort(a.begin(), a.end());
	find_ans(a,sum);
    return 0;
}
