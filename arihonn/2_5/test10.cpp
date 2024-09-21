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
    Edge(int from = 0, int to = 0, int cost = 1): from(from), to(to), cost(cost) {}
};

bool compare(Edge a, Edge b) {
    if (a.cost < b.cost) return true;
    else return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    rep(i, 0, m) {
        int from, to, cost;
        cin >> from >> to >> cost;
        from--;
        to--;
        edges.emplace_back(Edge{from, to, cost});
    }
    // 最小全域木問題をクラスカル法で求める
    dsu uf(n);
    vector<Edge> mst;
    sort(edges.begin(), edges.end(), compare);
    auto kruskal = [&]() -> int {
        int res = 0;
        for (auto [from, to, cost]: edges) {
            if (uf.same(from, to)) continue;
            uf.merge(from, to);
            res += cost;
            mst.emplace_back(Edge{from, to, cost});
            // cout << from << "-" << to << "\n";
        }
        return res;
    };

    int res = kruskal();
    cout << "mincost = " << res <<  "\n";
    for (auto [from, to, cost]: mst) {
        cout << from + 1 << " - " << to + 1 << ", cost = " << cost << "\n";
    }
    return 0;
}