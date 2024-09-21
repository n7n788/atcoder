//#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <atcoder/all>
#include <map>
#include <set>
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
    int n;
    cin >> n;
    vector edges(n, vector<int>());
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges.at(u).push_back(v);
        edges.at(v).push_back(u);
    }

    vector<bool> visited(n, false);
    vector<int> res;
    auto dfs = [&] (int v, int depth, auto dfs) -> void{
        // cout << v << endl;
        visited.at(v) = true;
        if (depth % 3 == 1) res.push_back(edges.at(v).size());
        for (auto u: edges.at(v)) {
            if (visited.at(u)) continue;
            dfs(u, depth + 1, dfs);
        }
    };

    rep(i, 0, n) {
        // cout << edges.at(i).size() << endl;
        if (edges.at(i).size() == 1) {
            // cout << "dfs:" << i << endl;
            dfs(i, 0, dfs);
            break;
        }
    }
    sort(res.begin(), res.end());
    rep(i, 0, (int) res.size()) cout << res.at(i) << ' ';
    cout << endl;
    return 0;
}