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

ll c2(ll x) {
    return x * (x - 1) / 2;
}
int main()
{
    string s;
    cin >> s;
    ll n = (int) s.size();
    unordered_map<char, ll> mp;
    rep(i, 0, n) mp[s.at(i)]++;

    ll ans = c2(n);
    bool add = false;
    for (auto [key, val]: mp) {
        ans -= c2(val);
        if (val >= 2) add = true;
    }

    if (add) ans++;
    
    cout << ans << "\n";
    return 0;
}
