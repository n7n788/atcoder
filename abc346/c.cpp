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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, 0, n) cin >> a.at(i);

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    // rep(i, 0, a.size()) cout << a.at(i) << " ";
    // cout << "\n";

    ll ans = (ll) k * (k + 1) / 2;
    rep(i, 0, a.size()) {
        if (a.at(i) <= k) ans -= a.at(i);
    }
    cout << ans << "\n";
    return 0;
}