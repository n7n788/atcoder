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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, 0, n) cin >> a.at(i);
    unordered_map<int, int> mp;
    set<P> st;

    // 値valをcnt個増やす: mapとsetを更新
    auto update = [&](int val, int cnt) {
        st.erase({mp[val], val});
        mp[val] += cnt;
        st.insert({mp[val], val});
    };

    rep(i, 0, n) mp[a.at(i)]++;
    for (auto [key, val]: mp) {
        st.insert({val, key});
    }
    erep(i, 0, n) {
        if (mp.find(i) != mp.end()) continue;
        st.insert({0, i});
    }
    // for (auto [cnt, val]: st) {
    //     cout << cnt << ":" << val << ", ";
    // }
    // cout << "\n";

    rep(qi, 0, q) {
        int i, x;
        cin >> i >> x;
        i--;
        update(a.at(i), -1);
        a.at(i) = x;
        update(x, 1);
        // int ans;
        // int val = st.begin()->second;
        // int cnt = st.begin()->first;
        // if (cnt == 0) ans = val;
        // else if (val > 0) ans = 0;
        // else {

        // }
        cout << st.begin()->second << "\n";

        // for (auto [cnt, val]: st) {
        //     cout << cnt << ":" << val << ", ";
        // }
        // cout << "\n";
    }
    return 0;
}