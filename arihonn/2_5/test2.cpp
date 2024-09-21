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
    // 無向グラフが木かどうかを判定
    int n, m;
    cin >> n >> m;
    dsu uf(n);
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (!uf.same(u, v)) uf.merge(u, v);
    }
    
    if (uf.groups().size() == 1 && m == n - 1) cout << "Yes" << "\n";
    else cout << "No" << "\n";
}