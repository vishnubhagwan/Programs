#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int segment(int k, vector<int> a) {
	int n = a.size();
	deque<int> q;
	for(int i = 0 ; i < k ; i++) {
		while(!q.empty() && a[q.back()] > a[i])
			q.pop_back();
		while(!q.empty() && i - q.front() + 1 > k)
			q.pop_front();
		q.push_back(i);
	}
	int ans = 0;
	ans = max(ans, a[q.front()]);
	for(int i = k ; i < n ; i++) {
		while(!q.empty() && a[q.back()] > a[i])
			q.pop_back();
		while(!q.empty() && i - q.front() + 1 > k)
			q.pop_front();
		q.push_back(i);
		ans = max(ans, a[q.front()]);
	}
	return ans;
}


int main()
{
	int n,k;
	cin >> k >> n;
	vector<int> a(n);
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	cout << segment(k,a) << '\n';
	return 0;
}

