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
    int h, w, m;
    cin >> h >> w >> m;
    vector<int> t(m), a(m), x(m);
    rep(i, 0, m) cin >> t.at(i) >> a.at(i) >> x.at(i);

    // vector<bool> row(h, false), col(w, false);
    unordered_set<int> row, col;
    map<int, ll> ans;
    for (int i = m - 1; i >= 0; i--) {
        if (t.at(i) == 1) {
            if (row.find(a.at(i)) == row.end()) {
                ans[x.at(i)] += (ll) w - col.size();
                row.insert(a.at(i));
            }
        } else {
            if (col.find(a.at(i)) == col.end()) {
                ans[x.at(i)] += (ll) h - row.size();
                col.insert(a.at(i));
            }
        }
        // for (auto [key, val]: ans) cout << key << ": " << val << "\n";
        // cout << endl;
    }

    ll sum = 0;
    for (auto [key, val]: ans) {
        if (key != 0) sum += val;
    }
    ans[0] = (ll) h * w - sum;
    int k = 0;
    for (auto [key, val]: ans) if (val != 0) k++;
    
    cout << k << "\n";
    for (auto [key, val]: ans) {
        if (val == 0) continue;
        cout << key << ' ' << val << "\n";
    }

    return 0;
}