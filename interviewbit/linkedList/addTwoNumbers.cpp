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

ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
	int carry = 0;
	ListNode *ans = NULL, *head = NULL;
	while(a != NULL && b != NULL) {
		a->val = a->val + b->val + carry;
		carry = a->val / 10;
		a->val %= 10;
		if(ans == NULL)
			head = ans = a;
		else
			ans->next = a, ans = ans->next;
		a = a->next;
		b = b->next;
	}
	while(a != NULL) {
		a->val = a->val + carry;
		carry = a->val / 10;
		a->val %= 10;
		if(ans == NULL)
			head = ans = a;
		else
			ans->next = a, ans = ans->next;
		a = a->next;
	}
	while(b != NULL) {
		b->val = b->val + carry;
		carry = b->val / 10;
		b->val %= 10;
		if(ans == NULL)
			head = ans = b;
		else
			ans->next = b, ans = ans->next;
		b = b->next;
	}
	if(carry != 0)
		ans->next = new ListNode(carry);
	return head;
}

int main() {
	int n,m;
	cin >> n >> m;
	ListNode *a,*b,*tmp;
	a = b = tmp = NULL;
	for(int i = 0 ; i < n ; i++) {
		int l;
		cin >> l;
		if(a == NULL) {
			a = new ListNode(l);
			tmp = a;
		}
		else {
			tmp->next = new ListNode(l);
			tmp = tmp->next;
		}
	}
	for(int i = 0 ; i < m ; i++) {
		int l;
		cin >> l;
		if(b == NULL) {
			b = new ListNode(l);
			tmp = b;
		}
		else {
			tmp->next = new ListNode(l);
			tmp = tmp->next;
		}
	}
	ListNode* head = addTwoNumbers(a,b);
	for(ListNode *i = head ; i != NULL ; i = i->next)
		cout << i->val << ' ';
	cout << '\n';
	return 0;
}

