#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
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
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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

// int main()
// {
//     int n;
//     cin >> n;
//     vi a(n);
//     REP(i, n) cin >> a.at(i);
//     REP(i, n) a.at(i)--;

//     vector<pii> swaps;
//     for (int i = 0; i < n - 1;) {
//         if (a.at(i) == i) i++;
//         else {
//             swaps.emplace_back(i, a.at(i));
//             swap(a.at(i), a.at(a.at(i)));
//         }
//     }

//     cout << swaps.size() << endl;
//     for (auto [i, j]: swaps) {
//         cout << i + 1 << " " << j + 1 << "\n";
//     }
//     return 0;
// }


// int main()
// {
//     int n;
//     cin >> n;
//     vi a(n);
//     REP(i, n) cin >> a.at(i), a.at(i)--;

//     vi pos(n);
//     REP(i, n) pos.at(a.at(i)) = i;

//     vector<pii> ans;
//     REP(i, n - 1) {
//         if (pos.at(i) == i) continue;
//         int j = pos.at(i);
//         ans.emplace_back(i, j);
//         swap(a.at(i), a.at(j));
//         swap(pos.at(a.at(i)), pos.at(a.at(j)));
//     }

//     cout << ans.size() << endl;
//     for (auto [i, j]: ans) {
//         cout << i + 1 << " " << j + 1 << "\n";
//     }
//     return 0;
// }

void myswap(vi& a, int i, int j)
{
    swap(a.at(i), a.at(j));
    return;
}

// void solve(int n, vi a)
// {
//     REP(i, n) a.at(i)--;
//     int i = 0;
//     vpii swaps;
//     while (i < n) {
//         if (a.at(i) == i) i++;
//         else {
//             swaps.emplace_back(i, a.at(i));
//             myswap(a, i, a.at(i));
//         }
//     }
//     cout << swaps.size() << "\n";
//     for (auto [l, r]: swaps) {
//         cout << l + 1 << " " << r + 1 << "\n";
//     }
//     return;
// }

void solve(int n, vi a)
{
    REP(i, n) a.at(i)--;
    vpii swaps;
    vi p(n);
    REP(i, n) p.at(a.at(i)) = i;
    REP(i, n - 1) {
        if (a.at(i) == i) continue;
        int pi = p.at(i);
        swaps.emplace_back(i, pi);
        myswap(a, i, pi);
        myswap(p, a.at(i), a.at(pi));
    }
    cout << swaps.size() << "\n";
    for (auto [l, r]: swaps) {
        cout << l + 1 << " " << r + 1 << "\n";
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    vi a(n);
    REP(i, n) cin >> a.at(i);

    solve(n, std::move(a));
    return 0;
}