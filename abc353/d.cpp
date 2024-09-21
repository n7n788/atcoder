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

ll getCrr(ll x)
{
    ll y = 1;
    while (x >= y) {
        y *= 10;
    }
    return y;
}

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    REP(i, n) cin >> a.at(i);

    mint ans = 0;
    mint sum = 0;
    vector<ll> cs(n, 0);

    FOR(i, 1, n - 1) {
        cs.at(i) = getCrr(a.at(i));
    }
    FOR(i, 1, n - 1) {
        sum += cs.at(i);
    }
    // REP(i, n) {
    //     printf("%lld\n", cs.at(i));
    // }
    REP(i, n) {
        sum -= cs.at(i);
        ans += (sum + i) * a.at(i);
    }

    cout << ans.val() << endl;
    return 0;
}