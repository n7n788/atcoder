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

struct Edge {
    int from;
    int to;
    int cost;
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    rep(i, 0, m) {
        int u, v, cost;
        cin >> u >> v >> cost;
        u--;
        v--;
        edges.emplace_back(Edge{u, v, cost});
        // edges.emplace_back(Edge{v, u, cost});
    }

    // 頂点sからの各頂点への最短路をベルマンフォード法で解く
    vector<int> distances(n, INF);
    auto bellman_ford = [&](int s) {
        distances.at(s) = 0;
        while (true) {
            bool update = false;
            for (auto [from, to, cost]: edges) {
                if (distances.at(from) == INF) continue;
                if (distances.at(to) > distances.at(from) + cost) {
                    distances.at(to) = distances.at(from) + cost;
                    update = true;
                }
            }
            if (!update) break;
        }
    };
    bellman_ford(0);
    rep(i, 0, n) {
        cout << distances.at(i) << "\n";
    }
    return 0;
}