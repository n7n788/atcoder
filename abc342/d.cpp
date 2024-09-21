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

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}

ll c2(ll n) {
    return n * (n - 1) / 2;
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a.at(i);
    map<set<int>, ll> fmap;
    ll zcnt = 0, ans = 0;
    for (auto x: a) {
        if (x == 0) {
            zcnt++;
            continue;
        }
        set<int> st;
        vector<pair<ll, ll>> res;
        res = prime_factorize(x);
        for (auto [f, ex]: res) {
            if (ex % 2 == 1) st.insert(f);
        }
        fmap[st]++;
    }
    for (auto it = fmap.begin(); it != fmap.end(); it++) {
        ans += c2(it->second);
    }
    ans += c2(zcnt);
    ans += (n - zcnt) * zcnt;
    cout << ans << "\n";
    return 0;
}