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

struct Edge {
    int from;
    int to;
    ll cost;
    Edge(int from = 0, int to = 0, ll cost = 0): from(from), to(to), cost(cost) {}
};

bool compare(Edge a, Edge b) {
    return a.cost > b.cost;
}
int main()
{
    int n, m, r;
    cin >> n >> m >> r;
    vector<Edge> edges;
    rep(i, 0, r) {
        int from, to;
        ll cost;
        cin >> from >> to >> cost;
        // from--;
        // to--;
        to += n;
        edges.emplace_back(from, to, cost);
    }

    dsu uf(n + m);
    ll res = 0;
    sort(edges.begin(), edges.end(), compare);
    for (auto [from, to, cost]: edges) {
        if (uf.same(from, to)) continue;
        uf.merge(from, to);
        res += cost;
    }
    res = 10000 * (n + m) - res;
    cout << res << "\n";
}