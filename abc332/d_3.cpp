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
    int h, w;
    cin >> h >> w;
    vector a(h, vector<int>(w));
    vector b(h, vector<int>(w));
    vector<int> p(h), q(w);
    int ans = INF;
    rep(i, 0, h) rep(j, 0, w) cin >> a.at(i).at(j);
    rep(i, 0, h) rep(j, 0, w) cin >> b.at(i).at(j);
    rep(i, 0, h) p.at(i) = i;
    rep(i, 0, w) q.at(i) = i;
    do {
        do {
            // rep(i, 0, h) cout << p.at(i) << " ";
            // cout << "\n";
            // rep(i, 0, w) cout << q.at(i) << " ";
            // cout << "\n";
            // ベクトルa, bが一致しているかを判定
            bool match = true;
            rep(i, 0, h) rep(j, 0, w) {
                // cout << a.at(p.at(i)).at(q.at(i)) << " " << b.at(i).at(j) << "\n";
                if (a.at(p.at(i)).at(q.at(j)) != b.at(i).at(j)) match = false;
            }
            if (!match) continue;

            // 数列p, qの転倒数を計算
            int pinv = 0, qinv = 0;
            rep(i, 0, h) rep(j, 0, h) if (i < j && p.at(i) > p.at(j)) pinv++;
            rep(i, 0, w) rep(j, 0, w) if (i < j && q.at(i) > q.at(j)) qinv++;
            chmin(ans, pinv + qinv);
        } while (next_permutation(q.begin(), q.end()));
    } while (next_permutation(p.begin(), p.end()));

    if (ans == INF) cout << -1 << "\n";
    else cout << ans << "\n";
    return 0;
}