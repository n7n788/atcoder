#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cassert>
#include <iomanip>
#include <regex>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF_ll 1001001001001001001ll
#define INF 1001001001
#define fcout cout << fixed << setprecision(12)

using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<long long, long long>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;
using vvvi = vector<vector<vector<int>>>;
using pii = pair<int, int>;

template <typename T>
inline bool chmax(T &a, T b) {
    return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
    return ((a > b) ? (a = b, true) : (false));
}

int main()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    const ll off = 2e9;
    a += off;
    b += off;
    c += off;
    d += off;

    vvl m = {{0, 1, 2, 1},
             {1, 0, 1, 2}};
    
    auto f = [&](int x1, int x2, int y1, int y2) -> ll {
        assert(x1 >= 0);
        assert(x2 <= 4);
        assert(y1 >= 0);
        assert(y2 <= 2);

        ll ans = 0;
        FOR(x, x1, x2 - 1) FOR(y, y1, y2 - 1) {
            ans += m.at(y).at(x);
        }
        return ans;
    };

    ll k1 = (a - 2) / 4;
    if (4 * k1 + 2 <= a) k1++;

    ll k2 = (c - 2) / 4;
    // if (4 * k2 + 2 > c) k2--;

    ll l1 = b / 2;
    if (2 * l1 <= b) l1++;

    ll l2 = d / 2;
    // if (2 * l2 > d) l2--;

    ll al = (a + 2) % 4, au = 4;
    ll cl = 0, cu = (c - 2) % 4;
    ll bl = b % 2, bu = 2;
    ll dl = 0, du = d % 2;

    ll ans = 0;
    ans += (l2 - l1) * (k2 - k1) * 8;
    ans += (l2 - l1) * f(al, au, 0, 2);
    ans += (k2 - k1) * f(0, 4, bl, bu);
    ans += (l2 - l1) * f(cl, cu, 0, 2);
    ans += (k2 - k1) * f(0, 4, dl, du);
    ans += f(al, au, bl, bu);
    ans += f(al, au, dl, du);
    ans += f(cl, cu, bl, bu);
    ans += f(cl, cu, dl, du);

    cout << ans << endl;
    return 0;
}