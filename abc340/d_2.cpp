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
        Edge() {};
        Edge(int to, ll cost): to(to), cost(cost) {}
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
        graph.at(i).emplace_back(i + 1, a);
        graph.at(i).emplace_back(x, b);
    }

    auto djikstra = [&](const Graph& graph, vector<ll>& distances, int startIndex) -> void {
        using P = pair<ll, int>;
        priority_queue<P, vector<P>, greater<P>> q;
        q.emplace(distances.at(startIndex) = 0, startIndex);
        while (!q.empty()) {
            ll d;
            int from;
            d = q.top().first;
            from = q.top().second;
            q.pop();
            if (d > distances.at(from)) continue;
            for (auto [to, cost]: graph.at(from)) {
                ll nd = d + cost;
                if (nd < distances.at(to)) q.emplace(distances.at(to) = nd, to);
            }
        }
    };

    djikstra(graph, distances, 0);
    cout << distances.at(n - 1) << "\n";
}