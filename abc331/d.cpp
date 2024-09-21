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
    int n, q;
    cin >> n >> q;
    vector<string> p(n);
    vector s(n + 1, vector<ll>(n + 1, 0));
    rep(i, 0, n) cin >> p.at(i);
    rep(i, 0, n) rep(j, 0, n) {
        s.at(i + 1).at(j + 1) = s.at(i + 1).at(j);
        if (p.at(i).at(j) == 'B') s.at(i + 1).at(j + 1)++;
    }
    // rep(i, 0, n + 1) {
    //     rep(j, 0, n + 1) {
    //         cout << s.at(i).at(j) << " ";
    //     }
    //     cout << "\n";
    // }
    rep(j, 0, n) rep(i, 0, n) {
        s.at(i + 1).at(j + 1) += s.at(i).at(j + 1);
    }
    // rep(i, 0, n + 1) {
    //     rep(j, 0, n + 1) {
    //         cout << s.at(i).at(j) << " ";
    //     }
    //     cout << "\n";
    // }
    // (0, 0) から (i, j)の長方形内の個数を求める
    auto get = [&] (int i, int j) -> ll {
        ll ans = 0;
        ans += s.at(i % n + 1).at(j % n + 1);
        ans += s.at(n).at(n) * (i / n) * (j / n);
        ans += s.at(n).at(j % n + 1) * (i / n);
        ans += s.at(i % n + 1).at(n) * (j / n);
        return ans;
    };
    // cout << get(n - 1, n - 1) << "\n";
    rep(qi, 0, q) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ll ans = get(c, d) - get(c, b - 1) - get(a - 1, d) + get(a - 1, b - 1);
        cout << ans << "\n";
    }
    return 0;
}