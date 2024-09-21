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
    Edge(int to = 0, ll cost = 0): to(to), cost(cost) {}
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector edges(n, vector<Edge>());
    rep(i, 0, m) {
        int from, to;
        ll cost;
        cin >> from >> to >> cost;
        from--;
        to--;
        edges.at(from).emplace_back(Edge{to, cost});
        edges.at(to).emplace_back(Edge{from, cost});
    }

    vector<ll> dist(n, INF), dist2(n, INF);
    auto dijkstra = [&](int s) {
        priority_queue<P, vector<P>, greater<P>> q;
        q.emplace(dist.at(s) = 0, 0);
        while (!q.empty()) {
            int from = q.top().second;
            int d = q.top().first;
            q.pop();
            cout << from << ", " << d << "\n";
            if (d > dist2.at(from)) continue;
            for (auto [to, cost]: edges.at(from)) {
                int nd = d + cost;
                if (nd < dist.at(to)) {
                    dist2.at(to) = dist.at(to);
                    q.emplace(dist.at(to) = nd, to);
                }
                if (nd > dist.at(to) && nd < dist2.at(to)) {
                    q.emplace(dist2.at(to) = nd, to);
                }
            }
        }
    };
    dijkstra(0);
    cout << dist2.at(n - 1) << "\n";
}