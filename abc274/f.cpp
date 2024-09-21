// #include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <atcoder/all>
#include <set>
#include <map>
#include <atcoder/all>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using namespace atcoder;
using mint = modint998244353;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define erep(i, a, b) for (int i = (a); i <= (b); i++)
typedef pair<int, int> P;
template <typename T> bool chmin(T &a, const T& b) {if (a > b) {a = b; return true;} return false;}
template <typename T> bool chmax(T &a, const T& b) {if (a < b) {a = b; return true;} return false;}

typedef long long ll;
const int INF = 1 << 30;
const ll INF_ll = 1ll << 60;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> x(n + m + 1), y(n + m + 1);
    rep(i, 0, n + m) cin >> x.at(i) >> y.at(i);
    x.at(n + m) = 0;
    y.at(n + m) = 0;

    int n1 = n + m + 1; /*街 + 宝箱 + 原点*/
    int n2 = 1 << n1; /*部分集合を表すビット列*/
    vector<double> spd(n2, 1.0); /*状態ごとの速度を予め求める*/
    rep(s, 0, n2) {
        rep(i, 0, m) if ((s >> (n + i)) & 0x1) spd.at(s) *= 2.0;
    }

    auto dist = [&](int u, int v) -> double {
        double dx = (double) x.at(u) - x.at(v);
        double dy = (double) y.at(u) - y.at(v);
        return sqrt(dx * dx + dy * dy);
    };

    const double INF = 1e18;
    vector dp(n2, vector<double>(n1, INF));/*訪問状態がs, 今vにいる時の時間の合計*/
    dp.at(0).at(n1 - 1) = 0.0; /*全ての頂点が未訪問で、今原点にいる*/
    rep(s, 0, n2)rep(v, 0, n1) {
        if (dp.at(s).at(v) == INF) continue;
        rep(u, 0, n1) {
            if ((s >> u) & 0x1) continue;
            chmin(dp.at(s | (1 << u)).at(u), dp.at(s).at(v) + dist(u, v) / spd.at(s));
        }
    }

    // rep(s, 0, n2) {
    //     cout << s << ": ";
    //     rep(v, 0, n1) cout << dp.at(s).at(v) << ' ';
    //     cout << endl;
    // }

    // 
    int t = ((1 << n) - 1) | 1 << (n + m);
    double ans = INF;
    rep(s, 0, n2) {
        if ((s & t) == t) chmin(ans, dp.at(s).at(n1 - 1));
    }
    printf("%.6lf\n", ans);
    return 0;
}