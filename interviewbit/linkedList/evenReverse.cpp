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

ListNode* reverse(ListNode* a) {
	if(!a || !a->next)
		return a;
	ListNode* tmp = reverse(a->next);
	a->next->next = a;
	a->next = NULL;
	return tmp;
}

ListNode* merge(ListNode* a, ListNode* b) {
	ListNode *head, *tmpHead, *preA, *preB;
	head = tmpHead = new ListNode(-1);
	preA = a;
	preB = b;
	a = a->next;
	b = b->next;
	int cnt = 1;
	while(a && b) {
		ListNode* next = NULL;
		if(cnt & 1) {
			next = a->next;
			preA->next = a->next;
			a->next = NULL;
			tmpHead->next = a;
			a = next;
		}
		else {
			next = b->next;
			preB->next = b->next;
			b->next = NULL;
			tmpHead->next = b;
			b = next;
		}
		tmpHead = tmpHead->next;
		cnt++;
	}
	if(b)
		tmpHead->next = b;
	if(a)
		tmpHead->next = a;
	return head->next;
}

ListNode* solve(ListNode* a) {
	ListNode *even, *odd, *evenHead, *oddHead;
	evenHead = even = new ListNode(-1);
	oddHead = odd = new ListNode(-1);
	ListNode* pre = new ListNode(-1);
	pre->next = a;
	int cnt = 1;
	while(a) {
		ListNode* next = NULL;
		if(cnt & 1) {
			next = a->next;
			pre->next = a->next;
			a->next = NULL;
			odd->next = a;
			a = next;
			odd = odd->next;
		}
		else {
			next = a->next;
			pre->next = a->next;
			a->next = NULL;
			even->next = a;
			a = next;
			even = even->next;
		}
		cnt++;
	}
	evenHead->next = reverse(evenHead->next);
	return merge(oddHead, evenHead);
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
	head = solve(head);
	for(ListNode *i = head ; i != NULL ; i = i->next)
		cout << i->val << ' ';
	cout << '\n';
	return 0;
}

