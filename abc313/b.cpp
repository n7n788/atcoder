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
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges.at(a).push_back(b);
    }

    vector<bool> visited(n, false);
    auto dfs = [&](int v, auto dfs) -> void {
        // cout << v << ' ';
        visited.at(v) = true;
        for (auto u: edges.at(v)) {
            // cout << "go to: " << u << endl;
            if (visited.at(u) == false) dfs(u, dfs);
        }
    };

    rep(i, 0, n) {
        visited = vector<bool>(n, false);
        // cout << i << endl;
        dfs(i, dfs);
        bool ok = true;
        rep(j, 0, n) {
            if (visited.at(j) == false) {
                ok = false;
                break;
            }
        }
        if (ok) {
                cout << i + 1 << endl;
                return 0;
            }
        // cout << endl;
    }
    cout << -1 << endl;
    return 0;
}