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
    int p, q;
    cin >> p >> q;
    vector<int> a(q + 2);
    a.at(0) = 0;
    rep(i, 0, q) cin >> a.at(i + 1);
    a.at(q + 1) = p + 1;
    vector dp(q + 1, vector<int>(q + 2, INF));

    // 初期化
    rep(i, 0, q + 1) dp.at(i).at(i + 1) = 0;

    //　幅の小さい順にdpを埋める
    for (int w = 2; w <= q + 1; w++) {
        for (int i = 0; i + w <= q + 1; i++) {
            int j = i + w;
            // cout << i << ", " << j << "\n";
            rep(k, i + 1, j) {
                chmin(dp.at(i).at(j), dp.at(i).at(k) + dp.at(k).at(j));
            }
            dp.at(i).at(j) += a.at(j) - a.at(i) - 2;
        }
    }

    cout << dp.at(0).at(q + 1) << "\n";
    return 0;
}