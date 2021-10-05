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

ListNode* remove(ListNode* node) {
	ListNode* tmp = node->next;
	ListNode* t = node;
	while(t != NULL)
		cout << t->val << ' ', t = t->next;
	cout << '\n';
	node->next = node->next->next;
	cout << tmp->val << " del\n";
	tmp->next = NULL;
	return node->next;
}

void insert(ListNode** p, ListNode* tail) {
	if(*p == NULL)
		*p = tail->next;
	else {
		(*p)->next = remove(tail);
		*p = (*p)->next;
	}
	return;
}

ListNode* partition(ListNode* a, int b) {
	ListNode *p1, *p2, *head1, *head2;
	head1 = p1 = new ListNode(-1);
	head2 = p2 = new ListNode(-1);
	while(a) {
		if(a->val < b) {
			p1->next = a;
			p1 = p1->next;
			a = a->next;
		}
		else {
			p2->next = a;
			p2 = p2->next;
			a = a->next;
		}
	}
	p1->next = head2->next;
	p2->next = NULL;
	return head1->next;
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
	head = partition(head, m);
	for(ListNode *i = head ; i != NULL ; i = i->next)
		cout << i->val << ' ';
	cout << '\n';
	return 0;
}

