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
using mint = modint998244353;

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

struct C
{
    int a;
    int c;
    int i;

    C() : a(0), c(0), i(0) {}
    C(int a, int c, int i): a(a), c(c), i(i) {}
};

int main()
{
    int n;
    cin >> n;
    vector<C> cs(n);
    REP(i, n) {
        cin >> cs.at(i).a >> cs.at(i).c;
        cs.at(i).i = i;
    }

    auto compare = [](C lc, C rc) -> bool {
        // 昇順
        return lc.c < rc.c;
    };

    sort(cs.begin(), cs.end(), compare);

    int max_a = 0;
    vi ans;
    REP(i, n) {
        if (max_a < cs.at(i).a) {
            ans.push_back(cs.at(i).i);
            max_a = cs.at(i).a;
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    REP(i, ans.size()) {
        cout << ans.at(i) + 1 << " ";
    }
    cout << endl;
    return 0;
}