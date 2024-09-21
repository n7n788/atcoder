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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    dsu uf(h * w);
    vector<P> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    mint ans, n, m;
    auto f = [&](int i, int j) -> int {
        return i * w + j;
    };
    rep(i, 0, h) cin >> s.at(i);
    rep(i, 0, h) rep(j, 0, w) {
        if (s.at(i).at(j) == '.') continue;
        for (auto [di, dj]: d) {
            int ni = i + di;
            int nj = j + dj;
            if (ni < 0 || ni >= h || nj < 0 || nj >= w || 
                s.at(ni).at(nj) == '.') continue;
            if (!uf.same(f(i, j), f(ni, nj)))
                uf.merge(f(i, j), f(ni, nj));
            // cout << "merge: " << f(i, j) << ", " << f(ni, nj) << "\n";
        }
    }
    for (auto g: uf.groups()) {
        // for (auto v: g) {
        //     cout << v << " ";
        // }
        // cout << "\n";
        int l = uf.leader(g.at(0));
        if (s.at(l / w).at(l % w) == '#') m++;
    }
    // cout << m.val() << "\n";
    ans = 0;
    n = 0;
    rep(i, 0, h)rep(j, 0, w) {
        unordered_set<ll> st;
        mint cnt;
        if (s.at(i).at(j) == '#') continue;
        // cout << "(i, j) = "<< i << ", " << j << "\n";
        for (auto [di, dj]: d) {
            int ni = i + di;
            int nj = j + dj;
            ll l;
            if (ni < 0 || ni >= h || nj < 0 || nj >= w || 
                s.at(ni).at(nj) == '.') continue;
            // cout << l << "\n";
            l = uf.leader(f(ni, nj));
            if (!st.count(l)) st.insert(l);
        }
        cnt = m - st.size() + 1;
        // cout << " cnt = " << cnt.val() << "\n";
        ans += cnt;
        n++;
    }
    // cout << n.val() << "\n";
    ans /= n;
    cout << ans.val() << "\n";
    return 0;
}