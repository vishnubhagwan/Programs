// Compiled with: g++ -Wall -std=c++14 -pthread

#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define pii pair<int, int>
#define f first
#define s second
#define vipii vector<int, pair<int, int> >
#define ipii pair<int, pair<int, int> >
#define pb push_back

typedef long long int ll;
using ll = int64_t;
void chmax(ll& a, ll b){ if(a < b) a = b; }
 
int main(){
    ll N, T;
    cin >> N >> T;
    vector<ll> A(N);
    for(ll& a : A) cin >> a;
    vector<ll> B{0}, C{0};
    for(ll a : A){
        for(ll i = B.size(); i--; ) B.push_back(B[i] + a);
        swap(B, C);
    }
    for(auto i : C) cout << i << ' '; cout << '\n';
    sort(B.begin(), B.end(), greater<ll>());
    
    ll ans = 0;
    for(ll x : C){
        if(x > T) continue;
        x += *lower_bound(B.begin(), B.end(), T - x, greater<ll>());
        chmax(ans, x);
    }
    cout << ans << endl;
}
