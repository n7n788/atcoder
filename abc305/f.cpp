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
    int n, m;
    cin >> n >> m;
    vector edge(n + 1, vector<int>());
    vector<bool> visited(n + 1, false);

    auto dfs = [&] (int v, int pv, auto dfs) -> void {
        if (v == n) {
            string ok;
            cin >> ok;
            exit(0);
        }
        int k;
        cin >> k;

        if (k == -1) exit(0);

        vector<int> ve(k);
        rep(i, 0, k) cin >> ve.at(i);

        // 未訪問なら辺を追加
        if (!visited.at(v)) {
            rep(i, 0, k) edge.at(v).push_back(ve.at(i));
        }
        visited.at(v) = true;

         // 未訪問の辺に移動
        for (auto u: edge.at(v)) {
            if (!visited.at(u)) {
                cout << u << '\n';
                dfs(u, v, dfs);
            }
        }

        // 未訪問の辺がなければ、来た方向へ戻る
        cout << pv << '\n';
        {
            int k;
            cin >> k;
            if (k == -1) exit(0);
            vector<int> ve(k);
            rep(i, 0, k) cin >> ve.at(i);
        }
    };

    dfs(1, -1, dfs);
}