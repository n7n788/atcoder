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
    int n, m;
    cin >> n >> m;
    vector<int> b(m);
    fenwick_tree<ll> d(n+1);
    // 区間[l, r)にxを加算
    auto add = [&](int l, int r, ll x) -> void {
        d.add(l, x);
        d.add(r, -x);
    };
    rep(i, 0, n) {
        ll a;
        cin >> a;
        add(i, i + 1, a);
    }
    rep(i, 0, m) cin >> b.at(i);

    rep(i, 0, m) {
        ll x, p, q;
        x = d.sum(0, b.at(i) + 1); // [i]の値を取得
        add(b.at(i), b.at(i) + 1, -x); // [i]を0に更新
        p = x / n;
        q = x % n;
        add(0, n, p); // 全体にpを加算
        if (b.at(i) + q < n) {
            add(b.at(i) + 1, b.at(i) + q + 1, 1); // 一部だけ1を加算
        } else {
            add(b.at(i) + 1, n, 1);
            add(0, (b.at(i) + q + 1) % n, 1); // 一部だけ1を加算
        }
    }

    rep(i, 0, n) {
        cout << d.sum(0, i + 1) << " ";
    }
    cout << "\n";

    return 0;
}