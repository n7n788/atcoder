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
    vector<int> u(m), v(m);
    vector<int> w(n), a(n);
    // vector edgeB(n, vector<int>()); 
    vector edge(n, vector<int>());
    vector<int> vals(n, 0);
    vector<int> nodes(n);
    ll ans;
    rep(i, 0, m) {
        cin >> u.at(i) >> v.at(i);
        u.at(i)--;
        v.at(i)--;
    }
    rep(i, 0, n) cin >> w.at(i);
    rep(i, 0, n) cin >> a.at(i);
    rep(i, 0, m) {
        if (w.at(v.at(i)) > w.at(u.at(i))) 
            edge.at(v.at(i)).push_back(u.at(i));
        else if (w.at(u.at(i)) > w.at(v.at(i))) 
            edge.at(u.at(i)).push_back(v.at(i));
    }

    // wの小さい順に, 各頂点からの行き止まりへの最長パスの長さを求める
    rep(i, 0, n) nodes.at(i) = i;
    sort(nodes.begin(), nodes.end(), [&](int i, int j) {return w.at(i) < w.at(j);});
    for (int from : nodes) {
        // ナップザック問題を解く
        const int WMAX = 5000;
        vector dp(WMAX + 1, 0);
        for (int to : edge.at(from)) {
            // 重さを後ろから計算することで、1次元のdp配列を使い回すことが可能
            for (int j = w.at(from); j >= w.at(to); j--) {
                chmax(dp.at(j), dp.at(j - w.at(to)) + vals.at(to));
            }
        }
        vals.at(from) = dp.at(w.at(from) - 1) + 1;
    }
    ans = 0;
    rep(i, 0, n) {
        ans += (ll) vals.at(i) * a.at(i);
    }
    cout << ans << "\n";
    return 0;
}
