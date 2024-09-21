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

// 結合則が成立する二項演算子 c = min(a, b);
int op(int a, int b) 
{
    return min(a, b);
}

// 単位元 a = e + aのeに相当するもの
// a = min(a, e)
int e() 
{
    return INT_MAX;
}

int main()
{
    int n, q;
    cin >> n >> q;
    segtree<int, op, e> seg(n);
    REP(i, n) {
        int v;
        cin >> v;
        // インデックスiの値をvに更新
        seg.set(i, v);
    }

    REP(qi, q) {
        int l, r;
        cin >> l >> r;
        // 区間[l, r]の最小値を求める
        cout << seg.prod(l, r + 1) << "\n";
    }

    return 0;
}