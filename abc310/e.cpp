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
    int n;
    string s;
    cin >> n >> s;

    vector dp(n, vector<ll>(2, INF_ll));

    if (s.at(0) == '0') {
        dp.at(0).at(0) = 1;
        dp.at(0).at(1) = 0;
    } else {
        dp.at(0).at(0) = 0;
        dp.at(0).at(1) = 1;
    }

    rep(i, 0, n - 1) {
        if (s.at(i + 1) == '0') {
            dp.at(i + 1).at(0) = 1;
            dp.at(i + 1).at(1) = dp.at(i).at(0) + dp.at(i).at(1);
        } else {
            dp.at(i + 1).at(0) = dp.at(i).at(1);
            dp.at(i + 1).at(1) = dp.at(i).at(0) + 1;
        }
    }

    // rep(j, 0, 2) {
    //     rep(i, 0, n) cout << dp.at(i).at(j) << ' ';
    //     cout << endl;
    // }
    ll res = 0;
    rep(i, 0, n) res += dp.at(i).at(1);
    cout << res << endl;
    return 0;
}