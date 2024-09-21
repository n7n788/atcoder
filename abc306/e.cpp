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
    int n, k, q;
    cin >> n >> k >> q;
    set<pair<ll, int>> big, small;
    rep(i, 0, n) {
        if (i < k) big.insert({0, i});
        else small.insert({0, i});
    } 
    ll res = 0;
    vector<ll> a(n, 0);
    rep(qi, 0, q) {
        int x;
        ll y;
        cin >> x >> y;
        x--;
        if (big.count({a.at(x), x})) {
            big.erase({a.at(x), x});
            big.insert({y, x});
            res -= a.at(x);
            res += y;
            a.at(x) = y;
        } else {
            small.erase({a.at(x), x});
            small.insert({y, x});
            a.at(x) = y;
        }

        if (small.size() >= 1) {
            pair<ll, int> minB = *big.begin();
            pair<ll, int> maxS = *small.rbegin();
            if (minB.first < maxS.first) {
                ll mB = minB.first; int mBi = minB.second;
                ll mS = maxS.first; int mSi = maxS.second;
                big.erase({mB, mBi});  big.insert({mS, mSi});
                small.erase({mS, mSi});  small.insert({mB, mBi});
                res -= mB;
                res += mS;
            }
        }
        // pair<ll, int> minB = *big.begin();
        // pair<ll, int> maxS = *small.rbegin();
        // if (minB.first < maxS.first) {
        //     ll mB = minB.first; int mBi = minB.second;
        //     ll mS = maxS.first; int mSi = maxS.second;
        //     big.erase({mB, mBi});  big.insert({mS, mSi});
        //     small.erase({mS, mSi});  small.insert({mB, mBi});
        //     res -= mB;
        //     res += mS;
        // }

        // for(auto [y, x]: big) {
        //     cout << "(" << y << "," << x << ")" << ' ';
        // }
        // cout << '\n';
        // for(auto [y, x]: small) {
        //     cout << "(" << y << "," << x << ")" << ' ';
        // }
        // cout << '\n';

        cout << res << '\n';
    }
    return 0;
}