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

ListNode* detectCycle(ListNode* a) {
	ListNode *p1 = a, *p2 = a;
	p2 = p2->next;
	while(p1 != p2 && p1 && p2 && p2->next)
		p1 = p1->next, p2 = p2->next->next;
	if(p1 == NULL || p2 == NULL || p2->next == NULL)
		return NULL;
	int l = 1;
	p1 = p1->next;
	while(p1 != p2 && p1) l++, p1 = p1->next;
	p1 = p2 = a;
	while(p2 != NULL && l--) p2 = p2->next;
	while(p1 != p2 && p1)
		p1 = p1->next, p2 = p2->next;
	return p1;
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
	head = detectCycle(head);
	for(ListNode *i = head ; i != NULL ; i = i->next)
		cout << i->val << ' ';
	cout << '\n';
	return 0;
}

