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
    vector a(n, vector<int>(m));
    rep(i, 0, n)rep(j, 0, m) cin >> a.at(i).at(j);

    vector<P> b;
    rep(i, 0, n)rep(j, 0, m)  b.emplace_back(a.at(i).at(j), i);
    sort(b.begin(), b.end());

    ll ans = ll ((m + 1) * m / 2) * ((n * (n - 1)) / 2);
    // 転倒数を求めるためにBIT木を使用
    fenwick_tree<int> t(n);
    for (auto [_, x]: b) {
        // x番目に1を追加
        t.add(x, 1);
        // すでに追加されているxより大きい値の個数を調べる＊
        ans += t.sum(x + 1, n);
    }
    cout << ans << endl;
    return 0;
}