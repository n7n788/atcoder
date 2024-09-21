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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<P> edges;
    dsu uf(n); //　頂点の縮約のためにunion-find木を使用
    vector<vector<int>> to(n);
    vector<int> vs;
    vector<int> dp(n, -INF);
    rep(i, 0, n) cin >> a.at(i);
    // 同じ値かつ連結なら同じグループにマージして縮約
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (a.at(u) == a.at(v)) uf.merge(u, v);
        edges.emplace_back(u, v);
    }
    // DAGを構成
    for (auto [u, v]: edges) {
        u = uf.leader(u);
        v = uf.leader(v);
        if (u == v) continue;
        if (a.at(u) > a.at(v)) swap(u, v);
        to.at(u).push_back(v);
    }
    // トポロジカルソート順のインデックスを作成: 昇順なら < で降順なら >
    rep(i, 0, n) if (uf.leader(i) == i) vs.push_back(i);
    sort(vs.begin(), vs.end(), [&](int u, int v) {
        return a.at(u) < a.at(v);
    });
    // トポロジカルソート順にdp[i]の値を計算: 遷移で書く
    dp.at(uf.leader(0)) = 1;
    for (int v: vs) {
        for (int u: to.at(v)) {
            dp.at(u) = max(dp.at(u), dp.at(v) + 1);
        }
    }
    cout << max(dp.at(uf.leader(n - 1)), 0) << "\n";
    return 0;
}