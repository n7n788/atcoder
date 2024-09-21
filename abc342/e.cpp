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
    struct Edge {
        int to;
        ll cost;
        ll l;
        ll d;
        ll k;
    };
    using Graph = vector<vector<Edge>>;
    int n, m;
    cin >> n >> m;
    Graph graph(n);
    vector<ll> times(n, 0);
    vector<ll> l(m), d(m), k(m), c(m), a(m), b(m);
    rep(i, 0, m) cin >> l.at(i) >> d.at(i) >> k.at(i) >> c.at(i) >> a.at(i) >> b.at(i);
    rep(i, 0, m) {
        a.at(i)--;
        b.at(i)--;
        graph.at(b.at(i)).emplace_back(Edge{(int) a.at(i), c.at(i), l.at(i), d.at(i), k.at(i)});
    }
    auto dijkstra = [&](const Graph& graph, vector<ll>& times, const int startIndex) -> void {
        using Pair = pair<ll, int>;
        // priority_queueは昇順と降順を逆に指定する
        priority_queue<Pair, vector<Pair>> q;
        q.emplace(Pair{(times.at(startIndex) = INF_ll), startIndex});
        while (!q.empty()) {
            const ll t = q.top().first;
            const int from = q.top().second;
            // cout << from << ", " << t << "\n";
            q.pop();
            if (t < times.at(from)) continue;
            for (const auto& e: graph.at(from)) {
                ll to = e.to;
                ll cost = e.cost;
                ll l = e.l;
                ll d = e.d;
                ll k = e.k;
                ll rt = times.at(from) - cost;
                ll cnt = min((rt - l) / d, k - 1);
                ll startTime = l + cnt * d;
                // cout << "  " << to << " start = " << startTime << "\n";
                if (startTime > times.at(to)) {
                    q.emplace(Pair{(times.at(to) = startTime), to});
                }
            }
        }
    };
    dijkstra(graph, times, n - 1);
    rep(i, 0, n - 1) {
        if (times.at(i) == 0) cout << "Unreachable" << "\n";
        else cout << times.at(i) << "\n";
    }
    return 0;
}
