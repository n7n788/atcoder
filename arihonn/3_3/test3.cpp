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

// セグメント木を使用して区間の最小値を返すRMQ (Range Minimum Query) を実装
const int MAX_N = 1 << 17;

// セグメント木を持つグローバル配列
int n, dat[2 * MAX_N - 1];

// 初期化
void init(int n_)
{
    // 簡単のため、要素数を2のべき乗に
    n = 1;
    while (n < n_) n *= 2;

    // 全ての値をINT_MAXに
    REP(i, 2 * n - 1) dat[i] = INT_MAX;
}

// k番目の値(0-indexed)をaに変更
void update(int k, int a) 
{
    // 葉の節点
    k += n - 1;
    dat[k] = a;
    // 登りながら更新
    while (k > 0) {
        k = (k - 1) / 2;
        dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
}

// [a, b)の最小値を求める
// 後ろの方の引数は, 計算の簡単のための引数
// kは節点の番号, l, rはその節点が[l, r)に対応づいていることを表す
// したがって、外からはquery(a, b, 0, 0, n)として呼び出す
int query(int a, int b, int k, int l, int r)
{
    // [a, b)と[l, r)が交差しなければ, INT_MAX
    if (r <= a || b <= l) return INT_MAX;

    // [a, b) が[l, r)を完全に含んでいれば, この接点の値
    if (a <= l && r <= b) return dat[k];
    else {
        // そうでなければ、2つの子の最小値
        int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
}

// [a, b)の最小値を求める
// 外から呼び出す関数
int query(int a, int b)
{
    return query(a, b, 0, 0, n);
}

int main()
{
    int q;
    cin >> n >> q;
    REP(i, n) {
        int x;
        cin >> x;
        update(i, x);
    }

    REP(qi, q) {
        int type;
        cin >> type;
        if (type == 1) {
            int p, x;
            cin >> p >> x;
            update(p, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(l, r) << endl;
        }
    }
    
    return 0;
}