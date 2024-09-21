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

int main()
{
    int n;
    cin >> n;
    using P = pair<ll, ll>;
    vector<P> p(n);
    REP(i, n) cin >> p.at(i).first >> p.at(i).second;

    vector<P> p0, p1;
    REP(i, n) {
        ll x = p.at(i).first, y = p.at(i).second;
        if ((x + y) % 2 == 0) {
            p0.emplace_back((x + y) / 2, (-x + y) / 2);
        } else {
            x--;
            p1.emplace_back((x + y) / 2, (-x + y) / 2);
        }
    }

    vector<vl> v(4, vl());
    REP(i, p0.size()) {
        v.at(0).push_back(p0.at(i).first);
        v.at(1).push_back(p0.at(i).second);
    }
     REP(i, p1.size()) {
        v.at(2).push_back(p1.at(i).first);
        v.at(3).push_back(p1.at(i).second);
    }


    ll ans = 0;
    REP(i, 4) {
        sort(v.at(i).begin(), v.at(i).end());

        // for (auto e: v.at(i)) cout << e << " ";
        // cout << endl;

        int n = v.at(i).size();
        vector<ll> s(n + 1, 0);
        REV(j, n - 1, 1) {
            s.at(j) = s.at(j + 1) + v.at(i).at(j);
        }
        REP(j, n - 1) {
            // cout << j << ", " << s.at(j + 1) << "\n";
            ans += s.at(j + 1) - v.at(i).at(j) * (n - 1 - j);
        }

        // cout << ans << "\n";
    }
    cout << ans << endl;
    return 0;    
}