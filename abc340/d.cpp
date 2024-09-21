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
#include <string>
#include <algorithm>
#include <cstdlib>

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
    struct Edge {
        int to;
        ll cost;
    };
    using Graph = vector<vector<Edge>>;
    int n;
    cin >> n;
    Graph graph(n);
    vector<ll> distances(n, INF_ll);
    rep(i, 0, n - 1) {
        ll a, b;
        int x;
        cin >> a >> b >> x;
        x--;
        // cout << graph.at(i).at(0).to << " ";
        graph.at(i).emplace_back(Edge{i + 1, a});
        graph.at(i).emplace_back(Edge{x, b});
    }

    // rep(i, 0, n - 1) {
    //     cout << "from = " << i << "\n";
    //     for (const auto& [to, cost]: graph.at(i)) {
    //         cout << "  to = " << to << ", cost = " << cost << "\n";
    //     }
    // }

    auto dijkstra = [&](const Graph& graph, vector<ll>& distances, const int startIndex) -> void {
        using Pair = pair<ll, int>;
        // priority_queueは昇順と降順を逆に指定する
        priority_queue<Pair, vector<Pair>, greater<Pair>> q;
        q.emplace(Pair{(distances.at(startIndex) = 0), 0});
        while (!q.empty()) {
            const ll d = q.top().first;
            const int from = q.top().second;
            // cout << "from = " << from << ", d = " << d << "\n";
            q.pop();
            if (d > distances.at(from)) continue;
            for (const auto& [to, cost]: graph.at(from)) {
                ll nd = distances.at(from) + cost;
                if (nd < distances.at(to)) {
                    q.emplace(Pair{(distances.at(to) = nd), to});
                }
            }
        }
    };

    dijkstra(graph, distances, 0);
    cout << distances.at(n - 1) << "\n";
}