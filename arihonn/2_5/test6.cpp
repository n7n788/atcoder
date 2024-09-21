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
    Edge(int to = 0, int cost = 0): to(to), cost(cost) {}
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

    // 負の辺がないグラフにおいて, 始点sから各頂点への最短経路をダイクストラ法で求める
    vector<int> distances(n, INF);
    auto dijkstra = [&](int s) {
        priority_queue<P, vector<P>, greater<P>> q;
        q.emplace(distances.at(s) = 0, s);
        while (!q.empty()) {
            int d = q.top().first;
            int from = q.top().second;
            q.pop();
            if (d > distances.at(from)) continue;
            for (auto [to, cost]: edges.at(from)) {
                int nd = d + cost;
                if (nd < distances.at(to)) {
                    q.emplace(distances.at(to) = nd, to);   
                }
            }
        }
    };
    dijkstra(0);
    rep(i, 0, n) {
        cout << distances.at(i) << "\n";
    }
    return 0;
}