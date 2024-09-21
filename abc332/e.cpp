//#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include "atcoder/all"
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>

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
    int d, n;
    cin >> n >> d;
    vector<double> w(n);
    double avg = 0;
    int n2 = 1 << n;
    vector<double> x(n2, 0);
    const double INF = 1e18; // double型の最大値
    vector<double> dp(n2, INF); // 残りの集合がsである時の(和-平均)の２乗和の最小値
    double ans;
    // 平均を求める
    rep(i, 0, n) cin >> w.at(i);
    rep(i, 0, n) avg += w.at(i);
    avg /= d;
    // 部分集合の(和-平均)の２乗をを前計算
    rep(s, 0, n2) {
        rep(i, 0, n) if (s >> i & 1) x.at(s) += w.at(i);
        x.at(s) = (x.at(s) - avg) * (x.at(s) - avg);
    }
    // 3乗dp
    dp[n2 - 1] = 0; // 全て残っている状態を0で初期化
    rep(i, 0, d) {
        vector<double> old(n2, INF);
        swap(old, dp);
        rep(s, 0, n2) {
            // sの部分集合を求める
            for (int t = s;;t = (t - 1) & s) {
                // s^tによりsから部分集合tを除く
                chmin(dp[s ^ t], old[s] + x[t]);
                if (t == 0) break;
            }
        }
    }
    ans = dp[0] / d;
    printf("%.10f\n", ans);
    return 0;
}
