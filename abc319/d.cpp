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
    int m, n;
    cin >> n >> m;
    vector<ll> l(n);
    rep(i, 0, n) cin >> l.at(i);

    // 横幅wで単語をM行以内に収めることが可能か
    auto ok = [&](ll w) -> bool {
        ll cols = l.at(0), rows = 1;
        if (cols > w) return false;

        rep(i, 1, n) {
            if (cols + 1 + l.at(i) <= w) cols += 1 + l.at(i);
            else {
                cols = l.at(i);
                rows++;
            }

            if (rows > m) return false;
        }
        return true;
    };

    ll ac = 0, ng = 0;
    rep(i, 0, n) {
        ac += l.at(i) + 1;
        chmax(ng, l.at(i));
    }
    ng--; ac--;

    while (ac - ng > 1) {
        ll mid = (ac + ng) / 2;
        if (ok(mid)) ac = mid;
        else ng = mid;
    }

    cout << ac << endl;
    return 0;
}