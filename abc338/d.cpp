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
    int n, m;
    cin >> n >> m;
    vector<int> x(m);
    fenwick_tree<ll> d(n + 1);
    ll res = INF_ll;
    auto add = [&](int l, int r, ll x) -> void {
        d.add(l, x);
        d.add(r, -x);
    };
    rep(i, 0, m) {
        cin >> x.at(i);
        x.at(i)--;
    }
    rep(i, 0, m - 1) {
        // rep(i, 0, n) {
        //     cout << d.sum(0, i + 1) << " ";
        // }
        // cout << "\n";
        int l = min(x.at(i), x.at(i + 1));
        int r = max(x.at(i), x.at(i + 1));
        add(l, r, n - r + l);
        add(0, l, r - l);
        add(r, n, r - l);
    }
    // rep(i, 0, n) {
    //         cout << d.sum(0, i + 1) << " ";
    //     }
    // cout << "\n";
    rep(i, 0, n) {
        chmin(res, d.sum(0, i + 1));
    }
    cout << res << "\n";
    return 0;
}