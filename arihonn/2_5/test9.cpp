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
    int to;
    int cost;
    Edge(int to = 0, int cost = 0) : to(to), cost(cost) {}
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector edges(n, vector<Edge>());
    rep(i, 0, m) {
        int from, to, cost;
        cin >> from >> to >> cost;
        from--;
        to--;
        edges.at(from).emplace_back(Edge{to, cost});
        edges.at(to).emplace_back(Edge{from, cost});
    }
    // 最小全域木をプリム法で求める
    vector<int> mincost(n, INF); // ある頂点からの頂点iへの最小コスト
    vector<bool> used(n, false); // 頂点iを使用したか
    vector<int> parent(n, -1); // 最小全域木における頂点iへの直前の頂点
    auto compare = [&](P a, P b) -> bool {
        if (a.first > b.first) return true;
        else return false;
    };
    // 最小全域木を構成する辺と合計コストを求める
    auto prim = [&]() -> int {
        int res = 0;
        priority_queue<P, vector<P>, decltype(compare)> q(compare);
        q.emplace(P{mincost.at(0) = 0, 0});
        while (!q.empty()) {
            int from = q.top().second;
            cout << from << "\n";
            q.pop();
            if (used.at(from)) continue;
            used.at(from) = true;
            res += mincost.at(from);
            for (auto [to, cost]: edges.at(from)) {
                if (used.at(to)) continue;
                if (cost < mincost.at(to)) {
                    cout << to << ":" << cost << ", ";
                    q.emplace(P{mincost.at(to) = cost, to});
                    parent.at(to) = from;
                }
                cout << "\n";
            }
        }
        return res;
    };

    int res = prim();
    cout << "mincost = " << res << "\n";
    rep(i, 0, n) {
        if (parent.at(i) == -1) continue;
        cout << parent.at(i) + 1 << " - " << i + 1<< "\n";
    }
    return 0;
}