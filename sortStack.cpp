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

void insertAtBottom(stack<int>& st, int x) {
	if(st.empty() || st.top() <= x) {
		st.push(x);
		return;
	}
	int p = st.top();
	st.pop();
	insertAtBottom(st, x);
	st.push(p);
}

void reverse(stack<int>& st) {
	if(st.empty())
		return;
	int x = st.top();
	st.pop();
	reverse(st);
	insertAtBottom(st,x);
	return;
}

int main() {
	int n;
	cin >> n;
	stack<int> st;
	for(int i = 0 ; i < n ; i++) {
		int l;
		cin >> l;
		st.push(l);
	}
	reverse(st);
	while(!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}
	cout << '\n';
	return 0;
}
