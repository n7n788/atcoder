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
#include <stack>

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
    rep(i, 0, n) {
        int c;
        cin >> c;
        rep(j, 0, c) {
            int p;
            cin >> p;
            p--;
            edges.at(i).push_back(p);
        }
    }

    // トポロジカルソート：DFSの帰りがけ順を求める
    vector<bool> visited(n, false);
    auto dfs = [&](int v, auto dfs) -> void {
        visited.at(v) = true;
        for (auto u: edges.at(v)) {
            if (visited.at(u)) continue;
            dfs(u, dfs);
        }
        if (v != 0) cout << v + 1<< ' ';
    };

    dfs(0, dfs);
    cout <<  endl;

    return 0;
}