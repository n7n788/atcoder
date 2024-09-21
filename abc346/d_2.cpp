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
    string s;
    cin >> s;
    vector<ll> c(n);
    rep(i, 0, n) cin >> c.at(i);

    // 文字列sの奇数番目を反転
    rep(i, 0, n) 
        if (i % 2 == 1) s.at(i) ^= '1'^'0'; // 文字を反転

    ll ans = INF_ll;
    rep(bi, 0, 2)
    {
        vector<ll> l(n + 1, 0), r(n + 1, 0);
        rep(i, 0, n) {
            l.at(i + 1) = l.at(i);
            if (s.at(i) == '1') l.at(i + 1) += c.at(i);
        }
        for (int i = n - 1; i >= 0; i--) {
            r.at(i) += r.at(i + 1);
            if (s.at(i) == '0') r.at(i) += c.at(i);
        }
        rep(i, 0, n - 1) {
            chmin(ans, l.at(i + 1) + r.at(i + 1));
        }

        rep(i, 0, n) s.at(i) ^= '1'^'0';
    }

    cout << ans << endl;
    return 0;
}