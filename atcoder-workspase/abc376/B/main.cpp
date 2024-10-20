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

bool exist(int secL, int secR, int x)
{
    int mn = min(secL, secR);
    int mx = max(secL, secR);
    return mn <= x && x <= mx;
}

int moveHandleCounter(int& current_pos, int target_pos, int disrupter_pos, int N)
{
    int len = abs(current_pos - target_pos);
    int res;
    if (exist(current_pos, target_pos, disrupter_pos)) {
        res = N - len;
    } else res = len;
    current_pos = target_pos;
    return res;
}

void solve(long long N, long long Q, std::vector<std::string> H, std::vector<long long> T)
{
    int cnt = 0;
    int l = 1, r = 2;
    REP(qi, Q) {
        int t = T.at(qi);
        string h = H.at(qi);
        if (h == "L") {
            cnt += moveHandleCounter(l, t, r, N);
        } else {
            cnt += moveHandleCounter(r, t, l, N);
        }
    }
    cout << cnt << endl;
    return;
}

// Generated by 2.14.0 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
int main()
{
        long long N;
    std::scanf("%lld", &N);
    long long Q;
    std::scanf("%lld", &Q);
    std::vector<std::string> H(Q);
    std::vector<long long> T(Q);
    for(int i = 0 ; i < Q ; i++){
        std::cin >> H[i];
        std::scanf("%lld", &T[i]);
    }
        solve(N, Q, std::move(H), std::move(T));
        return 0;
}
