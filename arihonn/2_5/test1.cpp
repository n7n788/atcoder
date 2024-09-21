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
    // 2部グラフの判定を実行
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
    
    vector<int> color(n, 0);
    // 頂点vを色cで塗ることが可能か判定
    auto dfs = [&](int v, int c, auto dfs) -> bool {
        cout << v + 1 << ": " << c << "\n";
        color.at(v) = c;
        bool flag = true;
        for (auto u: edges.at(v)) {
            cout << "  " << v + 1 << "->" << u + 1 << ":" << color.at(u) << "\n";
            if (color.at(u) == 0) flag &= dfs(u, -c, dfs);
            else if (color.at(u) == c) {
                flag = false;
                break;
            }
            // cout << "\n";
        }
        return flag;
    };
    bool ok = false;
    rep(i, 0, n) {
        if (color.at(i) == 0) ok &= dfs(i, 1, dfs);
    }
    if (ok) cout << "Yes" << "\n";
    else cout << "No" << "\n";
    return 0;    
}