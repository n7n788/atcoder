//#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <atcoder/all>
#include <map>
#include <set>
#include <unordered_set>

using namespace std;
using namespace atcoder;
using mint = modint998244353;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define erep(i, a, b) for (int i = (a); i <= (b); i++)
// typedef pair<int, int> P;
template <typename T> bool chmin(T &a, const T& b) {if (a > b) {a = b; return true;} return false;}
template <typename T> bool chmax(T &a, const T& b) {if (a < b) {a = b; return true;} return false;}

typedef long long ll;
const int INF = 1 << 30;
const ll INF_ll = 1ll << 60;

struct P {
    ll t, r;
    P(ll t = 0, ll r = 0): t(t), r(r) {}
    // tが小さい方を優先, tが同じならrが大きい方を優先
    bool operator<(const P& p) const {
        if (t != p.t) return t < p.t;
        return r > p.r;
    }
    // tが大きい方を優先, tが同じならrが小さい方を優先
    bool operator>(const P& p) const {
        if (t != p.t) return t > p.t;
        return r < p.r;
    }
    // 1回移動するためにcost必要で, 1回でearn稼げる手段がある時の, 最小操作回数とその時の余りを返す
    P add(ll cost, ll earn) {
        if (cost <= r) return P(t + 1, r - cost);
        cost -= r;
        ll num = (cost + earn - 1) / earn;
        return P(t + num + 1, num * earn - cost);
    }
};

P dp[80][80][80][80];

int main()
{
    int n;
    cin >> n;
    vector p(n, vector<ll>(n));
    vector r(n, vector<ll>(n));
    vector d(n, vector<ll>(n));
    rep(i, 0, n) rep(j, 0, n) cin >> p.at(i).at(j);
    rep(i, 0, n) rep(j, 0, n - 1) cin >> r.at(i).at(j);
    rep(i, 0, n - 1) rep(j, 0, n) cin >> d.at(i).at(j);

    auto senni = [&](int i, int j, int k, int l, int ni, int nj, ll cost) {
        if (ni < 0 || ni >= n || nj < 0 || nj >= n) return;
        P x = dp[i][j][k][l];
        int nk = k, nl = l;
        if (p.at(ni).at(nj) > p.at(k).at(l)) nk = ni, nl = nj;
        chmin(dp[ni][nj][nk][nl], x.add(cost, p.at(nk).at(nl)));
    };
    
    rep(i, 0, n) rep(j, 0, n) rep(k, 0, n) rep(l, 0, n) 
        dp[i][j][k][l] = P{INF_ll, 0};
    dp[0][0][0][0] = P{0, 0};


    rep(i, 0, n) rep(j, 0, n) rep(k, 0, n) rep(l, 0, n) {
        P x = dp[i][j][k][l];
        if (x.t == INF_ll) continue;
        cout << i << ", " << j << ", " << k << ", " << l << ": " << x.t << ", " << x.r << "\n";
        senni(i, j, k, l, i + 1, j, d.at(i).at(j));
        senni(i, j, k, l, i, j + 1, r.at(i).at(j));
    }

    ll ans = INF_ll;
    rep(k, 0, n) {
        rep(l, 0, n) {
            // cout << dp[n - 1][n - 1][k][l].t << " ";
            chmin(ans, dp[n - 1][n - 1][k][l].t);
        }
        // cout << "\n";
    }
    cout << ans << "\n";
    return 0;
}