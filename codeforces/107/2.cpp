#include <iostream>
 
#define fo(i, n) for (int i = 0; i < int(n); i++)
#define of(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define Fo(i, l, r) for (int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define x first
#define y second
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
 
const int N = 10;
pair<ll, ll> precomp[10][10][10];
void solve() {
    int a, b, c; cin >> a >> b >> c;
    auto res = precomp[a][b][c];
    cout << res.x << " " << res.y << '\n';
    // Fo(a, 1, 10) {
    //     Fo(b, 1, 10) {
    //         Fo(c, 1, 10) {
    //             if(c > a or c > b) continue;
    //             int least_A = pow(10, a - 1);
    //             int max_A = pow(10, a) - 1;
    //             int least_B = pow(10, b - 1);
    //             int max_B = pow(10, b) - 1;
    //             bool f = 0;
    //             Fo(A, least_A, max_A + 1) {
    //                 if(f) break;
    //                 Fo(B, least_B, max_B + 1) {
    //                     if(sz(to_string(__gcd(A, B))) == c) {
    //                         cout << "precomp[" << a << "]["<< b << "][" << c << "] = " << "make_pair(" << A << "," << B << ");" << endl;
    //                         f = 1;
    //                         break;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }
}
 
 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
precomp[1][1][1] = make_pair(1,1);
precomp[1][2][1] = make_pair(1,10);
precomp[1][3][1] = make_pair(1,100);
precomp[1][4][1] = make_pair(1,1000);
precomp[1][5][1] = make_pair(1,10000);
precomp[1][6][1] = make_pair(1,100000);
precomp[1][7][1] = make_pair(1,1000000);
precomp[1][8][1] = make_pair(1,10000000);
precomp[1][9][1] = make_pair(1,100000000);
precomp[2][1][1] = make_pair(10,1);
precomp[2][2][1] = make_pair(10,11);
precomp[2][2][2] = make_pair(10,10);
precomp[2][3][1] = make_pair(10,101);
precomp[2][3][2] = make_pair(10,100);
precomp[2][4][1] = make_pair(10,1001);
precomp[2][4][2] = make_pair(10,1000);
precomp[2][5][1] = make_pair(10,10001);
precomp[2][5][2] = make_pair(10,10000);
precomp[2][6][1] = make_pair(10,100001);
precomp[2][6][2] = make_pair(10,100000);
precomp[2][7][1] = make_pair(10,1000001);
precomp[2][7][2] = make_pair(10,1000000);
precomp[2][8][1] = make_pair(10,10000001);
precomp[2][8][2] = make_pair(10,10000000);
precomp[2][9][1] = make_pair(10,100000001);
precomp[2][9][2] = make_pair(10,100000000);
precomp[3][1][1] = make_pair(100,1);
precomp[3][2][1] = make_pair(100,11);
precomp[3][2][2] = make_pair(100,10);
precomp[3][3][1] = make_pair(100,101);
precomp[3][3][2] = make_pair(100,110);
precomp[3][3][3] = make_pair(100,100);
precomp[3][4][1] = make_pair(100,1001);
precomp[3][4][2] = make_pair(100,1010);
precomp[3][4][3] = make_pair(100,1000);
precomp[3][5][1] = make_pair(100,10001);
precomp[3][5][2] = make_pair(100,10010);
precomp[3][5][3] = make_pair(100,10000);
precomp[3][6][1] = make_pair(100,100001);
precomp[3][6][2] = make_pair(100,100010);
precomp[3][6][3] = make_pair(100,100000);
precomp[3][7][1] = make_pair(100,1000001);
precomp[3][7][2] = make_pair(100,1000010);
precomp[3][7][3] = make_pair(100,1000000);
precomp[3][8][1] = make_pair(100,10000001);
precomp[3][8][2] = make_pair(100,10000010);
precomp[3][8][3] = make_pair(100,10000000);
precomp[3][9][1] = make_pair(100,100000001);
precomp[3][9][2] = make_pair(100,100000010);
precomp[3][9][3] = make_pair(100,100000000);
precomp[4][1][1] = make_pair(1000,1);
precomp[4][2][1] = make_pair(1000,11);
precomp[4][2][2] = make_pair(1000,10);
precomp[4][3][1] = make_pair(1000,101);
precomp[4][3][2] = make_pair(1000,110);
precomp[4][3][3] = make_pair(1000,100);
precomp[4][4][1] = make_pair(1000,1001);
precomp[4][4][2] = make_pair(1000,1010);
precomp[4][4][3] = make_pair(1000,1100);
precomp[4][4][4] = make_pair(1000,1000);
precomp[4][5][1] = make_pair(1000,10001);
precomp[4][5][2] = make_pair(1000,10010);
precomp[4][5][3] = make_pair(1000,10100);
precomp[4][5][4] = make_pair(1000,10000);
precomp[4][6][1] = make_pair(1000,100001);
precomp[4][6][2] = make_pair(1000,100010);
precomp[4][6][3] = make_pair(1000,100100);
precomp[4][6][4] = make_pair(1000,100000);
precomp[4][7][1] = make_pair(1000,1000001);
precomp[4][7][2] = make_pair(1000,1000010);
precomp[4][7][3] = make_pair(1000,1000100);
precomp[4][7][4] = make_pair(1000,1000000);
precomp[4][8][1] = make_pair(1000,10000001);
precomp[4][8][2] = make_pair(1000,10000010);
precomp[4][8][3] = make_pair(1000,10000100);
precomp[4][8][4] = make_pair(1000,10000000);
precomp[4][9][1] = make_pair(1000,100000001);
precomp[4][9][2] = make_pair(1000,100000010);
precomp[4][9][3] = make_pair(1000,100000100);
precomp[4][9][4] = make_pair(1000,100000000);
precomp[5][1][1] = make_pair(10000,1);
precomp[5][2][1] = make_pair(10000,11);
precomp[5][2][2] = make_pair(10000,10);
precomp[5][3][1] = make_pair(10000,101);
precomp[5][3][2] = make_pair(10000,110);
precomp[5][3][3] = make_pair(10000,100);
precomp[5][4][1] = make_pair(10000,1001);
precomp[5][4][2] = make_pair(10000,1008);
precomp[5][4][3] = make_pair(10000,1100);
precomp[5][4][4] = make_pair(10000,1000);
precomp[5][5][1] = make_pair(10000,10001);
precomp[5][5][2] = make_pair(10000,10010);
precomp[5][5][3] = make_pair(10000,10100);
precomp[5][5][4] = make_pair(10000,11000);
precomp[5][5][5] = make_pair(10000,10000);
precomp[5][6][1] = make_pair(10000,100001);
precomp[5][6][2] = make_pair(10000,100010);
precomp[5][6][3] = make_pair(10000,100100);
precomp[5][6][4] = make_pair(10000,101000);
precomp[5][6][5] = make_pair(10000,100000);
precomp[5][7][1] = make_pair(10000,1000001);
precomp[5][7][2] = make_pair(10000,1000010);
precomp[5][7][3] = make_pair(10000,1000100);
precomp[5][7][4] = make_pair(10000,1001000);
precomp[5][7][5] = make_pair(10000,1000000);
precomp[5][8][1] = make_pair(10000,10000001);
precomp[5][8][2] = make_pair(10000,10000010);
precomp[5][8][3] = make_pair(10000,10000100);
precomp[5][8][4] = make_pair(10000,10001000);
precomp[5][8][5] = make_pair(10000,10000000);
precomp[5][9][1] = make_pair(10000,100000001);
precomp[5][9][2] = make_pair(10000,100000010);
precomp[5][9][3] = make_pair(10000,100000100);
precomp[5][9][4] = make_pair(10000,100001000);
precomp[5][9][5] = make_pair(10000,100000000);
precomp[6][1][1] = make_pair(100000,1);
precomp[6][2][1] = make_pair(100000,11);
precomp[6][2][2] = make_pair(100000,10);
precomp[6][3][1] = make_pair(100000,101);
precomp[6][3][2] = make_pair(100000,110);
precomp[6][3][3] = make_pair(100000,100);
precomp[6][4][1] = make_pair(100000,1001);
precomp[6][4][2] = make_pair(100000,1008);
precomp[6][4][3] = make_pair(100000,1100);
precomp[6][4][4] = make_pair(100000,1000);
precomp[6][5][1] = make_pair(100000,10001);
precomp[6][5][2] = make_pair(100000,10010);
precomp[6][5][3] = make_pair(100000,10080);
precomp[6][5][4] = make_pair(100000,11000);
precomp[6][5][5] = make_pair(100000,10000);
precomp[6][6][1] = make_pair(100000,100001);
precomp[6][6][2] = make_pair(100000,100010);
precomp[6][6][3] = make_pair(100000,100100);
precomp[6][6][4] = make_pair(100000,101000);
precomp[6][6][5] = make_pair(100000,110000);
precomp[6][6][6] = make_pair(100000,100000);
precomp[6][7][1] = make_pair(100000,1000001);
precomp[6][7][2] = make_pair(100000,1000010);
precomp[6][7][3] = make_pair(100000,1000100);
precomp[6][7][4] = make_pair(100000,1001000);
precomp[6][7][5] = make_pair(100000,1010000);
precomp[6][7][6] = make_pair(100000,1000000);
precomp[6][8][1] = make_pair(100000,10000001);
precomp[6][8][2] = make_pair(100000,10000010);
precomp[6][8][3] = make_pair(100000,10000100);
precomp[6][8][4] = make_pair(100000,10001000);
precomp[6][8][5] = make_pair(100000,10010000);
precomp[6][8][6] = make_pair(100000,10000000);
precomp[6][9][1] = make_pair(100000,100000001);
precomp[6][9][2] = make_pair(100000,100000010);
precomp[6][9][3] = make_pair(100000,100000100);
precomp[6][9][4] = make_pair(100000,100001000);
precomp[6][9][5] = make_pair(100000,100010000);
precomp[6][9][6] = make_pair(100000,100000000);
precomp[7][1][1] = make_pair(1000000,1);
precomp[7][2][1] = make_pair(1000000,11);
precomp[7][2][2] = make_pair(1000000,10);
precomp[7][3][1] = make_pair(1000000,101);
precomp[7][3][2] = make_pair(1000000,110);
precomp[7][3][3] = make_pair(1000000,100);
precomp[7][4][1] = make_pair(1000000,1001);
precomp[7][4][2] = make_pair(1000000,1008);
precomp[7][4][3] = make_pair(1000000,1100);
precomp[7][4][4] = make_pair(1000000,1000);
precomp[7][5][1] = make_pair(1000000,10001);
precomp[7][5][2] = make_pair(1000000,10010);
precomp[7][5][3] = make_pair(1000000,10080);
precomp[7][5][4] = make_pair(1000000,11000);
precomp[7][5][5] = make_pair(1000000,10000);
precomp[7][6][1] = make_pair(1000000,100001);
precomp[7][6][2] = make_pair(1000000,100010);
precomp[7][6][3] = make_pair(1000000,100100);
precomp[7][6][4] = make_pair(1000000,100800);
precomp[7][6][5] = make_pair(1000000,109375);
precomp[7][6][6] = make_pair(1000000,100000);
precomp[7][7][1] = make_pair(1000000,1000001);
precomp[7][7][2] = make_pair(1000000,1000010);
precomp[7][7][3] = make_pair(1000000,1000100);
precomp[7][7][4] = make_pair(1000000,1001000);
precomp[7][7][5] = make_pair(1000000,1010000);
precomp[7][7][6] = make_pair(1000000,1100000);
precomp[7][7][7] = make_pair(1000000,1000000);
precomp[7][8][1] = make_pair(1000000,10000001);
precomp[7][8][2] = make_pair(1000000,10000010);
precomp[7][8][3] = make_pair(1000000,10000100);
precomp[7][8][4] = make_pair(1000000,10001000);
precomp[7][8][5] = make_pair(1000000,10010000);
precomp[7][8][6] = make_pair(1000000,10100000);
precomp[7][8][7] = make_pair(1000000,10000000);
precomp[7][9][1] = make_pair(1000000,100000001);
precomp[7][9][2] = make_pair(1000000,100000010);
precomp[7][9][3] = make_pair(1000000,100000100);
precomp[7][9][4] = make_pair(1000000,100001000);
precomp[7][9][5] = make_pair(1000000,100010000);
precomp[7][9][6] = make_pair(1000000,100100000);
precomp[7][9][7] = make_pair(1000000,100000000);
precomp[8][1][1] = make_pair(10000000,1);
precomp[8][2][1] = make_pair(10000000,11);
precomp[8][2][2] = make_pair(10000000,10);
precomp[8][3][1] = make_pair(10000000,101);
precomp[8][3][2] = make_pair(10000000,110);
precomp[8][3][3] = make_pair(10000000,100);
precomp[8][4][1] = make_pair(10000000,1001);
precomp[8][4][2] = make_pair(10000000,1008);
precomp[8][4][3] = make_pair(10000000,1024);
precomp[8][4][4] = make_pair(10000000,1000);
precomp[8][5][1] = make_pair(10000000,10001);
precomp[8][5][2] = make_pair(10000000,10010);
precomp[8][5][3] = make_pair(10000000,10080);
precomp[8][5][4] = make_pair(10000000,11000);
precomp[8][5][5] = make_pair(10000000,10000);
precomp[8][6][1] = make_pair(10000000,100001);
precomp[8][6][2] = make_pair(10000000,100010);
precomp[8][6][3] = make_pair(10000000,100096);
precomp[8][6][4] = make_pair(10000000,100800);
precomp[8][6][5] = make_pair(10000000,109375);
precomp[8][6][6] = make_pair(10000000,100000);
precomp[8][7][1] = make_pair(10000000,1000001);
precomp[8][7][2] = make_pair(10000000,1000010);
precomp[8][7][3] = make_pair(10000000,1000064);
precomp[8][7][4] = make_pair(10000000,1001000);
precomp[8][7][5] = make_pair(10000000,1008000);
precomp[8][7][6] = make_pair(10000000,1093750);
precomp[8][7][7] = make_pair(10000000,1000000);
precomp[8][8][1] = make_pair(10000000,10000001);
precomp[8][8][2] = make_pair(10000000,10000010);
precomp[8][8][3] = make_pair(10000000,10000100);
precomp[8][8][4] = make_pair(10000000,10001000);
precomp[8][8][5] = make_pair(10000000,10010000);
precomp[8][8][6] = make_pair(10000000,10100000);
precomp[8][8][7] = make_pair(10000000,11000000);
precomp[8][8][8] = make_pair(10000000,10000000);
precomp[8][9][1] = make_pair(10000000,100000001);
precomp[8][9][2] = make_pair(10000000,100000010);
precomp[8][9][3] = make_pair(10000000,100000100);
precomp[8][9][4] = make_pair(10000000,100001000);
precomp[8][9][5] = make_pair(10000000,100010000);
precomp[8][9][6] = make_pair(10000000,100100000);
precomp[8][9][7] = make_pair(10000000,101000000);
precomp[8][9][8] = make_pair(10000000,100000000);
precomp[9][1][1] = make_pair(100000000,1);
precomp[9][2][1] = make_pair(100000000,11);
precomp[9][2][2] = make_pair(100000000,10);
precomp[9][3][1] = make_pair(100000000,101);
precomp[9][3][2] = make_pair(100000000,110);
precomp[9][3][3] = make_pair(100000000,100);
precomp[9][4][1] = make_pair(100000000,1001);
precomp[9][4][2] = make_pair(100000000,1008);
precomp[9][4][3] = make_pair(100000000,1024);
precomp[9][4][4] = make_pair(100000000,1000);
precomp[9][5][1] = make_pair(100000000,10001);
precomp[9][5][2] = make_pair(100000000,10010);
precomp[9][5][3] = make_pair(100000000,10080);
precomp[9][5][4] = make_pair(100000000,10240);
precomp[9][5][5] = make_pair(100000000,10000);
precomp[9][6][1] = make_pair(100000000,100001);
precomp[9][6][2] = make_pair(100000000,100010);
precomp[9][6][3] = make_pair(100000000,100096);
precomp[9][6][4] = make_pair(100000000,100800);
precomp[9][6][5] = make_pair(100000000,109375);
precomp[9][6][6] = make_pair(100000000,100000);
precomp[9][7][1] = make_pair(100000000,1000001);
precomp[9][7][2] = make_pair(100000000,1000010);
precomp[9][7][3] = make_pair(100000000,1000064);
precomp[9][7][4] = make_pair(100000000,1000960);
precomp[9][7][5] = make_pair(100000000,1008000);
precomp[9][7][6] = make_pair(100000000,1093750);
precomp[9][7][7] = make_pair(100000000,1000000);
precomp[9][8][1] = make_pair(100000000,10000001);
precomp[9][8][2] = make_pair(100000000,10000010);
precomp[9][8][3] = make_pair(100000000,10000100);
precomp[9][8][4] = make_pair(100000000,10000640);
precomp[9][8][5] = make_pair(100000000,10010000);
precomp[9][8][6] = make_pair(100000000,10080000);
precomp[9][8][7] = make_pair(100000000,10937500);
precomp[9][8][8] = make_pair(100000000,10000000);
precomp[9][9][1] = make_pair(100000000,100000001);
precomp[9][9][2] = make_pair(100000000,100000010);
precomp[9][9][3] = make_pair(100000000,100000100);
precomp[9][9][4] = make_pair(100000000,100001000);
precomp[9][9][5] = make_pair(100000000,100010000);
precomp[9][9][6] = make_pair(100000000,100100000);
precomp[9][9][7] = make_pair(100000000,101000000);
precomp[9][9][8] = make_pair(100000000,110000000);
precomp[9][9][9] = make_pair(100000000,100000000);
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
