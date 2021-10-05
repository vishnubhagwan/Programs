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

ListNode* reverseBetween(ListNode* head, int a, int b) {
	ListNode* tmp1 = head, tmp2 = head;
	int cnt = b-a;
	while(tmp2 && cnt > 0) {
		tmp2 = tmp2->next;
		cnt--;
	}
	ListNode* pre = NULL;
	while(a-- && tmp2)
		pre = tmp1, tmp1 = tmp1->next, tmp2 = tmp2->next;
	ListNode *curr = tmp1, *next = NULL;
	while(tmp1->next) {
		next = tmp1->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return head;
}

int main() {
	int n, a, b;
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
	cin >> a >> b;
	head = reverseBetween(head);
	trace(head);
	return 0;
}

