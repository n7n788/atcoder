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

void solve(ll N, vl A, vl B, vl C) {
    vvl tree(N, vl());
    REP(i, N - 1) {
        A.at(i)--;
        B.at(i)--;
        tree.at(A.at(i)).push_back(B.at(i));
        tree.at(B.at(i)).push_back(A.at(i));
    }

    ll tot = 0;
    REP(i, N) tot += C.at(i);

    int x = -1;
    auto dfs = [&](auto dfs, int v, int p = -1) -> ll {
        ll res = C.at(v);
        bool isCentroid = true;
        for (auto ch: tree.at(v)) {
            if (ch == p) continue;
            ll now = dfs(dfs, ch, v);
            if (now > tot / 2) isCentroid = false;
            res += now;
        }
        if (tot - res > tot / 2) isCentroid = false;
        if (isCentroid) x = v;
        return res;
    };
    dfs(dfs, 0);

    auto dfs1 = [&](auto dfs1, int v, int p = -1, int d = 0) -> ll {
        ll res = C.at(v) * d;
        for (auto ch : tree.at(v)) {
            if (ch == p ) continue;
            res += dfs1(dfs1, ch, v, d + 1);
        }
        return res;
    };
    cout << dfs1(dfs1, x) << endl;

    return;
}
// void solve(ll N, vl A, vl B, vl C) {
//     vvl to(N, vl());
//     REP(i, N - 1) {
//         A.at(i)--;
//         B.at(i)--;
//         to.at(A.at(i)).push_back(B.at(i));
//         to.at(B.at(i)).push_back(A.at(i));
//     }

//     // 木の全体の重みの総和を計算
//     ll tot = 0;
//     REP(i, N) tot += C.at(i);

//     // 木の重心を求める
//     int x = -1;
//     // 今いる頂点vを根とした部分木の重みの総和をTree DPで求める
//     // v: 今いる頂点、p: 親の頂点
//     auto subFindCentroid = [&](auto f, int v, int p = -1) -> ll {
//         ll res = C.at(v); // 頂点vを根とする部分木の重さの総和
//         bool isCentroid = true; // 頂点vが重心か否か
//         for (auto ch: to.at(v)) {
//             if (ch == p) continue; 
//             ll now = f(f, ch, v); 
//             if (now > tot / 2) isCentroid = false; // 子の部分木のサイズをチェック
//             res += now;
//         }
//         if (tot - res > tot / 2) isCentroid = false; // 親側の部分木のサイズをチェック
//         if (isCentroid) x = v; 

//         return res;
//     };

//     subFindCentroid(subFindCentroid, 0);

//     // 重心から各頂点への距離を求め、重さの総和を計算
//     // 　　頂点vを根とする部分木の距離　x　重さの総和を返す
//     auto dfs = [&](auto dfs, int v, int p = -1, int d = 0) -> ll {
//         ll res = C.at(v) * d;
//         for (auto ch : to.at(v))  {
//             if (ch == p) continue;
//             res += dfs(dfs, ch, v, d + 1);
//         }
//         return res;
//     };

//     cout << dfs(dfs, x) << endl;
//     return;
// }

// 木の重心を求める
// void solve(long long N, std::vector<long long> A, std::vector<long long> B, std::vector<long long> C){
//     vvl to(N, vl());
//     REP(i, N - 1) {
//         A.at(i)--;
//         B.at(i)--;
//         to.at(A.at(i)).push_back(B.at(i));
//         to.at(B.at(i)).push_back(A.at(i));
//     }

//     // 全体の重みの総和を求める
//     ll tot = 0;
//     REP(i, N) tot += C.at(i);

//     // 木の重心を求める
//     int x = -1; // 求める重心の頂点
//     {
//         // ある頂点を根とした部分木の重みの総和を求める
//         // v: 今いる頂点、p: 親の頂点
//         auto dfs = [&](auto dfs, int v, int p=-1) -> ll {
//             ll res = C.at(v);
//             ll mx = 0;
//             for (int u: to.at(v)) {
//                 // 親方向は探索しない
//                 if (u != p) {
//                     ll now = dfs(dfs, u, v); // 子を根とした部分木の総和
//                     chmax(mx, now);
//                     res += now;
//                 }
//             }
//             // 自分を抜いた親方向の部分木の重みの総和: 全体 - (自分を根とした部分木の総和)
//             chmax(mx, tot - res); 
//             // 自分を抜いた部分木の重みの総和の最大値 <= 全体 / 2になったら、自分が重心
//             if (mx * 2 <= tot) x = v;
//             return res;
//         };

//         dfs(dfs, 0);
//     }
    
//     // 重心xから各頂点への距離を求め, 重み✖️積の総和を求める
//     auto dfs = [&](auto dfs, int v, int dist = 0, int p=-1) -> ll {
//         ll ans = (ll) dist * C.at(v);
//         for (int u: to.at(v)) {
//             if (u != p) {
//                 ans += dfs(dfs, u, dist + 1, v);
//             }
//         }
//         return ans;
//     };
//     cout << dfs(dfs, x) << endl;
//     return;
// }

// Generated by 2.13.0 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
int main(){
        long long N;
    std::scanf("%lld", &N);
    std::vector<long long> A(N-1);
    std::vector<long long> B(N-1);
    for(int i = 0 ; i < N-1 ; i++){
        std::scanf("%lld", &A[i]);
        std::scanf("%lld", &B[i]);
    }
    std::vector<long long> C(N);
    for(int i = 0 ; i < N ; i++){
        std::scanf("%lld", &C[i]);
    }
        solve(N, std::move(A), std::move(B), std::move(C));
        return 0;
}
