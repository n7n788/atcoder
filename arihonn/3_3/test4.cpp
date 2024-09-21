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

const int ST_SIZE = (1 << 15) - 1;
const int MAX_N = 1e5, MAX_C = 1e5;
// 入力
int N, C;
int L[MAX_N];
int S[MAX_C], A[MAX_C];

// セグメント木のデータ
double vx[ST_SIZE], vy[ST_SIZE]; // 各節点のベクトル
double ang[ST_SIZE]; // 各節点の角度

// 角度の変化を調べるために、現在の角度を保存しておく
double prv[MAX_N];

// セグメント木を初期化する
// kは節点の番号、l, rはその節点が[l, r]に対応づいていることを表す
void init(int k, int l, int r) 
{
    ang[k] = vx[k] = 0.0;

    if (r - l == 1) {
        // 葉
        vy[k] = L[l];
    } else {
        // 葉ではない節点
        int chl = k * 2 + 1, chr = k * 2 + 2;
        init(chl, l, (l + r) / 2);
        init(chr, (l + r) / 2, r);
        vy[k] = vy[chl] + vy[chr];
    }
}

// 場所kの角度がaだけ変更になった
// vは節点の番号、l, rはその節点が[l, r)に対応づいていることを表す
void change(int k, double a, int v, int l, int r) 
{
    if (k <= l) return;
    else if (k < r) {
        int chl = v * 2 + 1, chr = v * 2 + 2;
        int m = (l + r) / 2;
        change(k, a, chl, l, m);
        change(k, a, chr, m, r);
        if (k <= m) ang[v] += a;

        double s = sin(ang[v]), c = cos(ang[v]);
        vx[v] = vx[chl] + (c * vx[chr] - s * vy[chr]);
        vy[v] = vy[chl] + (s * vx[chr] + c * vy[chr]);
    }
}

void solve()
{
    // 初期化
    init(0, 0, N);
    FOR(i, 1, N - 1) prv[i] = M_PI;

    // 各クエリを処理
    REP(i, C) {
        int s = S[i];
        double a = A[i] / 360.0 * 2 * M_PI; // ラジアンに変換

        change(s, a - prv[s], 0, 0, N);
        prv[s] = a;

        printf("%.2f %.2f\n", vx[0], vy[0]);
    }
}

int main()
{
    cin >> N >> C;
    REP(i, N) cin >> L[i];
    REP(i, C) cin >> S[i];
    REP(i, C) cin >> A[i];

    solve();
    return 0;
}