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
int op1(int a, int b) 
{
    return a + b;
}

// 単位元 a = e + aのeに相当するもの
// a = a + 0
int e1() 
{
    return 0;
}

typedef pair<double, double> P;
P op2(P a, P b) 
{
    return P{a.first + b.first, a.second + b.second};
}

P e2() 
{
    return P{0, 0};
}

int main()
{
    int n, c;
    cin >> n >> c;
    vector<int> l(n);
    REP(i, n) cin >> l.at(i);

    segtree<int, op1, e1> theta(n);
    segtree<P, op2, e2> v(n);
    REP(i, n) v.set(i, P{0.0, (double) l.at(i)});

    fcout;
    REP(ci, c) {
        int s, a;
        cin >> s >> a;

        theta.set(s, 180 - a);
        int r = theta.prod(0, s + 1);
        P nv;
        nv.first = l.at(s) * sin(M_PI * r / 180.0);
        nv.second = l.at(s) * cos(M_PI * r / 180.0);
        v.set(s, nv);

        cout << v.all_prod().first << " " << v.all_prod().second << "\n";
    }

    return 0;
}