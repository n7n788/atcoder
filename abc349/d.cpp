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
#define INF 1001001001
#define INF_ll 1001001001001001001ll
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

int getMxDiv(ll x) {
  if (x == 0) return 60;
  int cnt = 0;
  while (x % 2 == 0) {
    x /= 2;
    cnt++;
  }
  return cnt;
}

int getRemEx(ll x) {
  int cnt = 0;
  ll y = 1;
  while (x >= y) {
    y *= 2;
    cnt++;
  }
  return cnt - 1;
}

int main()
{
  ll l, r;
  cin >> l >> r;
  vector<ll> resL, resR;
  ll x = l;
  while (x < r) {
    resL.push_back(x);
    int mxdiv = getMxDiv(x);
    ll rem = r - x;
    int rem_ex = getRemEx(rem);
    int w = min(mxdiv, rem_ex);
    x += 1ll << w;
    resR.push_back(x);
  }

  int m = resL.size();
  cout << m << "\n";
  REP(i, m) cout << resL.at(i) << " " << resR.at(i) << "\n";
  return 0;
}