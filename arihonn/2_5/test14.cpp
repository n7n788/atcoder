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

struct Edge {
    int from;
    int to;
    ll cost;
    Edge(int from = 0, int to = 0, ll cost = 0): 
        from(from), to(to), cost(cost) {}
};

int main()
{
    int n, l, d;
    cin >> n >> l >> d;
    vector<Edge> edges;
    rep(i, 0, l) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        edges.emplace_back(a, b, c);
    }
    rep(i, 0, d) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        edges.emplace_back(b, a, -c);
    }
    rep(i, 0, n - 1) {
        edges.emplace_back(i + 1, i, 0);
    }
    vector<ll> distances(n, INF);
    auto bellman_ford = [&](int s) {
        distances.at(s) = 0;
        bool updated;
        rep(i, 0, n) {
            updated = false;
            for (auto [from, to, cost]: edges) {
                if (distances.at(from) == INF) continue;
                if (distances.at(from) + cost < distances.at(to)) {
                    distances.at(to) = distances.at(from) + cost;
                    updated = true;
                }
            }
        }
        return updated;
    };

    bool updated = bellman_ford(0);
    ll res = distances.at(n - 1);
    // 負閉路が検出できた場合, d(n-1)は無限に小さくなる. しかし, d(0) = 0なので、制約を満たさない。よって、制約を満たすdは存在しない
    if (updated) cout << -1 << "\n";
    // いくらでも離れることができる場合
    else if (res == INF) cout << -2 << "\n";
    else cout << res << "\n";
    return 0;
}
