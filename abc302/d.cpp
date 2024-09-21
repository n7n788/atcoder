//#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <atcoder/all>
#include <map>
#include <set>

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
    ll D;
    cin >> n >> m >> D;
    vector<ll> A(n), B(m);
    rep(i, 0, n) cin >> A.at(i);
    rep(i, 0, m) cin >> B.at(i);

    sort(B.begin(), B.end());
    ll max = -INF_ll;
    for (ll a: A) {
        int j= upper_bound(B.begin(), B.end(), a + D) - B.begin();
        if (j == 0) continue; // a + D以下の値が見つからなかった。
        ll b = B[j - 1];
        if (b >= a - D) chmax(max, a + b);
    }

    if (max == -INF_ll) cout << -1 << endl;
    else cout << max << endl;
}