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

// void solve(long long N, std::string S, std::vector<long long> C){
//     REP(i, N) if (i % 2 == 1) S.at(i) = (S.at(i) == '1' ? '0' : '1');
//     // cout << S << endl;
//     auto f = [&](string t) -> ll {
//         ll ans;
//         ll sum = 0;
//         REP(i, N) if (S.at(i) != t.at(i)) sum += C.at(i);
//         // cout << t << ": " << sum << "\n";
//         ans = sum;
//         FOR (i, 1, N - 2) {
//             t.at(i) = (t.at(i) == '1' ? '0' : '1');
//             if (t.at(i) == S.at(i)) sum -= C.at(i);
//             else sum += C.at(i);
//             // cout << t << ": " << sum << "\n";
//             chmin(ans, sum);
//         }
//         return ans;
//     };

//     string t0 = "0", t1 = "1";
//     REP(i, N - 1) t0 += "1", t1 += "0";
//     ll ans = min(f(t0), f(t1));
//     cout << ans << endl;
//     return;
// }

void solve(long long N, std::string S, std::vector<long long> C){
    REP(i, N) if (i % 2 == 1) S.at(i) = (S.at(i) == '1' ? '0' : '1');

    vl z(N), o(N), zs(N + 1, 0), os(N + 1, 0);
    REP(i, N) if (S.at(i) == '0') z.at(i) += C.at(i);
    REP(i, N) if (S.at(i) == '1') o.at(i) += C.at(i);
    REP(i, N) zs.at(i + 1) = zs.at(i) + z.at(i);
    REP(i, N) os.at(i + 1) = os.at(i) + o.at(i);

    // 累積和配列sumから、右開区間[l, r)で指定した区間和を返す
    auto getSec = [&] (const vl& sum, int l, int r) -> ll {
        return sum.at(r) - sum.at(l);
    };

    ll ans = INF_ll;
    FOR(i, 1, N - 1) {
        ll sum = getSec(zs, 0, i) + getSec(os, i, N);
        chmin(ans, sum);
    }
    FOR(i, 1, N - 1) {
        ll sum = getSec(os, 0, i) + getSec(zs, i, N);
        chmin(ans, sum);
    }
    cout << ans << endl;
    return;
}

// Generated by 2.13.0 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
int main(){
        long long N;
    std::scanf("%lld", &N);
    std::string S;
    std::cin >> S;
    std::vector<long long> C(N);
    for(int i = 0 ; i < N ; i++){
        std::scanf("%lld", &C[i]);
    }
        solve(N, S, std::move(C));
        return 0;
}
