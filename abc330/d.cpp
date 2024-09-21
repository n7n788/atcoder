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
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, 0, n) cin >> s.at(i);
    vector<ll> sumr(n), sumc(n);
    rep(i, 0, n) {
        ll cnt = 0;
        rep(j, 0, n) if (s.at(i).at(j) == 'o') cnt++;
        sumr.at(i) = cnt;
    }
    rep(i, 0, n) {
        ll cnt = 0;
        rep(j, 0, n) if (s.at(j).at(i) == 'o') cnt++;
        sumc.at(i) = cnt;
    }
    ll ans = 0;
    rep(i, 0, n) rep(j, 0, n) {
        if (s.at(i).at(j) != 'o') continue;
        ans += (sumr.at(i) - 1) * (sumc.at(j) - 1);
    }
    cout << ans << "\n";
    return 0;
}