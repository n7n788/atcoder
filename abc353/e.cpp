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
    vs s(n);
    REP(i, n) cin >> s.at(i);

    sort(s.begin(), s.end());

    vi xs(n, 0);
    ll ans = 0;
    REP(i, n) {
        if (i != 0) {
            int j = 0;
            while (j < s.at(i).size() && j < s.at(i - 1).size() &&
            s.at(i).at(j) == s.at(i - 1).at(j)) j++;
            chmax(xs.at(i), j);
        }
        if (i != n - 1) {
            int j = 0;
            while (j < s.at(i).size() && j < s.at(i + 1).size() &&
                s.at(i).at(j) == s.at(i + 1).at(j)) j++;
            chmax(xs.at(i), j);
        }
    }

    REP(i, n) cout << xs.at(i) << "\n";
    
    vl y(n, 0);
    REP(i, n) {
        if (i == 0) {
            y.at(xs.at(0)) = 0;
            break;
        }
        if (xs.at(i) > xs.at(i - 1)) y.at(xs.at(i)) = i;
        else if (xs.at(i) < xs.at(i - 1)) ans += (i - y.at(xs.at(i))) * xs.at(i);
    }
    ans += (n - y.at(xs.at(n - 1)) + 1) * xs.at(n - 1);
    cout << ans << endl;
    return 0;
}