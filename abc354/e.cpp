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
    int n;
    cin >> n;
    vi a(n), b(n);
    REP(i, n) cin >> a.at(i) >> b.at(i);

    map<pair<ll, int>, int> mp;
    auto f = [&](auto f, int turn, ll used) -> bool {
        if (mp.count(pair{used, turn})) return mp[pair{used, turn}];

        bool fin = true;
        REP(i, n) {
            FOR(j, i + 1, n - 1) {
                if ((used >> i) & 1 || (used >> j) & 1) continue;
                if (a.at(i) == a.at(j) || b.at(i) == b.at(j)) {
                    fin = false;
                }
            }
        }

        if (fin) {
            return !turn;
        }

        bool win = false;
        REP(i, n) {
            FOR(j, i + 1, n - 1) {
                ll nused = used;
                if ((used >> i) & 1 || (used >> j) & 1) continue;
                if (a.at(i) == a.at(j) || b.at(i) == b.at(j)) {
                    nused |= (1ll << i);
                    nused |= (1ll << j);
                    win |= (f(f, !turn, nused) == turn);
                }
            }
        }

        if (win) return mp[pair{used, turn}] = turn;
        else return mp[pair{used, turn}] = !turn;
    };

    ll used = 0ll;
    if (f(f, 0, used) == 0) cout << "Takahashi\n";
    else cout << "Aoki\n";
    return 0;
}