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
#define INF 1001001001001001001ll
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
//     const int MAX_N = 1e6;
//     fenwick_tree<int> f(MAX_N);
//     int n;
//     cin >> n;
//     ll ans = 0;
//     REP(i, n) {
//         int a;
//         cin >> a;
//         ans += i - f.sum(0, a + 1);
//         f.add(a, 1);
//     }

//     cout << ans << endl;
//     return 0;
// }

// 実際にバブルソートを実行してカウント： O(n^2)
void solve0(vi a, int n)
{
    ll cnt = 0;
    REP(i, n - 1) {
        REV(j, n - 1, i + 1) {
              if (a.at(j - 1) > a.at(j)) {
                  swap(a.at(j - 1), a.at(j));
                  cnt++;
              }
        }
    }
    cout << "bubble sort = " << cnt << "\n";
}

// 転倒数を計算: O(n^2)
void solve1(vi a, int n)
{
    ll cnt = 0;
    REP(i, n) REP(j, n) {
        if (i < j && a.at(i) > a.at(j)) cnt++;
    }
    cout << "inversion number = " << cnt << "\n";
}

// BIT木を使用して平面走査： O(nlogn)
void solve2(vi a, int n)
{
    const int M = 1e6;
    fenwick_tree<ll> f(M);
    ll cnt = 0;
    REP(i, n) {
        cnt += f.sum(0, M) - f.sum(0, a.at(i));
        f.add(a.at(i), 1);
    }
    cout << "place scanning using BIT = " << cnt << "\n";
    return;
}

int main()
{
    int n;
    cin >> n;
    vi a(n);
    REP(i, n) cin >> a.at(i);

    // バブルソートの交換回数を求める
    solve0(a, n);
    solve1(a, n);
    solve2(a, n);
}