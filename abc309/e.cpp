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
    vector edge(n, vector<int>());
    rep(i, 1, n) {
        int p;
        cin >> p;
        p--;
        edge.at(p).push_back(i);
    }

    vector<int> res(n, -1);
    rep(i, 0, m) {
        int x, y;
        cin >> x >> y;
        x--;
        chmax(res.at(x), y);
    }
    auto dfs = [&](int v, int cnt, auto dfs) -> void{
        chmax(res.at(v), cnt);
        for(auto nv: edge.at(v)) {
            dfs(nv, res.at(v) - 1, dfs);
        }
    };

    dfs(0, -1, dfs);
    int ans = 0;
    rep(i, 0, n) {
        if (res.at(i) >= 0) ans++;
    }
    cout << ans << endl;
    return 0;
}