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

using state = vector<vector<int>>;
using key = std::pair<int, state>;

bool check(const state& s, int i) {

  int t;
  if (i % 2 == 0) t = 1;
  else t = -1;

  REP(i, 3) {
    int acnt = 0;
    REP(j, 3) {
      if (s.at(i).at(j) == t) acnt++;
    }
    if (acnt == 3) return true;
  }

  REP(j, 3) {
    int acnt = 0;
    REP(i, 3) {
      if (s.at(i).at(j) == t) acnt++;
    }
    if (acnt == 3) return true;
  }

  {
    int acnt = 0, ccnt = 0;
    REP(i, 3) {
      if (s.at(i).at(i) == t) acnt++;
    }
    if (acnt == 3) return true;
  }

  {
    int acnt = 0, ccnt = 0;
    REP(i, 3) {
      if (s.at(2 - i).at(i) == t) acnt++;
    }
    if (acnt == 3) return true;
  }
}

int main()
{
  vector a(3, vector<ll>(3));
  REP(i, 3) REP(j, 3) cin >> a.at(i).at(j);

  
  map<key, bool> mp;
  
  auto dfs = [&](auto dfs, int i, state s) -> bool {
    if (mp.find(pair{i, s}) != mp.end()) return mp[pair{i, s}];
    if (i == 9) {
      ll as = 0, bs = 0;
      REP(i, 3) REP(j, 3) {
        if (s.at(i).at(j) == 1) as += a.at(i).at(j);
        else if (s.at(i).at(j) == -1)  bs += a.at(i).at(j);
      }
      if (bs > as) return true;
      else return false;
    }

    bool ans = false;
    REP(i, 3) REP(j, 3) {
      state ns = s;
      if (s.at(i).at(j) == 0) {
        if (i % 2 == 0) ns.at(i).at(j) = 1;
        else ns.at(i).at(j) = -1;

        if (check(ns, i)) return true;
        else ans |= ~dfs(dfs, i + 1, ns);
      }
    }

    mp[pair{i, s}] = ans;
    return ans;
  };

  vector s(3, vector<int>(3, 0));
  if (dfs(dfs, 0, s)) cout << "Takahashi\n";
  else cout << "Aoki\n";

  return 0;
}
