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

void trace(ListNode* a) {
	ListNode* tmp = a;
	while(tmp) {
		cout << tmp->val << ' ';
		tmp = tmp->next;
	}
	cout << '\n';
	return;
}

ListNode* findMid(ListNode* a) {
	if(!a || !a->next)
		return NULL;
	ListNode *p, *q;
	p = a;
	q = a->next;
	while(q && q->next)
		p = p->next, q = q->next->next;
	return p;
}

ListNode* reverse(ListNode* a) {
	if(!a->next)
		return a;
	ListNode* tmp = reverse(a->next);
	a->next->next = a;
	a->next = NULL;
	return tmp;
}

ListNode* reorderList(ListNode* a) {
	ListNode *mid, *b = NULL, *head = NULL;
	ListNode *p, *q, *pre=NULL;
	p = a;
	q = a;
	while(q && q->next) {
		pre = p, p = p->next, q = q->next->next;
	}
	if(pre)
		pre->next = NULL;
	b = p;
	b = reverse(b);
	head = a;
	while(a && b) {
		ListNode *next1, *next2;
		next1 = a->next;
		next2 = b->next;
		a->next = b, b->next = next1;
		pre = b;
		a = next1, b = next2;
	}
	if(b)
		pre->next = b;
	return head;
}

int main() {
	int n;
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
	head = reorderList(head);
	for(ListNode *i = head ; i != NULL ; i = i->next)
		cout << i->val << ' ';
	cout << '\n';
	return 0;
}

