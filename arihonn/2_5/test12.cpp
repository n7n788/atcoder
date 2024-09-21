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
    ll cost;
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

    vector<ll> dist1(n, INF), distN(n, INF);
    vector<int> parent1(n, -1), parentN(n, -1);
    auto dijkstra = [&](int s, vector<ll>& distances, vector<int>& parent) {
        priority_queue<P, vector<P>, greater<P>> q;
        q.emplace(distances.at(s) = 0, s);
        while (!q.empty()) {
            int from = q.top().second;
            int d = q.top().first;
            q.pop();
            if (d > distances.at(from)) continue;
            for (auto [to, cost]: edges.at(from)) {
                int nd = distances.at(from) + cost;
                if (nd < distances.at(to)) {
                    q.emplace(distances.at(to) = nd, to);
                    parent.at(to) = from;
                }
            } 
        }
    };

    dijkstra(0, dist1, parent1);
    dijkstra(n - 1, distN, parentN);

    ll mincost = INF;
    ll cost1toN = INF;
    ll ans = INF;
    ll mindist = dist1.at(n - 1);
    for (int v = n - 1; parent1.at(v) != -1; v = parent1.at(v)) {
        for (auto [to, cost]: edges.at(v)) {
            if (to == parent1.at(v)) chmin(mincost, cost);
            if (v == n - 1 && to == 0) cost1toN = cost;
        }
    }
    ans = cost1toN;
    rep(i, 0, n) {
        ll d = dist1.at(i) + distN.at(i);
        if (d == mindist) d += mincost * 2;
        chmin(ans, d);
    }
    cout << ans << "\n";
    return 0;
}