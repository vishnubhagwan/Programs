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
#define vii vector<vi >
#define pb push_back

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

typedef struct ListNode {
	int val;
	ListNode *next;
	ListNode(int val) {
		this->val = val;
		next = NULL;
	}
} ListNode;

ListNode* solve(ListNode* a, int k, int rev = 1) {
	if(!a || !a->next)
		return a;
	ListNode *next, *pre, *curr;
	curr = a;
	next = pre = NULL;
	int i = 0;
	if(rev) {
		while(curr && i < k) {
			next = curr->next;
			curr->next = pre;
			pre = curr;
			curr = next;
			i++;
		}
		a->next = solve(next, k, rev ^ 1);
	}
	else {
		next = curr;
		while(next && i < k)
			curr = next, next = next->next, i++;
		curr->next = solve(next, k, rev ^ 1);
	}
	return rev ? pre : a;
}

int main() {
	int n, m;
	cin >> n;
	ListNode *head, *tmp;
	head = tmp = NULL;
	for(int i = 0 ; i < n ; i++) {
		int l;
		cin >> l;
		if(head == NULL)
			head = new ListNode(l), tmp = head;
		else {
			tmp->next = new ListNode(l);
			tmp = tmp->next;
		}
	}
	cin >> m;
	head = solve(head, m);
	for(ListNode *i = head ; i != NULL ; i = i->next)
		cout << i->val << ' ';
	cout << '\n';
	return 0;
}

