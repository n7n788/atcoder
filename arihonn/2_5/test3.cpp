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

int main()
{
    int n, m;
    cin >> n >> m;
    vector edges(n, vector<int>());
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges.at(u).push_back(v);
        edges.at(v).push_back(u);
    }
    // 始点sから各頂点への最短路をBFSで求める
    vector<int> distances(n, INF);
    auto bfs = [&](int s) {
        queue<int> q;
        q.push(s);
        distances.at(s) = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto u: edges.at(v)) {
                if (distances.at(u) != INF) continue;
                q.push(u);
                distances.at(u) = distances.at(v) + 1;
            }
        }
    };

    bfs(0);
    rep(i, 0, n) {
        cout << distances.at(i) << "\n";
    }
    return 0;
}