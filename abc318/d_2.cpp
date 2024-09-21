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
    int n;
    cin >> n;
    vector d(n + 1, vector<ll>(n + 1));
    rep(i, 0, n - 1) rep(j, i + 1, n) {
        cin >> d.at(i).at(j);
        d.at(j).at(i) = d.at(i).at(j);
    }

    if (n%2 == 1) n++;

    // 全探索DFS: 重み付き完全グラフの最大マッチング問題
    ll ans = 0;
    vector<bool> used(n); // 頂点をマッチングしたかどうか
    // 頂点iのマッチング先を選ぶ.頂点iは小さい方から考える
    auto f = [&](auto f, int i, ll w) -> void {
        ans = max(ans, w);
        if (i == n) return;
        if (used.at(i)) {
            f(f, i + 1, w);
            return;
        }

        used.at(i) = true;
        for (int j = i + 1; j < n; j++) {
            if (used.at(j)) continue;
            used.at(j) = true;
            f(f, i + 1, w + d.at(i).at(j));
            used.at(j) = false;
        }
        used.at(i) = false;
    };

    f(f, 0, 0);
    cout << ans << endl;

    return 0;
}