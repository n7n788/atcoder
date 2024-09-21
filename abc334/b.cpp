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
    ll a, m, l, r;
    cin >> a >> m >> l >> r;
    ll ans, kl, kr, n;
    // nが非負の時の除算の切り上げと切り捨てを求める
    auto up = [&](ll n, ll m) {return (n + m - 1) / m;};
    auto down = [&](ll n, ll m) {return n / m;};
    n = l - a;
    if (n >= 0) kl = up(n, m);
    else kl = -down(-n, m);
    n = r - a;
    if (n >= 0) kr = down(n, m);
    else kr = -up(-n, m);
    ans = kr - kl + 1;
    // cout << kl << ", " << kr << "\n";
    cout << ans << "\n";
    return 0;
}