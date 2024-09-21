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
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i, 0, h) cin >> s.at(i);
    vector<int> x(max(h, w) + 1, 0), d(max(h, w) + 1, 0);
    int ans = INF;

    rep(i, 0, h) {
        rep(j, 0, w) {
            x.at(j + 1) = x.at(j);
            d.at(j + 1) = d.at(j);
            if (s.at(i).at(j) == 'x') x.at(j + 1)++;
            if (s.at(i).at(j) == '.') d.at(j + 1)++;
        }
        rep(j, 0, w - k + 1) {
            int cntx = x.at(j + k) - x.at(j);
            int cntd = d.at(j + k) - d.at(j);
            if (cntx == 0) chmin(ans, cntd);
        }
    }

    rep(i, 0, w) {
        rep(j, 0, h) {
            x.at(j + 1) = x.at(j);
            d.at(j + 1) = d.at(j);
            if (s.at(j).at(i) == 'x') x.at(j + 1)++;
            if (s.at(j).at(i) == '.') d.at(j + 1)++;
        }
        rep(j, 0, h - k + 1) {
            int cntx = x.at(j + k) - x.at(j);
            int cntd = d.at(j + k) - d.at(j);
            if (cntx == 0) chmin(ans, cntd);
        }
    }

    if (ans == INF) cout << -1 << "\n";
    else cout << ans << "\n";
    return 0;
}