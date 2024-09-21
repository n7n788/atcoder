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
    Edge(int to = 0, int cost = 1): to(to), cost(cost) {}
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector edges(n, vector<Edge>());
    rep(i, 0, m) {
        int to, from, cost;
        cin >> from >> to >> cost;
        to--;
        from--;
        edges.at(from).emplace_back(to, cost);
    }

    // 全対最短路問題をワーシャル・フロイド法を使用して解く
    vector dp(n, vector<int>(n, INF));
    rep(i, 0, n) {
        dp.at(i).at(i) = 0;
        for (auto [to, cost]: edges.at(i)) {
            dp.at(i).at(to) = cost;
        }
    }
    rep(k, 0, n) {
        rep(i, 0, n) rep(j, 0, n) {
            if (dp.at(i).at(k) == INF || dp.at(k).at(j) == INF) continue;
            chmin(dp.at(i).at(j), dp.at(i).at(k) + dp.at(k).at(j));
        }
    }

    rep(i, 0, n) {
        rep(j, 0, n)  {
            int d = dp.at(i).at(j);
            if (d == INF) cout << "- ";
            else cout << dp.at(i).at(j) << " ";
        } cout << "\n";
    }    
    return 0;
}