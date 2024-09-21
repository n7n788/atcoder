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
#include <stack>

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
    vector<ll> w(n), v(n);
    rep(i, 0, n) cin >> w.at(i);
    rep(i, 0, n) cin >> v.at(i);
    ll W;
    cin >> W;

    typedef pair<ll, ll> P;
    int n2 = n / 2;
    vector<P> ps(1 << n2); // 重さと価値のペア

    // 前半分を全列挙
    rep(i, 0, 1 << n2) {
        ll sw = 0, sv = 0;
        rep(j, 0, n2) {
            if (i >> j & 1) {
                sw += w.at(j);
                sv += v.at(j);
            }
        }
        ps.at(i) = make_pair(sw, sv);
    }
    
    for (auto [sw, sv]: ps) 
        printf("sw = %lld, sv = %lld\n", sw, sv);
    cout << endl;

    //　無駄な要素を取り除く
    // 値を一つずつ取り出し, ps[i-1].second > ps[i].second ならps[i]を除く
    sort(ps.begin(), ps.end());
    {
        int k = 1;
        rep(i, 1, 1 << n2) {
            if (ps.at(k).second < ps.at(i).second)
                ps.at(k++) = ps.at(i);
        }
    }

    for (auto [sw, sv]: ps) 
        printf("sw = %lld, sv = %lld\n", sw, sv);
    cout << endl;

    // 後ろ半分を全列挙し解を求める
    ll res = 0;
    rep(i, 0, 1 << (n - n2)) {
        ll sw = 0, sv = 0;
        rep(j, 0, n - n2) {
            if (i >> j & 1) {
                sw += w.at(j + n2);
                sv += v.at(j + n2);
            }
        }
        printf("sw = %lld, sv = %lld\n", sw, sv);
        if (sw <= W) {
            ll tv = (lower_bound(ps.begin(), ps.end(), make_pair(W - sw, INF_ll)) - 1)->second;
            printf("tv = %lld\n", tv);
            chmax(res, sv + tv);
        }
    }
    cout << res << endl;
    return 0;
}