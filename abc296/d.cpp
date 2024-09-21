// #include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <atcoder/all>

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
    ll n, m;
    cin >> n >> m;

    ll res = INF_ll;
    for (ll a = (m + n - 1) / n; a <= (ll) ceil(sqrt(m)) && a <= n; a++) { 
        ll num = a * ((m + a - 1) / a);
        // cout << a << ", " << num << endl;
        chmin(res, a * ((m + a - 1) / a));
    }

    if (res == INF_ll) res = -1;
    cout << res << endl;
}
