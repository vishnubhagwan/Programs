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

#define vi vector<int>
#define pb push_back

ll MOD = ll(1e9+7);

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

int main() {
	vector<pair<string, string> > m;
	m.pb({"Name","Govind Shukla"});
	m.pb({"D.O.B.","17/05/1993"});
	m.pb({"T.O.B.","12:05 A.M."});
	m.pb({"P.O.B.","Bhopal"});
	m.pb({"Gotra","Sankrit"});
	m.pb({"Brahmin","Kanyakubj"});
	m.pb({"Education","IIT Qualified, BTech. Computer Science Engineering from IIIT Hyderabad"});
	m.pb({"Interests", "Music , Books , Travelling , Movies , Sports"});
	m.pb({"Height","5\' 10\""});
	m.pb({"Manglik","Anshik Mangali"});
	m.pb({"Complexion","Fair"});
	m.pb({"Job","Sr. Analyst, Full Stack Development, Bank of NewYork Mellon, Pune"});
	m.pb({"Annual Income", "25 LPA"});
	m.pb({"Native Place","Auraiya (U.P.)"});
	m.pb({"Preference","Engineering/Architecture , CA/CS/ICWA/CFA , Government Officer"});
	m.pb({"Father\'s Name","Dinesh Kumar Shukla"});
	m.pb({"Father\'s Occupation","Ex. Forest Officer"});
	m.pb({"Mother\'s Name","Uma Devi Shukla"});
	m.pb({"Mother\'s Occupation","House wife"});
	m.pb({"Details on Sisters","2 Sisters, Both Married. Older Sister completed MSc in Chemistry, B.Ed. Younger sister is Phd degree holder from UIT RGPV, currently working as Assistant Professor in UIT RGPV."});
	m.pb({"Details on Brothers", "1 Brother, IIT Qualified, Married. Working as Sr. Scientist in ISRO Satellite Centre Bangalore"});
	m.pb({"Mob. No.", "8989109541, 8319948032"});
	int t = 0;
	for(auto i : m) {
		t = max((int) i.f.size(), t);
	}
	t++;
	for(auto i : m) {
		string tmp = i.f;
		while(tmp.size() < t)
			tmp += " ";
		cout << tmp << " : " << i.s << '\n';
	}
	return 0;
}

