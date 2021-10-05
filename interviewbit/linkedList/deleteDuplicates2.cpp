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

ListNode* deleteDuplicates(ListNode* l) {
    ListNode *a = l, *pre = NULL;
    bool dup = false;
    while(a && a->next) {
        if(a->val == a->next->val)
            dup = true;
        int t = a->val;
        while(dup && a != NULL && a->val == t)
            a = a->next;
        if(dup) {
            dup = false;
        }
        else {
            if(pre == NULL)
                l = pre = a;
	    else {
		    pre->next = a;
		    pre = pre->next;
	    }
            a = a->next;
        }
    }
    pre->next = NULL;
    return l;
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
	head = deleteDuplicates(head);
	for(ListNode *i = head ; i != NULL ; i = i->next)
		cout << i->val << ' ';
	cout << '\n';
	return 0;
}

